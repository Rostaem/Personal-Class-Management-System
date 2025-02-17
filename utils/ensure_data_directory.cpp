#include <iostream>
#include <filesystem>
#include "ensure_data_directory.h"

using namespace std;
namespace fs = filesystem;

// porpuse: Function to ensure the 'data' directory exists
void ensure_data_directory() {
	if (!fs::exists("data")) { // Check if the 'data' directory exists
		if (fs::create_directory("data")) { // Create the directory if it doesn't exist
			cout << "Created 'data' directory for saving files." << endl;
		} else {
			cout << "Error: Unable to create 'data' directory." << endl;
			exit(1);
		}
	}
}