#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <utility>

#include <menu.h>
#include <menuitem.h>

#include "texteditprintmenuvisitor.h"
#include "menuiterator.h"
#include "adddialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800, 600);

    createMenu();
    slotUpdateMenu();

    connect(ui->menuComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(menuElementSelected()), Qt::UniqueConnection);
    connect(ui->action_Add, SIGNAL(triggered(bool)),
            this, SLOT(slotAddNewItem()), Qt::UniqueConnection);
    connect(ui->savePushButton, SIGNAL(clicked(bool)),
            this, SLOT(slotSaveEditedItem()), Qt::UniqueConnection);
    connect(ui->menuEditorDelegate, SIGNAL(itemChanged()),
            this, SLOT(slotItemChanged()), Qt::UniqueConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotPrintMenu()
{
    ui->menuTextEdit->clear();

    TextEditPrintMenuVisitor visitor(ui->menuTextEdit);

    MenuIterator iterator(mRoot.get());
    while(iterator.hasNext())
    {
        auto item =  iterator.next();
        item->apply(&visitor);
    }
}

void MainWindow::menuElementSelected()
{
    ui->savePushButton->setEnabled(false);

    AbstractMenuItem * item = ui->menuComboBox->currentMenuItem();

    AbstractVisitor *visitor = ui->menuEditorDelegate;
    item->apply(visitor);
}

void MainWindow::slotUpdateMenu()
{
    int index = ui->menuComboBox->currentIndex();

    ui->menuComboBox->setMenu(mRoot.get());

    slotPrintMenu();

    ui->menuComboBox->setCurrentIndex(index);
}

void MainWindow::slotAddNewItem()
{
    AddDialog addDialog;
    addDialog.setMenu(mRoot.get());

    if (QDialog::Accepted == addDialog.exec())
    {
        slotUpdateMenu();
    }
}

void MainWindow::slotItemChanged()
{
    ui->savePushButton->setEnabled(true);
}

void MainWindow::slotSaveEditedItem()
{
    ui->savePushButton->setEnabled(false);
    ui->menuEditorDelegate->slotSave();
    slotUpdateMenu();
}

void MainWindow::createMenu()
{
    auto root = std::make_unique<Menu>("MAIN MENU");

    auto pizzaMenu = std::make_unique<Menu>("Pizza Menu");
    pizzaMenu->append(std::make_unique<MenuItem>("hawaiian pizza", 2.4, "cheese and tomato base with toppings of ham and pineapple"));
    pizzaMenu->append(std::make_unique<MenuItem>("vegetarian pizza", 4.2, "cheese and tomato ... "));
    root->append(std::move(pizzaMenu));

    auto beveragesMenu = std::make_unique<Menu>("Beverages");
    beveragesMenu->append(std::make_unique<MenuItem>("Coca-Cola", 2));

    auto coffeMenu = std::make_unique<Menu>("Coffe");
    coffeMenu->append(std::make_unique<MenuItem>("Late", 1, "             "));
    coffeMenu->append(std::make_unique<MenuItem>("Capucino", 2, "             "));
    beveragesMenu->append(std::move(coffeMenu));

    beveragesMenu->append(std::make_unique<MenuItem>("Pepsi-Cola", 3));

    auto mineralWatersMenu = std::make_unique<Menu>("Mineral waters");
    mineralWatersMenu->append(std::make_unique<MenuItem>("Borjomi", 2.43, "   nice thing  "));
    mineralWatersMenu->append(std::make_unique<MenuItem>("Morshynska", 1.4, "         "));
    beveragesMenu->append(std::move(mineralWatersMenu));

    auto alcoDrinksMenu = std::make_unique<Menu>("Alco drinks");
    auto winesMenu = std::make_unique<Menu>("Wines");
    auto dryWines = std::make_unique<Menu>("Dry Wines");
    dryWines->append(std::make_unique<MenuItem>("Bordeaux", 20));
    winesMenu->append(std::move(dryWines));
    winesMenu->append(std::make_unique<MenuItem>("Champagne", 16.5));
    alcoDrinksMenu->append(std::move(winesMenu));
    alcoDrinksMenu->append(std::make_unique<MenuItem>("Beer", 5));
    beveragesMenu->append(std::move(alcoDrinksMenu));

    root->append(std::move(beveragesMenu));

    mRoot = std::move(root);
}
