#ifndef MENUITERATOR_H
#define MENUITERATOR_H

#include <stack>
#include <memory>

class AbstractMenuItem;
#include "lambdavisitor.h"

/*!
 * \brief The MenuIterator class implements depth first iteraotion
 *   over the given menu item composite.
 */
class MenuIterator
{
public:
    MenuIterator(AbstractMenuItem *menu);

    bool hasNext() const;
    AbstractMenuItem *next();

private:
    std::stack<AbstractMenuItem *> mItemsStack;
    std::unique_ptr<LambdaVisitor> mAddChildrenVisitor;
};

#endif // MENUITERATOR_H
