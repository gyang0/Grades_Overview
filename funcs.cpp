#include <iostream>
#include <fstream>
#include "funcs.h"

void addCourse()
{
    // Appending to file
    std::ofstream outputFile;
    outputFile.open("grades.txt", std::ios::app);
    
    // Variables
    std::string courseID, courseName;
    int gradeAverage, gradeTaken;
    
    
    // Add a course
    std::cout << "Enter the course ID: ";
    std::cin >> courseID;
    
    std::cin.ignore();
    std::cout << "Enter the course name: ";
    getline(std::cin, courseName);
    
    std::cout << "Enter your grade average: ";
    std::cin >> gradeAverage;
    while(gradeAverage < 0 || gradeAverage > 100)
    {
        std::cout << "Again: ";
        std::cin >> gradeAverage;
    }
    
    std::cout << "Enter your grade when you took this course: ";
    std::cin >> gradeTaken;
    while(gradeTaken < 7 || gradeTaken > 12)
    {
        std::cout << "Again: ";
        std::cin >> gradeTaken;
    }
    
    // Echo back
    std::cout << "\nAdded " << courseName << " (" << courseID << ") with a GPA of "
         << gradeAverage << " to grade " << gradeTaken;
    
    // Write to file
    outputFile << gradeTaken << " " << gradeAverage << "                 [" << courseID << "] " << courseName << "\n";
    
    
    outputFile.close();
}


void deleteCourse()
{
    
    
}

void showOverview()
{
    
    
}
