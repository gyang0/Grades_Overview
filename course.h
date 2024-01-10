#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <utility>

// A class to handle courses
class Course {
private:
    int gradeTaken;
    std::string courseCode;
    std::string courseName;
    std::pair<double, double> score; // <semester 1 score, semester 2 score>
    
public:
    // Constructor
    Course(int _gradeTaken, std::string _courseCode, std::string _courseName, std::pair<double, double> _score);

    // Getters
    int getGradeTaken();
    std::string getCourseCode();
    std::string getCourseName();
    std::pair<double, double> getScore();

    // Setters
    void setGradeTaken(int newVar);
    void setCourseCode(std::string newVar);
    void setCourseName(std::string newVar);
    void setScore(std::pair<double, double> newVar);
};

#endif