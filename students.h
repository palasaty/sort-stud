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

	void print();
	void addStudent();
	void editStudent();
	void removeStudent();

	void customSort();

private:
	void load();
	void save();

	void addStudent(Student& st);
	Student& getStudent(long id) { return _database[id]; }

private:
	std::map<int, Student> _database;
};