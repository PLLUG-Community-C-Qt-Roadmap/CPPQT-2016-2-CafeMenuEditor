#include "adddialog.h"
#include "ui_adddialog.h"

#include <menu.h>
#include <menuitem.h>
#include "lambdavisitor.h"

enum MenuItemType{MenuType = 0, MenuItemType};

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog),
    mRoot{nullptr},
    mParent{nullptr}
{
    ui->setupUi(this);
    setWindowTitle("Add...");

    ui->typeComboBox->addItem("Menu Item", MenuItemType);
    ui->typeComboBox->addItem("Menu", MenuType);

    connect(ui->backPushButton, SIGNAL(clicked(bool)), this, SLOT(slotBackClicked()), Qt::UniqueConnection);
    connect(ui->cancelPushButton_2, SIGNAL(clicked(bool)), this, SLOT(slotCancelClicked()), Qt::UniqueConnection);
    connect(ui->nextPushButton, SIGNAL(clicked(bool)), this, SLOT(slotNextClicked()), Qt::UniqueConnection);
    connect(ui->okPushButton, SIGNAL(clicked(bool)), this, SLOT(slotOkClicked()), Qt::UniqueConnection);
    connect(ui->widget, SIGNAL(itemChanged()), this, SLOT(slotChanged()), Qt::UniqueConnection);
    connect(ui->parentComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slotParentChanged()), Qt::UniqueConnection);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::setMenu(AbstractMenuItem *menu)
{
    mRoot = menu;
    ui->parentComboBox->setMenu(menu);
}

void AddDialog::showEvent(QShowEvent *)
{
    clear();

    showPage1();
}

void AddDialog::slotBackClicked()
{
    showPage1();

    clear();
}

void AddDialog::slotCancelClicked()
{
    ui->widget->clear();

    reject();
}

void AddDialog::slotNextClicked()
{
    switch (ui->typeComboBox->currentData().toInt())
    {
    case MenuType:
        mNewItem = std::make_unique<Menu>("");
        break;
    case MenuItemType:
        mNewItem = std::make_unique<MenuItem>("", 0.0);
        break;
    default:
        break;
    }

    if (mNewItem)
    {
        mNewItem->apply(ui->widget);
        showPage2();
    }
}

void AddDialog::slotOkClicked()
{
   if(ui->widget->slotSave())
     {
        if(ui->parentComboBox->checkDublicate(ui->widget->getTempTitle()))
           {
                mParent->append(std::move(mNewItem));
                accept();
           }
        else
           {
                QMessageBox msgBox;
                msgBox.setText("Menu item with the same name already exists.");
                msgBox.exec();
           }
     }
}

void AddDialog::slotChanged()
{
    ui->okPushButton->setEnabled(true);
}

void AddDialog::slotParentChanged()
{
    auto nextPushButton = this->ui->nextPushButton;

    auto menuItemHandler = [nextPushButton](MenuItem *item)
    {
        Q_UNUSED(item);
        nextPushButton->setEnabled(false);
    };

    auto menuHandler = [nextPushButton, this](Menu *item)
    {
        nextPushButton->setEnabled(true);
        this->mParent = item;
    };

    LambdaVisitor processParentVisitor;
    processParentVisitor.setMenuItemHandler(menuItemHandler);
    processParentVisitor.setMenuHandler(menuHandler);

    auto item = ui->parentComboBox->currentMenuItem();
    item->apply(&processParentVisitor);
}

void AddDialog::showPage1()
{
    ui->stackedWidget->setCurrentWidget(ui->addPage1);
    ui->backPushButton->setVisible(false);
    ui->nextPushButton->setVisible(true);
    ui->okPushButton->setVisible(false);
}

void AddDialog::showPage2()
{
    ui->stackedWidget->setCurrentWidget(ui->addPage2);
    ui->backPushButton->setVisible(true);
    ui->nextPushButton->setVisible(false);
    ui->okPushButton->setVisible(true);
    ui->okPushButton->setEnabled(true);
}

void AddDialog::clear()
{
    if (mNewItem)
    {
        mParent = nullptr;
        mNewItem.release();
        ui->widget->clear();
    }
}
