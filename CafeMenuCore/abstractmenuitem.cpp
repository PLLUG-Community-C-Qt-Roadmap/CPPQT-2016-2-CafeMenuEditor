#include "abstractmenuitem.h"

/*!
 * \brief Public constructor.
 * \param title Menu title.
 */
AbstractMenuItem::AbstractMenuItem(const std::string &title)
    : mTitle{title},
      mUp(nullptr)
{

}

/*!
 * \brief Returns title for the menu item.
 * \return Title text string.
 */
std::string AbstractMenuItem::title() const
{
    return mTitle;
}

void AbstractMenuItem::setTitle(const std::string &title)
{
    mTitle = title;
}

void AbstractMenuItem::setUp(Menu *up)
{
    mUp = up;
}

