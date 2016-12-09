#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>

#include "abstractmenuitem.h"

/*!
 * \brief The Menu class implements menus and submenus that contains list of menu items.
 */
class Menu : public AbstractMenuItem
{
public:
    Menu(const std::string &title);

    int count() const;
    AbstractMenuItem *at(int index) const;

    void append(std::unique_ptr<AbstractMenuItem> item);

private:
    std::vector<std::unique_ptr<AbstractMenuItem>> mListItems;

    // AbstractMenuItem interface
public:
    virtual void apply(AbstractVisitor *visitor) override;
};

#endif // MENU_H
