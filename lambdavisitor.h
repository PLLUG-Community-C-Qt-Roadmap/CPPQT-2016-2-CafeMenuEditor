#ifndef LAMBDAVISITOR_H
#define LAMBDAVISITOR_H

#include <abstractvisitor.h>
#include <functional>

class LambdaVisitor : public AbstractVisitor
{
public:
    LambdaVisitor();

    void setMenuHandler(std::function<void(Menu *)> menuHandler);
    void setMenuItemHandler(std::function<void(MenuItem *)> menuItemHandler);

    // AbstractVisitor interface
public:
    virtual void visit(Menu *item) override;
    virtual void visit(MenuItem *item) override;

private:
    std::function<void(Menu *)> mMenuHandler;
    std::function<void(MenuItem *)> mMenuItemHandler;
};

#endif // LAMBDAVISITOR_H
