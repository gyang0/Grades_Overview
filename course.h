#ifndef COURSE_H
#define COURSE_H

#include <string>

// A class to handle courses
class Course {
private:
    int gradeTaken;
    std::string courseCode;
    std::string courseName;
    double score;
    
public:
    // Constructor
    Course(int _gradeTaken, std::string _courseCode, std::string _courseName, double _score);

    // Getters
    int getGradeTaken();
    std::string getCourseCode();
    std::string getCourseName();
    double getScore();

    // Setters
    void setGradeTaken(int newVar);
    void setCourseCode(std::string newVar);
    void setCourseName(std::string newVar);
    void setScore(int newVar);
};

#endif