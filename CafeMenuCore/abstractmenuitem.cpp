#include "abstractmenuitem.h"

/*!
 * \brief Public constructor.
 * \param title Menu title.
 */
AbstractMenuItem::AbstractMenuItem(const std::string &title)
    : mTitle{title}
{

}

/*!
 * \brief Returns title for the menu item.
 * \return Title text string.
 */
std::__cxx11::string AbstractMenuItem::title() const
{
    return mTitle;
}

