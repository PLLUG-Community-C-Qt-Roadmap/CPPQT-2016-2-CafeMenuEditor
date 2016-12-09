#include "menuiterator.h"

#include <utility>

#include <abstractmenuitem.h>
#include <menu.h>

#include "lambdavisitor.h"

/*!
 * \brief MenuIterator::MenuIterator constructor
 * \param container is menu item to iterate
 */
MenuIterator::MenuIterator(AbstractMenuItem *menu)
    : mAddChildrenVisitor{std::make_unique<LambdaVisitor>()}
{
    auto addChildrenForTraversal = [this](Menu *item)
    {
        if (!item)
        {
            return;
        }

        for (int index = 0; index < item->count(); ++index)
        {
            auto next = item->at(index);
            this->mItemsStack.push(next);
        }
    };

    mAddChildrenVisitor->setMenuHandler(addChildrenForTraversal);
    menu->apply(mAddChildrenVisitor.get());
}

/*!
 * \brief MenuIterator::hasNext
 * \return true if next menu item is found, else - false
 */
bool MenuIterator::hasNext() const
{
    return !mItemsStack.empty();
}

/*!
 * \brief MenuIterator::next
 * \return next menu item
 */
AbstractMenuItem *MenuIterator::next()
{
    AbstractMenuItem *nextItem = mItemsStack.top();
    mItemsStack.pop();

    nextItem->apply(mAddChildrenVisitor.get());
    return nextItem;
}

