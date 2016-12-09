#include "lambdavisitor.h"

LambdaVisitor::LambdaVisitor()
{

}

void LambdaVisitor::setMenuHandler(std::function<void (Menu *)> menuHandler)
{
    mMenuHandler = menuHandler;
}

void LambdaVisitor::setMenuItemHandler(std::function<void (MenuItem *)> menuItemHandler)
{
    mMenuItemHandler = menuItemHandler;
}

void LambdaVisitor::visit(Menu *item)
{
    if (mMenuHandler)
    {
        mMenuHandler(item);
    }
}

void LambdaVisitor::visit(MenuItem *item)
{
    if (mMenuItemHandler)
    {
        mMenuItemHandler(item);
    }
}
