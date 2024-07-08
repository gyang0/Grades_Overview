#include "course.h"

// Constructor
Course::Course(char _status, int _gradeTaken, std::string _courseCode, std::string _courseName, std::pair<int, int> _score){
	status = _status;
	gradeTaken = _gradeTaken;
	courseCode = _courseCode;
	courseName = _courseName;
	score = _score;
}

// Getters
char Course::getStatus(){ return status; }
int Course::getGradeTaken(){ return gradeTaken; }
std::string Course::getCourseCode(){ return courseCode; }
std::string Course::getCourseName(){ return courseName; }
std::pair<int, int> Course::getScore(){ return score; }

// Setters
void Course::setStatus(char newVar){ status = newVar; }
void Course::setGradeTaken(int newVar){ gradeTaken = newVar; }
void Course::setCourseCode(std::string newVar){ courseCode = newVar; }
void Course::setCourseName(std::string newVar){ courseName = newVar; }
void Course::setScore(std::pair<int, int> newVar){ score = newVar; }