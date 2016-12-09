#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

#include <memory>

namespace Ui {
class AddDialog;
}

class AbstractMenuItem;
class Menu;

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();

    void setMenu(AbstractMenuItem *);

protected:
    void showEvent(QShowEvent *);

private slots:
    void slotBackClicked();
    void slotCancelClicked();
    void slotNextClicked();
    void slotOkClicked();

    void slotChanged();
    void slotParentChanged();

private:
    void showPage1();
    void showPage2();

    void clear();

private:
    Ui::AddDialog *ui;
    AbstractMenuItem *mRoot;
    std::unique_ptr<AbstractMenuItem> mNewItem;
    Menu *mParent;
};

#endif // ADDDIALOG_H
