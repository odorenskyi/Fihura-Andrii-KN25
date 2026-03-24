#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <exception>
#include "ModulesFihura.h"

using namespace std;

struct TestCase
{
    double x;
    double y;
    double z;
    bool expect_exception;
    double expected_result;
    string description;
};

bool nearly_equal(double a, double b, double eps = 1e-6)
{
    return fabs(a - b) < eps;
}

int main()
{
    TestCase tests[] =
    {
        // Коректні тести
        {5.0, 2.0, 4.0, false, 4.877496595871273, "correct input #1"},
        {3.5, 1.2, 0.8, false, 4.024629063372321, "correct input #2"},

        // Помилкові тести
        {4.0, 0.0, 2.0, true, 0.0, "y = 0"},
        {2.0, 2.5, 1.0, true, 0.0, "x - y <= 0"},
        {2.0, 1.0, -4.0, true, 0.0, "denominator = 0"}
    };

    const int test_count = sizeof(tests) / sizeof(tests[0]);
    int passed_count = 0;

    cout << fixed << setprecision(6);
    cout << "=== UNIT TESTING OF s_calculation ===" << endl;

    for (int i = 0; i < test_count; i++)
    {
        cout << "\nTest case #" << (i + 1) << endl;
        cout << "Description: " << tests[i].description << endl;
        cout << "Input: x = " << tests[i].x
             << ", y = " << tests[i].y
             << ", z = " << tests[i].z << endl;

        bool passed = false;

        try
        {
            double actual_result = s_calculation(tests[i].x, tests[i].y, tests[i].z);

            cout << "Obtained result: " << actual_result << endl;

            if (!tests[i].expect_exception &&
                nearly_equal(actual_result, tests[i].expected_result))
            {
                passed = true;
            }
        }
        catch (exception& e)
        {
            cout << "Obtained exception: " << e.what() << endl;

            if (tests[i].expect_exception)
            {
                passed = true;
            }
        }
        catch (...)
        {
            cout << "Obtained unknown exception" << endl;

            if (tests[i].expect_exception)
            {
                passed = true;
            }
        }

        if (passed)
        {
            cout << "Status: PASSED" << endl;
            passed_count++;
        }
        else
        {
            cout << "Status: FAILED" << endl;
        }
    }

    cout << "\n=== TEST SUMMARY ===" << endl;
    cout << "Passed: " << passed_count << " / " << test_count << endl;

    if (passed_count == test_count)
        cout << "All test cases passed." << endl;
    else
        cout << "Some test cases failed." << endl;

    return 0;
}
