#include "main_menu_display.h"
using namespace std;

void main_menu_display() {
  	const int WIDTH = 60;
    cout << setfill('*') << setw(WIDTH) << "" << endl;
    cout << setfill(' ') << setw((WIDTH + 44)/2) << "Welcome to your Personal Class Management System!" << endl;
    cout << setw((WIDTH + 23) / 2) << "Choose where to navigate" << endl;
	cout << setfill('*') << setw(WIDTH) << "" << endl;

	cout << "1. Schedule" << endl;
	cout << "2. Attendance" << endl;
	cout << "3. Record & View Grades" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
}