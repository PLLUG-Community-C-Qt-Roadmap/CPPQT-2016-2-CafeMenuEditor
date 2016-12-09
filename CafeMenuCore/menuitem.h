#ifndef MENUITEM_H
#define MENUITEM_H

#include "abstractmenuitem.h"

/*!
 * \brief The MenuItem class implemens single menu entry.
 */
class MenuItem : public AbstractMenuItem
{
public:
    MenuItem(const std::string &title
        , double price
        , const std::string &description = {});

    double price() const;
    void setPrice(double price);

    std::string description() const;
    void setDescription(const std::string &description);

private:
    double mPrice;
    std::string mDescription;

    // AbstractMenuItem interface
public:
    virtual void apply(AbstractVisitor *visitor) override;
};

#endif // MENUITEM_H
