#include <iostream>
#include <fstream>
#include <string>
#include "ModulesFihura.h"

using namespace std;

bool file_contains(const string& filename, const string& text)
{
    ifstream fin(filename);

    if (!fin.is_open())
        return false;

    string content;
    string line;

    while (getline(fin, line))
    {
        content += line + "\n";
    }

    fin.close();

    return content.find(text) != string::npos;
}

void create_input_file(const string& filename, const string& content)
{
    ofstream fout(filename);

    if (fout.is_open())
    {
        fout << content;
        fout.close();
    }
}

bool test_10_1_word()
{
    string inputFile = "input_10_1.txt";
    string outputFile = "output_10_1.txt";

    create_input_file(inputFile, "мамо");

    try
    {
        task_10_1(inputFile, outputFile);

        bool passed = file_contains(outputFile, "Word length") &&
                      file_contains(outputFile, "Word found");

        cout << "TC_10_1_01" << endl;
        cout << "Input file: " << inputFile << ", content: мамо" << endl;
        cout << "Expected: word length and word found in poem" << endl;
        cout << "Status: " << (passed ? "passed" : "failed") << endl << endl;

        return passed;
    }
    catch (...)
    {
        cout << "TC_10_1_01 Status: failed" << endl << endl;
        return false;
    }
}

bool test_10_1_punctuation()
{
    string inputFile = "input_10_1_punct.txt";
    string outputFile = "output_10_1_punct.txt";

    create_input_file(inputFile, ",");

    try
    {
        task_10_1(inputFile, outputFile);

        bool passed = file_contains(outputFile, "punctuation");

        cout << "TC_10_1_02" << endl;
        cout << "Input file: " << inputFile << ", content: ," << endl;
        cout << "Expected: punctuation mark message" << endl;
        cout << "Status: " << (passed ? "passed" : "failed") << endl << endl;

        return passed;
    }
    catch (...)
    {
        cout << "TC_10_1_02 Status: failed" << endl << endl;
        return false;
    }
}

bool test_10_2_append()
{
    string outputFile = "output_10_2.txt";

    create_input_file(outputFile, "Start text\n");

    try
    {
        task_10_2(outputFile);

        bool passed = file_contains(outputFile, "Хай щастить у Вашій хаті, мамо") &&
                      file_contains(outputFile, "Date and time");

        cout << "TC_10_2_01" << endl;
        cout << "Output file before test: Start text" << endl;
        cout << "Expected: poem line and date/time appended" << endl;
        cout << "Status: " << (passed ? "passed" : "failed") << endl << endl;

        return passed;
    }
    catch (...)
    {
        cout << "TC_10_2_01 Status: failed" << endl << endl;
        return false;
    }
}

bool test_10_3_binary()
{
    string outputFile = "output_10_3.txt";

    create_input_file(outputFile, "Start text\n");

    try
    {
        task_10_3(outputFile, 5, 2, 4, 10);

        bool passed = file_contains(outputFile, "Binary code of b: 1010");

        cout << "TC_10_3_01" << endl;
        cout << "Input: x=5, y=2, z=4, b=10" << endl;
        cout << "Expected: binary code 1010" << endl;
        cout << "Status: " << (passed ? "passed" : "failed") << endl << endl;

        return passed;
    }
    catch (...)
    {
        cout << "TC_10_3_01 Status: failed" << endl << endl;
        return false;
    }
}

bool test_10_3_zero()
{
    string outputFile = "output_10_3_zero.txt";

    create_input_file(outputFile, "Start text\n");

    try
    {
        task_10_3(outputFile, 5, 2, 4, 0);

        bool passed = file_contains(outputFile, "Binary code of b: 0");

        cout << "TC_10_3_02" << endl;
        cout << "Input: x=5, y=2, z=4, b=0" << endl;
        cout << "Expected: binary code 0" << endl;
        cout << "Status: " << (passed ? "passed" : "failed") << endl << endl;

        return passed;
    }
    catch (...)
    {
        cout << "TC_10_3_02 Status: failed" << endl << endl;
        return false;
    }
}

int main()
{
    int passed = 0;
    int total = 0;

    cout << "===== LAB 10 UNIT TESTING =====" << endl << endl;

    total++;
    if (test_10_1_word()) passed++;

    total++;
    if (test_10_1_punctuation()) passed++;

    total++;
    if (test_10_2_append()) passed++;

    total++;
    if (test_10_3_binary()) passed++;

    total++;
    if (test_10_3_zero()) passed++;

    cout << "===== FINAL RESULT =====" << endl;
    cout << "Passed: " << passed << " / " << total << endl;

    if (passed == total)
        cout << "All tests passed." << endl;
    else
        cout << "Some tests failed." << endl;

    return 0;
}
