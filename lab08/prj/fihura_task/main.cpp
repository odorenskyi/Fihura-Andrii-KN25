#include <iostream>
#include <iomanip>
#include "ModulesFihura.h"

using namespace std;

// 8.2.1
string developer()
{
    return "Fihura Andrii ©";
}

// 8.2.2
int logic_result(char a, char b)
{
    return (a + 10 >= b);
}

// 8.2.3
void print_values(double x, double y, double z)
{
    cout << "Decimal: "
         << x << " "
         << y << " "
         << z << endl;

    cout << "Hex: "
         << hex
         << (int)x << " "
         << (int)y << " "
         << (int)z << endl;

    cout << dec;
}

int main()
{
    double x, y, z;
    char a, b;

    cin >> x >> y >> z;
    cin >> a >> b;

    // 8.2.1
    cout << developer() << endl;

    // 8.2.2
    cout << logic_result(a, b) << endl;

    // 8.2.3
    print_values(x, y, z);

    try
    {
        cout << "S = "
             << s_calculation(x, y, z)
             << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
