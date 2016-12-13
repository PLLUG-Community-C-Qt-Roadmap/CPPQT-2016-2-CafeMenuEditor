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
        , const std::string &description = {}
        , bool neue = false);

    double price() const;
    void setPrice(double price);

    bool neue() const;
    void setNeue(bool neue);

    std::string description() const;
    void setDescription(const std::string &description);

private:
    double mPrice;
    std::string mDescription;
    bool mNeue;

    // AbstractMenuItem interface
public:
    virtual void apply(AbstractVisitor *visitor) override;
};

#endif // MENUITEM_H
