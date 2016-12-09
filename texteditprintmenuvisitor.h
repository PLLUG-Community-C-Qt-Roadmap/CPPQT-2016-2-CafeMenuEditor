#ifndef TEXTEDITPRINTMENUVISITOR_H
#define TEXTEDITPRINTMENUVISITOR_H

#include <abstractvisitor.h>

#include<QString>

class AbstractMenuItem;
class QPlainTextEdit;
/*!
 * \brief The ConsolePrintMenuVisitor class
 */
class TextEditPrintMenuVisitor : public AbstractVisitor
{
public:
    TextEditPrintMenuVisitor(QPlainTextEdit *textEdit);

    virtual void visit(MenuItem *item) override;
    virtual void visit(Menu *menu) override;

private:
    QPlainTextEdit *mTextEdit;
    QString indent(AbstractMenuItem *item) const;
};


#endif // TEXTEDITPRINTMENUVISITOR_H
