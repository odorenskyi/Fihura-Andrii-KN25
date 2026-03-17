#include <iostream>

// підключаємо функцію з бібліотеки
double s_calculation(double x, double y, double z);

int main()
{
    double x, y, z;

    std::cout << "write x: ";
    std::cin >> x;

    std::cout << "write y: ";
    std::cin >> y;

    std::cout << "write z: ";
    std::cin >> z;

    try
    {
        double S = s_calculation(x, y, z);
        std::cout << "S = " << S << std::endl;
    }
    catch (...)
    {
        std::cout << "error!" << std::endl;
    }

    return 0;
}
