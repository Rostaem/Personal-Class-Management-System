#ifndef SCHEDULE_MANAGEMENT_H
#define SCHEDULE_MANAGEMENT_H

#include <vector>
#include <string>
using namespace std;

// Define the Class structure
struct Class {
	string name;
	string time;
	string professor;
	float grade;
};

// Declare the global classes vector
extern vector<Class> classes;

// Function declarations
void manage_schedule();
void add_class();
void delete_class();
void edit_class();
void view_classes();
void save_classes();
void load_classes();

#endif // SCHEDULE_MANAGEMENT_H