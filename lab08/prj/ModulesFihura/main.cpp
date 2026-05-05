#include <cmath>
#include <stdexcept>
#include <string>

#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

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

void get_rating(int score, string& national, string& ects, string& explanation)
{
    if (score >= 90 && score <= 100)
    {
        national = "Perfectly";
        ects = "A";
        explanation = "excellent performance with small number of errors";
    }
    else if (score >= 82 && score <= 89)
    {
        national = "Good";
        ects = "B";
        explanation = "above average some mistakes";
    }
    else if (score >= 75 && score <= 81)
    {
        national = "Good";
        ects = "C";
        explanation = "overall correct fulfilment of certain task with significant number of errors";
    }
    else if (score >= 67 && score <= 74)
    {
        national = "Satisfactorily";
        ects = "D";
        explanation = "not bad, but with significant number of defects";
    }
    else if (score >= 60 && score <= 66)
    {
        national = "Satisfactorily";
        ects = "E";
        explanation = "satisfies minimum criteria";
    }
    else if (score >= 35 && score <= 59)
    {
        national = "Unsatisfactorily";
        ects = "FX";
        explanation = "with the possibility of re-assembly";
    }
    else if (score >= 1 && score <= 34)
    {
        national = "Unsatisfactorily";
        ects = "F";
        explanation = "with the obligatory repeated course";
    }
    else if (score == 0)
    {
        national = "Unsatisfactorily";
        ects = "F";
        explanation = "with the obligatory repeated course";
    }
    else
    {
        throw invalid_argument("score must be from 0 to 100");
    }
}

double average_temperature(double t1, double t2, double t3, double t4, double t5, double t6, double t7)
{
    return (t1 + t2 + t3 + t4 + t5 + t6 + t7) / 7.0;
}

double celsius_to_fahrenheit(double tc)
{
    return 32 + 9.0 * tc / 5.0;
}

int bit12_value(int n)
{
    return (n >> 12) & 1;
}

int count_binary_ones(int n)
{
    int count = 0;

    if (n == 0)
        return 0;

    while (n > 0)
    {
        if ((n & 1) == 1)
            count++;

        n >>= 1;
    }

    return count;
}

int count_binary_zeros(int n)
{
    int count = 0;

    if (n == 0)
        return 1;

    while (n > 0)
    {
        if ((n & 1) == 0)
            count++;

        n >>= 1;
    }

    return count;
}

int process_number_by_bit12(int n)
{
    if (n < 0 || n > 17948360)
        throw invalid_argument("n must be from 0 to 17948360");

    if (bit12_value(n) == 0)
        return count_binary_zeros(n);
    else
        return count_binary_ones(n);
}

//Функція задачі 10.1

void task_10_1(const std::string& inputFile, const std::string& outputFile)
{
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (!fin.is_open())
        throw runtime_error("Cannot open input file");

    if (!fout.is_open())
        throw runtime_error("Cannot open output file");

    string word;
    fin >> word;

    // Авторська інформація
    fout << "Author: Fihura Andrii\n";
    fout << "University: CNTU\n";
    fout << "City: Kropyvnytskyi\n";
    fout << "Country: Ukraine\n\n";

    // Перевірка: слово чи знак
    if (word.length() == 1 && ispunct(word[0]))
    {
        fout << "This is punctuation mark\n";
    }
    else
    {
        fout << "Word length: " << word.length() << endl;

        string poem = "Хай щастить у Вашій хаті, мамо";
        if (poem.find(word) != string::npos)
            fout << "Word found in poem\n";
        else
            fout << "Word not found in poem\n";
    }

    fin.close();
    fout.close();
}

//функція задачі 10.2
void task_10_2(const std::string& outputFile)
{
    ofstream fout(outputFile, ios::app);

    if (!fout.is_open())
        throw runtime_error("Cannot open output file");

    time_t now = time(0);
    char* dt = ctime(&now);

    fout << "\n===== Task 10.2 =====\n";
    fout << "Хай щастить у Вашій хаті, мамо\n";
    fout << "Date and time: " << dt << endl;

    fout.close();
}

//функція задачі 10.3
std::string to_binary(unsigned int b)
{
    if (b == 0)
        return "0";

    std::string result = "";

    while (b > 0)
    {
        result = char('0' + b % 2) + result;
        b /= 2;
    }

    return result;
}

void task_10_3(const std::string& outputFile, double x, double y, double z, unsigned int b)
{
    ofstream fout(outputFile, ios::app);

    if (!fout.is_open())
        throw runtime_error("Cannot open output file");

    fout << "\n===== Task 10.3 =====\n";

    try
    {
        double s = s_calculation(x, y, z);
        fout << "s_calculation(" << x << ", " << y << ", " << z << ") = " << s << endl;
    }
    catch (const exception& e)
    {
        fout << "s_calculation error: " << e.what() << endl;
    }

    fout << "Number b: " << b << endl;
    fout << "Binary code of b: " << to_binary(b) << endl;

    fout.close();
}
