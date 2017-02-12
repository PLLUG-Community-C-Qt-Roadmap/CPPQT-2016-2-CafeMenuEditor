#ifndef EDITORDELEGATE_H
#define EDITORDELEGATE_H

#include <QWidget>
#include <QMessageBox>
#include "abstractvisitor.h"


namespace Ui {
class EditorDelegate;
}

class EditorDelegate : public QWidget, public AbstractVisitor
{
    Q_OBJECT

public:
    explicit EditorDelegate(QWidget *parent = 0);
    ~EditorDelegate();

    virtual void visit(MenuItem *) override;
    virtual void visit(Menu *) override;

    void clear();

public slots:
    bool slotSave();
    std::string getTempTitle();

signals:
    void itemChanged();

private:
    Ui::EditorDelegate *ui;

    std::string tempTitle;

    Menu *mEditedMenu;
    MenuItem *mEditedMenuItem;

};

#endif // EDITORDELEGATE_H
