#include <iostream>
#include "ClassLab12_Fihura.h"

using namespace std;

int main()
{
    ClassLab12_Fihura pipe(5, 10);

    cout << "Radius = "
         << pipe.getRadius()
         << endl;

    cout << "Length = "
         << pipe.getLength()
         << endl;

    cout << "Side Area = "
         << pipe.getSideArea()
         << endl;

    pipe.setData(7, 12);

    cout << "\nAfter change:\n";

    cout << "Radius = "
         << pipe.getRadius()
         << endl;

    cout << "Length = "
         << pipe.getLength()
         << endl;

    cout << "Side Area = "
         << pipe.getSideArea()
         << endl;

    return 0;
}
