#include "menuitem.h"
#include "menu.h";

#include "consoleprintvisitor.h"

MenuItem::MenuItem(const std::string &title, double price, const std::string &description,bool neue)
    : AbstractMenuItem{title}
    , mPrice{price}
    , mDescription{description}
    , mNeue{neue}
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

bool MenuItem::neue () const
{
   return mNeue;
}

void MenuItem::setNeue(bool neue)
{
    mNeue = neue;
}



std::string MenuItem::description() const
{
    return mDescription;
}

void MenuItem::setDescription(const std::string &description)
{
    mDescription = description;
}

void MenuItem::removeSubitem()
{
    mUp->deleteChild(this);
}

void MenuItem::apply(AbstractVisitor *visitor)
{
    if (visitor)
    {
        visitor->visit(this);
    }
}
