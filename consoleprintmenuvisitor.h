#ifndef CONSOLEPRINTMENUVISITOR_H
#define CONSOLEPRINTMENUVISITOR_H

#include <abstractvisitor.h>
#include <string>

class AbstractMenuItem;
/*!
 * \brief The ConsolePrintMenuVisitor class
 */
class ConsolePrintMenuVisitor : public AbstractVisitor
{
public:
    virtual void visit(MenuItem *item) override;
    virtual void visit(Menu *menu) override;

private:
    std::string indent(AbstractMenuItem *item) const;
};

#endif // CONSOLEPRINTMENUVISITOR_H
