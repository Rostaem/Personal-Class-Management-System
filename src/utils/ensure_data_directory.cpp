#include <iostream>
#include <filesystem>
#include "ensure_data_directory.h"

using namespace std;
namespace fs = filesystem;

void ensure_data_directory() {
	if (!fs::exists("data")) {
		if (fs::create_directory("data")) {
			cout << "Created 'data' directory for saving files." << endl;
		} else {
			cerr << "Error: Unable to create 'data' directory." << endl;
			exit(1);
		}
	}
}

