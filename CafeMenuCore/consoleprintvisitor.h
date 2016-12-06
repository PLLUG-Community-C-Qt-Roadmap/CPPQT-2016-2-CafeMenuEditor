#ifndef VISITOR_H
#define VISITOR_H

#include "abstractvisitor.h"

class Menu;
class MenuItem;


class ConsolePrintVisitor : public AbstractVisitor
{
public:
    void visit(Menu *item);
    void visit(MenuItem *item);
};

#endif // VISITOR_H
