#include "menuitem.h"

#include "consoleprintvisitor.h"

MenuItem::MenuItem(const std::string &title, double price, const std::__cxx11::string &description)
    : AbstractMenuItem{title}
    , mPrice{price}
    , mDescription{description}
{

}

double MenuItem::price() const
{
    return mPrice;
}

void MenuItem::setPrice(double price)
{
    mPrice = price;
}

std::__cxx11::string MenuItem::description() const
{
    return mDescription;
}

void MenuItem::setDescription(const std::__cxx11::string &description)
{
    mDescription = description;
}

void MenuItem::apply(AbstractVisitor *visitor)
{
    if (visitor)
    {
        visitor->visit(this);
    }
}
