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
    std::cout << "\nAdded course to file.";
    
    
    std::string spaces;
    
    // Write to file
    outputFile << gradeTaken << spaces.assign(' ', 30)
               << " [" << courseID << "] "
               << courseName
               << gradeAverage << "\n";
    
    
    outputFile.close();
}


void deleteCourse()
{
    
    
}

void showOverview()
{
    std::string line;
    int grade = 0,
        count = 0,
        word;
    
    // For calculating average
    double sumGrades = 0.0;
    int numCourses = 0;
    
    
    // File
    std::ifstream file;
    
    
    for(int i = 7; i <= 12; i++)
    {
        // Reset
        sumGrades = 0.0;
        numCourses = 0;
        
        
        // Open file
        file.open("grades.txt", std::ios::in);
        
        std::cout << i << "th grade\n";
        std::cout << "  Course                        Grade\n";
        
        
        
        while(getline(file, line))
        {
            // The grade level
            if(line[1] == ' ')
                grade = ((int)line[0] - 48);
            else
                grade = ((int)line[0] - 48) * 10 + ((int)line[1] - 48);
            
            
            if(grade == i)
            {
                numCourses++;
                
                // One digit
                if(line[line.length() - 2] == ' ')
                    sumGrades += (line[line.length() - 1] - 48) * 10;
                
                // Two digits
                else if(line[line.length() - 3] == ' ')
                    sumGrades += ((line[line.length() - 2] - 48) * 10
                                  + (line[line.length() - 1] - 48));
                // Three digits
                else
                    sumGrades += ((line[line.length() - 3] - 48) * 100
                                  + (line[line.length() - 2] - 48) * 10
                                  + (line[line.length() - 1] - 48));
                
                
                std::cout << "  ";
                for(int j = 2; j < line.length(); j++)
                    std::cout << line[j];
                    
                std::cout << "\n";
            }
            
        }
        
        if(numCourses > 0)
            std::cout << "Average grade: " << (sumGrades/numCourses) << "\n";
        else
            std::cout << "No data\n";
        
        std::cout << "\n";
        
        // Close file
        file.close();
        
    }
    
}
