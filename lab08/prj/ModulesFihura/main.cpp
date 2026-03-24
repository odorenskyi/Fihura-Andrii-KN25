#include <cmath>
#include <stdexcept>

double s_calculation(double x, double y, double z)
{
    const double PI = 3.141592653589793;

    if (x - y <= 0)
        throw std::invalid_argument("x - y must be > 0");

    if (y == 0)
        throw std::invalid_argument("y must not be 0");

    double denominator = x + z / (2 * y * y);

    if (denominator == 0)
        throw std::invalid_argument("division by zero");

    double expression = PI * x * x / denominator;

    if (expression < 0)
        throw std::domain_error("sqrt argument must be >= 0");

    return log(x - y) + sqrt(expression);
}
