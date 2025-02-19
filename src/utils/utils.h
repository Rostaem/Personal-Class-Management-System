#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void submenu_formatting(string submenu_title, string submenu_options[], int size);

//this function will replace the repetitive input validation in all cpp files
int input_validation(int min, int max, string prompt );

#endif // UTILS_H