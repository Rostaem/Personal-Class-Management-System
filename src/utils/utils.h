#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include<iomanip>
using namespace std;

// Function to display a formatted menu
void display_menu(const string &title, const vector<string> &options, const int width = 60);

//  clear input buffer
void clear_input_buffer();

// validate and get integer input
int get_valid_int_input(const string& prompt);

//trim whitespace from a string
string trim(const string& str);

// print a line with a specified character and length
void print_line(char ch, int length);

#endif // UTILS_H