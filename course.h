#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <utility>

// A class to handle courses
class Course {
private:
    char status; // S = taken at school, E = external institution
    int gradeTaken;
    std::string courseCode;
    std::string courseName;
    std::pair<int, int> score; // <semester 1 score, semester 2 score>
    
public:
    // Constructor
    Course(char status, int _gradeTaken, std::string _courseCode, std::string _courseName, std::pair<int, int> _score);

    // Getters
    char getStatus();
    int getGradeTaken();
    std::string getCourseCode();
    std::string getCourseName();
    std::pair<int, int> getScore();

    // Setters
    void setStatus(char newVar);
    void setGradeTaken(int newVar);
    void setCourseCode(std::string newVar);
    void setCourseName(std::string newVar);
    void setScore(std::pair<int, int> newVar);
};

#endif