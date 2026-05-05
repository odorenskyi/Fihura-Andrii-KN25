#include <iostream>
#include <string>
#include "ModulesFihura.h"

using namespace std;

int main()
{
    char choice;
    char exitChoice;

    do
    {
        cout << "1 - Task 10.1: analyze input text file" << endl;
        cout << "2 - Task 10.2: append poem line and date/time" << endl;
        cout << "3 - Task 10.3: calculate s_calculation and binary code" << endl;
        cout << "Your choice: ";
        cin >> choice;

        cout << endl;

        if (choice == '1')
        {
            string inputFile, outputFile;

            cout << "Enter input file name: ";
            cin >> inputFile;

            cout << "Enter output file name: ";
            cin >> outputFile;

            try
            {
                task_10_1(inputFile, outputFile);
                cout << "Task 10.1 completed successfully." << endl;
                cout << "Result saved to file: " << outputFile << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == '2')
        {
            string outputFile;

            cout << "Enter output file name: ";
            cin >> outputFile;

            try
            {
                task_10_2(outputFile);
                cout << "Task 10.2 completed successfully." << endl;
                cout << "Information appended to file: " << outputFile << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        else if (choice == '3')
        {
            string outputFile;
            double x, y, z;
            unsigned int b;

            cout << "Enter output file name: ";
            cin >> outputFile;

            cout << "Enter x: ";
            cin >> x;

            cout << "Enter y: ";
            cin >> y;

            cout << "Enter z: ";
            cin >> z;

            cout << "Enter natural number b: ";
            cin >> b;

            try
            {
                task_10_3(outputFile, x, y, z, b);
                cout << "Task 10.3 completed successfully." << endl;
                cout << "Result appended to file: " << outputFile << endl;
            }
            catch (const exception& e)
            {
                cout << "Error: " << e.what() << endl;
            }
        }
        else
        {
            cout << '\a';
            cout << "Incorrect choice! Command ignored." << endl;
        }

        cout << endl;
        cout << "Enter a, A or p to exit. Enter any other symbol to continue: ";
        cin >> exitChoice;
        cout << endl;

    } while (exitChoice != 'a' && exitChoice != 'A' && exitChoice != 'p');

    cout << "Program finished." << endl;

    return 0;
}
