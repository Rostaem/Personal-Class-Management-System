#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
using namespace std;

//this file was previously named main_menu_display and it served the purpose of storing the function to display the main menu
// it's now used to display all menus (main menu and submenu, by using a menu class which will store both functions)

class Menu {
private:
	const int WIDTH = 60;       // for menu formatting
	const int BOX_WIDTH = 40;   // for menu boxes
    void submenu_formatting(const string& submenu_title, const vector<string>& submenu_options) const;
public:
	Menu();

	// Display main menu
	void display_main_menu() const;

	// Display submenu
	void display_submenu(const string& submenu_title, const vector<string>& submenu_options) const;

	bool handle_main_menu_choice(int choice) const;
};
#endif //MENU_H