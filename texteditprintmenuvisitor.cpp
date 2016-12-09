#include "texteditprintmenuvisitor.h"

#include <QPlainTextEdit>

#include <menuitem.h>
#include <menu.h>
#include "lambdavisitor.h"

TextEditPrintMenuVisitor::TextEditPrintMenuVisitor(QPlainTextEdit *textEdit)
        : mTextEdit{textEdit}
{

}

/*!
 * \brief TextEditPrintMenuVisitor::indent
 * \param item
 * \return
 */
QString TextEditPrintMenuVisitor::indent(AbstractMenuItem *item) const
{
    QString rIndentString;

    return rIndentString;
}

/*!
 * \brief TextEditPrintMenuVisitor::visit
 * \param item
 */
void TextEditPrintMenuVisitor::visit(MenuItem *item)
{
    QString outString;

    QString lIndentString = indent(item);

    outString = QString("%1 > %2    %3$").arg(lIndentString).arg(item->title().c_str()).arg(item->price());
    mTextEdit->appendPlainText(outString);

    if (!item->description().empty())
    {
        QString description;
        description = QString("%1   ::::%2::::").arg(lIndentString).arg(item->description().c_str());
        mTextEdit->appendPlainText(description);
    }
}

/*!
 * \brief TextEditPrintMenuVisitor::visit
 * \param menu
 */
void TextEditPrintMenuVisitor::visit(Menu *menu)
{
    QString outString;
    QString lIndentString = indent(menu);
    outString = QString("%2[%1]").arg(menu->title().c_str()).arg(lIndentString);
    mTextEdit->appendPlainText(outString);
}
