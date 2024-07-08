#include "exam.h"

// Constructor
Exam::Exam(char _status, int _gradeTaken, std::string _date, int _score, std::string _examName){
	status = _status;
	gradeTaken = _gradeTaken;
	date = _date;
	score = _score;
	examName = _examName;
}

// Getters
char Exam::getStatus(){ return status; }
int Exam::getGradeTaken(){ return gradeTaken; }
std::string Exam::getDate(){ return date; }
int Exam::getScore(){ return score; }
std::string Exam::getExamName(){ return examName; }

// Setters
void Exam::setStatus(char newVar){ status = newVar; }
void Exam::setGradeTaken(int newVar){ gradeTaken = newVar; }
void Exam::setDate(std::string newVar){ date = newVar; }
void Exam::setScore(int newVar){ score = newVar; }
void Exam::setExamName(std::string newVar){ examName = newVar; }
