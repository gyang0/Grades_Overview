#include "course.h"

// Constructor
Course::Course(int _gradeTaken, std::string _courseCode, std::string _courseName, double _score){
	gradeTaken = _gradeTaken;
	courseCode = _courseCode;
	courseName = _courseName;
	score = _score;
}

// Getters
int Course::getGradeTaken(){ return gradeTaken; }
std::string Course::getCourseCode(){ return courseCode; }
std::string Course::getCourseName(){ return courseName; }
double Course::getScore(){ return score; }

// Setters
void Course::setGradeTaken(int newVar){ gradeTaken = newVar; }
void Course::setCourseCode(std::string newVar){ courseCode = newVar; }
void Course::setCourseName(std::string newVar){ courseName = newVar; }
void Course::setScore(int newVar){ score = newVar; }