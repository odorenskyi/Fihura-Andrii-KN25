#include "ClassLab12_Fihura.h"

ClassLab12_Fihura::
ClassLab12_Fihura(double r, double l)
{
    if (r > 0)
        radius = r;
    else
        radius = 1;

    if (l > 0)
        length = l;
    else
        length = 1;
}

double ClassLab12_Fihura::
getRadius() const
{
    return radius;
}

double ClassLab12_Fihura::
getLength() const
{
    return length;
}

void ClassLab12_Fihura::
setData(double r, double l)
{
    if (r > 0)
        radius = r;

    if (l > 0)
        length = l;
}

double ClassLab12_Fihura::
getSideArea() const
{
    return 2 * 3.1415926535 * radius * length;
}
