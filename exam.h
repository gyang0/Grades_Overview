#ifndef EXAM_H
#define EXAM_H

#include <string>

// A class to handle exams
class Exam {
private:
    char status; // Q = quiz
    int gradeTaken;
    std::string date;
    int score;
    std::string examName;
    
public:
    // Constructor
    Exam(char _status, int _gradeTaken, std::string _date, int _score, std::string _examName);

    // Getters
    char getStatus();
    int getGradeTaken();
    std::string getDate();
    int getScore();
    std::string getExamName();

    // Setters
    void setStatus(char newVar);
    void setGradeTaken(int newVar);
    void setDate(std::string newVar);
    void setScore(int newVar);
    void setExamName(std::string newVar);
};

#endif