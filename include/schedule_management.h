#ifndef SCHEDULE_MANAGEMENT_H
#define SCHEDULE_MANAGEMENT_H

#include <string>
#include <vector>

struct course {
	std::string name;
	std::string time;
	std::string professor;
	float grade;
};

class ScheduleManager {
private:
	std::vector<course> courses;

public:
	void manage_schedule();
	void add_course();
	void delete_course();
	void edit_course();
	void view_courses();
	void save_courses();
	void load_courses();
	const std::vector<course>& get_courses() const;
};

#endif // SCHEDULE_MANAGEMENT_H