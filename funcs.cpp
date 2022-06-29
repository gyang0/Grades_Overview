#include <iostream>
#include <fstream>
#include "funcs.h"


std::string numberToLetter(int grade)
{
    if(grade >= 93) return "A";
    else if(grade >= 90) return "A-";
    else if(grade >= 87) return "B+";
    else if(grade >= 83) return "B";
    else if(grade >= 80) return "B-";
    else if(grade >= 77) return "C+";
    else if(grade >= 73) return "C";
    else if(grade >= 70) return "C-";
    else if(grade >= 67) return "D+";
    else if(grade >= 63) return "D";
    else if(grade >= 60) return "D-";
    else return "F";
}


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
    outputFile << gradeTaken << " "
               << " [" << courseID << "] " << courseName << "                             "
               << numberToLetter(gradeAverage) << " (" << gradeAverage << ")\n";
    
    
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
                if(line[line.length() - 3] == '(')
                    sumGrades += (line[line.length() - 2] - 48) * 10;
                
                // Two digits
                else if(line[line.length() - 4] == '(')
                    sumGrades += ((line[line.length() - 3] - 48) * 10
                                  + (line[line.length() - 2] - 48));
                // Three digits
                else
                    sumGrades += ((line[line.length() - 4] - 48) * 100
                                  + (line[line.length() - 3] - 48) * 10
                                  + (line[line.length() - 2] - 48));
                
                
                std::cout << "  ";
                for(int j = 2; j < line.length(); j++)
                    std::cout << line[j];
                    
                std::cout << "\n";
            }
            
        }
        
        if(numCourses > 0)
            std::cout << "Average grade: " << numberToLetter(sumGrades/numCourses) << " (" << (sumGrades/numCourses) << ")\n";
        else
            std::cout << "No data\n";
        
        std::cout << "\n";
        
        // Close file
        file.close();
        
    }
    
}
