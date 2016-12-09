#include "menu.h"

#include "consoleprintvisitor.h"

/*!
 * \brief Public constructor.
 * \param title Menu title.
 */
Menu::Menu(const std::__cxx11::string &title)
    : AbstractMenuItem{title}
{

}

/*!
 * \brief Return number of menu entries.
 */
int Menu::count() const
{
    return mListItems.size();
}

/*!
 * \brief Gives access to the menu entry by its index.
 * \param index Position of menu entry starting from zero.
 * \return Pointer
 *  to the menu item.
 */
AbstractMenuItem *Menu::at(int index) const
{
    return mListItems.at(index).get();
}

void Menu::append(std::unique_ptr<AbstractMenuItem> item)
{
    mListItems.push_back(std::move(item));
}

void Menu::apply(AbstractVisitor *visitor)
{
    if (visitor)
    {
        visitor->visit(this);
    }
}
