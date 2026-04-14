#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "ModulesFihura.h"

using namespace std;

bool check_rating_test(int score, const string& exp_nat, const string& exp_ects, const string& exp_expl)
{
    string nat, ects, expl;

    try
    {
        get_rating(score, nat, ects, expl);

        bool passed = (nat == exp_nat && ects == exp_ects && expl == exp_expl);

        cout << "Input: score = " << score << endl;
        cout << "Expected: " << exp_nat << ", " << exp_ects << ", " << exp_expl << endl;
        cout << "Actual:   " << nat << ", " << ects << ", " << expl << endl;
        cout << "Status: " << (passed ? "passed" : "failed") << endl << endl;

        return passed;
    }
    catch (...)
    {
        cout << "Input: score = " << score << endl;
        cout << "Actual: exception" << endl;
        cout << "Status: failed" << endl << endl;
        return false;
    }
}

bool check_temp_test(double t1, double t2, double t3, double t4, double t5, double t6, double t7,
                     double exp_c, double exp_f)
{
    double avg_c = average_temperature(t1, t2, t3, t4, t5, t6, t7);
    double avg_f = celsius_to_fahrenheit(avg_c);

    bool passed = (std::fabs(avg_c - exp_c) < 0.001 &&
                   std::fabs(avg_f - exp_f) < 0.001);

    cout << fixed << setprecision(2);
    cout << "Input: " << t1 << ", " << t2 << ", " << t3 << ", " << t4 << ", "
         << t5 << ", " << t6 << ", " << t7 << endl;
    cout << "Expected: " << exp_c << " C, " << exp_f << " F" << endl;
    cout << "Actual:   " << avg_c << " C, " << avg_f << " F" << endl;
    cout << "Status: " << (passed ? "passed" : "failed") << endl << endl;

    return passed;
}

bool check_bit_test(int n, int expected_result)
{
    try
    {
        int actual = process_number_by_bit12(n);
        bool passed = (actual == expected_result);

        cout << "Input: N = " << n << endl;
        cout << "Expected: " << expected_result << endl;
        cout << "Actual:   " << actual << endl;
        cout << "Status: " << (passed ? "passed" : "failed") << endl << endl;

        return passed;
    }
    catch (...)
    {
        cout << "Input: N = " << n << endl;
        cout << "Actual: exception" << endl;
        cout << "Status: failed" << endl << endl;
        return false;
    }
}

int main()
{
    int passed_count = 0;
    int total_count = 0;

    cout << "===== TASK 9.1 TESTS =====" << endl << endl;
    total_count++;
    if (check_rating_test(95, "Perfectly", "A", "excellent performance with small number of errors")) passed_count++;

    total_count++;
    if (check_rating_test(70, "Satisfactorily", "D", "not bad, but with significant number of defects")) passed_count++;

    total_count++;
    if (check_rating_test(20, "Unsatisfactorily", "F", "with the obligatory repeated course")) passed_count++;

    cout << "===== TASK 9.2 TESTS =====" << endl << endl;
    total_count++;
    if (check_temp_test(10, 12, 11, 13, 14, 9, 15, 12.00, 53.60)) passed_count++;

    total_count++;
    if (check_temp_test(0, 0, 0, 0, 0, 0, 0, 0.00, 32.00)) passed_count++;

    total_count++;
    if (check_temp_test(-5, -3, -4, -6, -2, -1, -7, -4.00, 24.80)) passed_count++;

    cout << "===== TASK 9.3 TESTS =====" << endl << endl;
    total_count++;
    if (check_bit_test(10, 2)) passed_count++;

    total_count++;
    if (check_bit_test(4096, 1)) passed_count++;

    total_count++;
    if (check_bit_test(15, 0)) passed_count++;

    cout << "===== FINAL RESULT =====" << endl;
    cout << "Passed: " << passed_count << " / " << total_count << endl;

    if (passed_count == total_count)
        cout << "All tests passed." << endl;
    else
        cout << "Some tests failed." << endl;

    return 0;
}
