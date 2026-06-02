#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

#include "ClassLab12_Fihura.h"

using namespace std;

struct TestCase
{
    string command;
    double radius;
    double length;
    double expected;
};

bool readTestCase(ifstream& fin, TestCase& tc)
{
    string line;

    if(!getline(fin, line))
        return false;

    stringstream ss(line);

    string temp;

    getline(ss, tc.command, ';');

    getline(ss, temp, ';');
    tc.radius = atof(temp.c_str());

    getline(ss, temp, ';');
    tc.length = atof(temp.c_str());

    getline(ss, temp);
    tc.expected = atof(temp.c_str());

    return true;
}

int main()
{
    ofstream result("TestResults.txt");

    result << "UNIT TEST REPORT\n\n";

    const char* files[] =
{
    "TestRadius.txt",
    "TestLength.txt",
    "TestArea.txt"
};

    for(int i = 0; i < 3; i++)
    {
        ifstream fin(files[i]);

        if(!fin)
        {
            result << "Cannot open "
                   << files[i]
                   << endl;
            continue;
        }

        TestCase tc;

        while(readTestCase(fin, tc))
        {
            ClassLab12_Fihura obj(
                tc.radius,
                tc.length
            );

            double actual = 0;

            if(tc.command == "GET_RADIUS")
                actual = obj.getRadius();

            if(tc.command == "GET_LENGTH")
                actual = obj.getLength();

            if(tc.command == "GET_AREA")
                actual = obj.getSideArea();

            bool pass =
                fabs(actual - tc.expected)
                < 0.01;

            result
                << tc.command
                << " Expected="
                << tc.expected
                << " Actual="
                << actual
                << " Result="
                << (pass ? "PASS" : "FAIL")
                << endl;
        }

        fin.close();
    }

    result.close();

    cout
        << "Testing completed."
        << endl;

    return 0;
}
