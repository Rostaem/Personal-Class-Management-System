#include "utils.h"

int input_validation(int min, int max, string prompt) {
	int choice;

	cout << prompt;
	cin >> choice;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return -1;
	}

	if (choice < min || choice > max) {
		return -1;
	}

	return choice;
}