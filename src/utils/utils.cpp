#include "utils.h"

const int WIDTH = 60;
const int BOXWIDTH = 40;

void submenu_formatting(string submenu_title, string submenu_options[], int size) {
	// Centering the title
	cout << setfill('=') << setw(WIDTH) << " " << endl;

	int padding = (WIDTH - submenu_title.length()) / 2;
	cout << setfill(' ') << setw(padding + submenu_title.length()) << submenu_title
		 << setw(WIDTH - padding - submenu_title.length()) << "" << endl;

	cout << setfill('=') << setw(WIDTH) << " " << endl;

	for (int i = 0; i < size; i++) {
		const string &option = submenu_options[i];

		cout << "|" << setfill('-') << setw(BOXWIDTH) << "" << "|" << endl;

		int option_padding = (BOXWIDTH - option.length()) / 2;
		cout << "|" << setfill(' ')
			 << setw(option_padding) << "" << option
			 << setw(BOXWIDTH - option_padding - option.length()) << "" << "|" << endl;

		cout << "|" << setfill('-') << setw(BOXWIDTH) << "" << "|" << endl;
	}
}

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
		return -1; // the -1 will let the other file know something went wrong
	}

	return choice;
}