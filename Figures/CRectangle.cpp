#include "CRectangle.h"

CRectangle::CRectangle(Point p1, Point p2, GfxInfo figure_gfx_info)
    :CFigure(figure_gfx_info)
{
    this->p1 = p1;
    this->p2 = p2;
}

CRectangle::CRectangle()
{}

void CRectangle::Draw(Output* out_p) const
{
    //Call Output::DrawRect to draw a rectangle on the screen
    out_p->DrawRect(p1, p2, *this, selected);
}