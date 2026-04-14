#include <iostream>
#include <string>
#include "ModulesFihura.h"

using namespace std;

int main()
{
    char command;
    char finish;

    do
    {
        cout << "Enter command:" << endl;
        cout << "h - run s_calculation()" << endl;
        cout << "f - task 9.1" << endl;
        cout << "d - task 9.2" << endl;
        cout << "s - task 9.3" << endl;
        cout << "Your choice: ";
        cin >> command;

        cout << endl;

        if (command == 'h')
        {
            double x, y, z;

            cout << "Enter x: ";
            cin >> x;
            cout << "Enter y: ";
            cin >> y;
            cout << "Enter z: ";
            cin >> z;

            try
            {
                double result = s_calculation(x, y, z);
                cout << "Result of s_calculation: " << result << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            catch (...)
            {
                cout << "Unknown error!" << endl;
            }
        }
        else if (command == 'f')
        {
            int score;
            string national, ects, explanation;

            cout << "Enter score (0..100): ";
            cin >> score;

            try
            {
                get_rating(score, national, ects, explanation);

                cout << "National rating: " << national << endl;
                cout << "ECTS rating: " << ects << endl;
                cout << "Explanation: " << explanation << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            catch (...)
            {
                cout << "Unknown error!" << endl;
            }
        }
        else if (command == 'd')
        {
            double t1, t2, t3, t4, t5, t6, t7;

            cout << "Enter temperature for Monday: ";
            cin >> t1;
            cout << "Enter temperature for Tuesday: ";
            cin >> t2;
            cout << "Enter temperature for Wednesday: ";
            cin >> t3;
            cout << "Enter temperature for Thursday: ";
            cin >> t4;
            cout << "Enter temperature for Friday: ";
            cin >> t5;
            cout << "Enter temperature for Saturday: ";
            cin >> t6;
            cout << "Enter temperature for Sunday: ";
            cin >> t7;

            double avg_c = average_temperature(t1, t2, t3, t4, t5, t6, t7);
            double avg_f = celsius_to_fahrenheit(avg_c);

            cout << "Average temperature in Celsius: " << avg_c << endl;
            cout << "Average temperature in Fahrenheit: " << avg_f << endl;
        }
        else if (command == 's')
        {
            int n;

            cout << "Enter N (0..17948360): ";
            cin >> n;

            try
            {
                int result = process_number_by_bit12(n);

                if (bit12_value(n) == 0)
                    cout << "Bit D12 = 0, number of binary zeros: " << result << endl;
                else
                    cout << "Bit D12 = 1, number of binary ones: " << result << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
            catch (...)
            {
                cout << "Unknown error!" << endl;
            }
        }
        else
        {
            cout << '\a';
            cout << "Incorrect input! Command ignored." << endl;
        }

        cout << endl;
        cout << "Enter 'a', 'A' or 'p' to exit, any other symbol to continue: ";
        cin >> finish;
        cout << endl;

    } while (finish != 'a' && finish != 'A' && finish != 'p');

    cout << "Program finished." << endl;

    return 0;
}
