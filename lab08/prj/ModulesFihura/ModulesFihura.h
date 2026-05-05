#pragma once
#include <string>

double s_calculation(double x, double y, double z);
std::string developer();
int logic_result(char a, char b);
void print_values(double x, double y, double z);

// ===== Задача 9.1 =====
void get_rating(int score, std::string& national, std::string& ects, std::string& explanation);

// ===== Задача 9.2 =====
double average_temperature(double t1, double t2, double t3, double t4, double t5, double t6, double t7);
double celsius_to_fahrenheit(double tc);

// ===== Задача 9.3 =====
int bit12_value(int n);
int count_binary_ones(int n);
int count_binary_zeros(int n);
int process_number_by_bit12(int n);

// ===== Lab 10 =====

// Задача 10.1
void task_10_1(const std::string& inputFile, const std::string& outputFile);

// Задача 10.2
void task_10_2(const std::string& outputFile);

// Задача 10.3
void task_10_3(const std::string& outputFile, double x, double y, double z, unsigned int b);
