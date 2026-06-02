#ifndef CLASSLAB12_FIHURA_H
#define CLASSLAB12_FIHURA_H

class ClassLab12_Fihura
{
private:
    double radius;
    double length;

public:

    // Конструктор
    ClassLab12_Fihura(double r = 1.0,
                      double l = 1.0);

    // Отримання атрибутів
    double getRadius() const;
    double getLength() const;

    // Зміна атрибутів
    void setData(double r = 1.0,
                 double l = 1.0);

    // Площа бічної поверхні труби
    double getSideArea() const;
};

#endif
