#include <cmath>
#include <stdexcept>

double s_calculation(double x, double y, double z)
{
    if (x - y <= 0)
        throw std::invalid_argument("x - y має бути > 0");

    if (y == 0)
        throw std::invalid_argument("y не може бути 0");

    double denominator = x + z / (2 * y * y);

    if (denominator == 0)
        throw std::invalid_argument("Ділення на 0");

    return log(x - y) + sqrt(M_PI * x * x / denominator);
}
