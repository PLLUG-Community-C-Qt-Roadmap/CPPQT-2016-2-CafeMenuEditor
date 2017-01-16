#ifndef ABSTRACTMENUITEM_H
#define ABSTRACTMENUITEM_H

#include <string>
class Menu;
/*!
 * \brief The AbstractMenuItem class is the base class for items containing in the menu.
 */

class AbstractVisitor;

class AbstractMenuItem
{
public:
    AbstractMenuItem(const std::string &title);

    std::string title() const;
    void setTitle(const std::string& title);

    virtual void apply(AbstractVisitor *visitor) = 0;
    virtual void removeSubitem()=0;
    virtual ~AbstractMenuItem() {}
    void setUp(Menu* up);
protected:
    Menu* mUp;
private:
    std::string mTitle;
};

#endif // ABSTRACTMENUITEM_H
