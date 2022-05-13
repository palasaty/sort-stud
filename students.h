#pragma once
#include <fstream>
#include <map>
#include "student.h"

const std::string gFileName = "StudentsDatabase.txt";

class Students {
public:
	Students() { load(); }
	~Students() { save(); }

	bool empty() { return _database.empty(); }

	void addStudent(Student& st) { _database[st.gradeBookNo] = st; }
	Student& getStudent(long id) { return _database[id]; }
	void print();


private:
	void load();
	void save();

private:
	std::map<long, Student> _database;;
};