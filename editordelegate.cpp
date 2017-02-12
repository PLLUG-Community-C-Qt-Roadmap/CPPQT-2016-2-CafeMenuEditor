#include "editordelegate.h"
#include "ui_editordelegate.h"

#include "menu.h"
#include "menuitem.h"
#include "menucombobox.h"

EditorDelegate::EditorDelegate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorDelegate)
{
    ui->setupUi(this);
    connect(ui->menuNameLineEdit, SIGNAL(textChanged(QString)), this, SIGNAL(itemChanged()), Qt::UniqueConnection);
    connect(ui->menuItemNameLineEdit, SIGNAL(textChanged(QString)), this, SIGNAL(itemChanged()), Qt::UniqueConnection);
    connect(ui->menuItemDescriptionLineEdit, SIGNAL(textChanged(QString)), this, SIGNAL(itemChanged()), Qt::UniqueConnection);
    connect(ui->menuItemPriceSpinBox, SIGNAL(valueChanged(double)), this, SIGNAL(itemChanged()), Qt::UniqueConnection);
    connect(ui->menuItemProposalChekBox, SIGNAL(stateChanged(int)), this, SIGNAL(itemChanged()), Qt::UniqueConnection);
}

EditorDelegate::~EditorDelegate()
{
    delete ui;
}

void EditorDelegate::visit(MenuItem *item)
{
    blockSignals(true);

    clear();

    ui->stackedWidget->setCurrentWidget(ui->pageMenuItem);
    ui->menuItemNameLineEdit->setText(item->title().c_str());
    ui->menuItemDescriptionLineEdit->setText(item->description().c_str());
    ui->menuItemPriceSpinBox->setValue(item->price());
    ui->menuItemProposalChekBox->stateChanged(item->neue());

    mEditedMenuItem = item;

    blockSignals(false);
}

void EditorDelegate::visit(Menu *menu)
{
    blockSignals(true);

    clear();

    ui->stackedWidget->setCurrentWidget(ui->pageMenu);
    ui->menuNameLineEdit->setText(menu->title().c_str());
    ui->menuCountLabel->setText(QString::number(menu->count()));

    mEditedMenu = menu;

    blockSignals(false);
}

void EditorDelegate::clear()
{
    mEditedMenu = nullptr;
    mEditedMenuItem = nullptr;
}



bool EditorDelegate::slotSave()
{
    if((ui->menuItemNameLineEdit->text().toStdString().empty() && ui->stackedWidget->currentWidget()==ui->pageMenuItem)
            ||
      (ui->menuNameLineEdit->text().toStdString().empty() && ui->stackedWidget->currentWidget()==ui->pageMenu))
    {
                QMessageBox msgBox;
                msgBox.setText("Please, enter name first.");
                msgBox.exec();
                return false;
    }
    else
    {
            if (mEditedMenuItem)
            {
                    mEditedMenuItem->setTitle(ui->menuItemNameLineEdit->text().toStdString());
                    mEditedMenuItem->setDescription(ui->menuItemDescriptionLineEdit->text().toStdString());
                    mEditedMenuItem->setPrice(ui->menuItemPriceSpinBox->value());
                    mEditedMenuItem->setNeue(ui->menuItemProposalChekBox->checkState());

                    tempTitle=ui->menuItemNameLineEdit->text().toStdString();

                    return true;
            }

            if (mEditedMenu)
            {
                   mEditedMenu->setTitle(ui->menuNameLineEdit->text().toStdString());

                   tempTitle=ui->menuNameLineEdit->text().toStdString();

                   return true;
            }

    }
}

std::__cxx11::string EditorDelegate::getTempTitle()
{
    return tempTitle;
}

