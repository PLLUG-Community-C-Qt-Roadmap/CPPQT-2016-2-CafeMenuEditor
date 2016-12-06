#ifndef ABSTRACTVISITOR_H
#define ABSTRACTVISITOR_H

class Menu;
class MenuItem;

class AbstractVisitor
{
public:
    virtual void visit(Menu *item)=0;
    virtual void visit(MenuItem *item)=0;
};

#endif // ABSTRACTVISITOR_H
