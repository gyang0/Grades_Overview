#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include "course.h"
#include "funcs.h"

// How many lines of data there is in grades.txt per course
#define LINES_PER_COURSE 4

// Courses taken
std::vector<Course> courseload;


void updateCourseload(){
    courseload = {};

    std::ifstream file("grades.txt");
    std::string line;

    int index = 0;
    Course toAdd(0, "00000", "TITLE", 0);

    while(getline(file, line)){
        // do something with the lines
        if(index == 0) toAdd.setGradeTaken(std::stoi(line));
        else if(index == 1) toAdd.setCourseCode(line);
        else if(index == 2) toAdd.setCourseName(line);
        else if(index == 3) toAdd.setScore(std::stoi(line));

        // Loop for every 4 lines of the file
        index++;
        
        if(index >= LINES_PER_COURSE){
            courseload.push_back(toAdd);
            index = 0;
        }
    }

    file.close();
}

/**
 * Converts a numeric grade to its letter grade.
 * 
 * @param grade - The numeric grade
 * @return - The letter grade from F to A
 */
std::string numberToLetter(int grade){
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

void addCourse(){
    int anotherCourse = 0;
    do {
        std::cout << "---Add Courses---------------\n";

        
        int gradeTaken;
        std::string courseCode;
        std::string courseName;
        double score;


        int choice = 0;

        do {
            // Inputs
            std::cout << "Grade when you took the course: ";
            std::cin >> gradeTaken;

            std::cout << "Course code: ";
            std::cin >> courseCode;

            std::cout << "Course name: ";
            std::cin.ignore();
            std::getline(std::cin, courseName);

            std::cout << "Numeric score you received in this course: ";
            std::cin >> score;

            std::cout << "\nA course will be added with the following information:\n";
            std::cout << "   Grade taken: " << gradeTaken << "\n";
            std::cout << "   Course code: " << courseCode << "\n";
            std::cout << "   Course name: " << courseName << "\n";
            std::cout << "   Numeric score received: " << score << "\n\n";
            std::cout << "Enter 0 to proceed, 1 to edit this information, and 2 to quit: ";

            std::cin >> choice;
            std::cout << "\n";

        } while(choice == 1 || choice == 1);


        // Choice 0: proceed
        if(choice == 0){
            // Add data to file
            std::ofstream file("grades.txt", std::ios_base::app);
            file << gradeTaken << "\n";
            file << courseCode << "\n";
            file << courseName << "\n";
            file << score << "\n";
            file.close();

            std::cout << "The course has been added. Would you like to add another course?\n";
            std::cout << "Enter 0 to add another course, 1 to return to menu, and 2 to quit: ";
            std::cin >> anotherCourse;
            std::cout << "\n\n";

        } else if(choice == 2){
            std::cout << "\n\nClosing program...\n";
            exit(0);
        }

        if(anotherCourse == 2){
            std::cout << "\n\nClosing program...\n";
            exit(0);
        }

    } while (anotherCourse == 0);

    std::cout << "\n\n";
}

void deleteCourse(){
    std::cout << "---Delete courses------------\n";
}

/*

9 [OCS15] AP Computer Science A                                            A (100)
9 [OE010] Honors Textual Analysis and Argumentation                        A (96)
9 [OM4BC] AP Calculus BC                                                   A (98)
9 [OMSB9] Methodology of Science - Biology                                 A (100)
9 [OHSWP] Wellness I
9 [OE10WL] Textual Analysis and Argumentation Writing Lab
*/


void showOverview(){
    // Show courses taken for every grade
    for(int grade = 8; grade <= 12; grade++){
        std::cout << "---" << (grade < 10 ? " " : "") << grade << "th Grade Courses---------\n";

        double gradeSum = 0.0;
        int numCourses = 0;

        for(Course course : courseload){
            if(course.getGradeTaken() == grade){
                // Margins
                std::cout << std::fixed << std::setprecision(2) << std::setw(10);
                
                if(course.getScore() == -1)
                    std::cout << "N/A" << " ";
                else {
                    std::cout << course.getScore() << "%";
                    gradeSum += course.getScore();
                    numCourses++;
                }
                
                std::cout << " | [" << course.getCourseCode() << "] " << course.getCourseName() << "\n";
            }
        }

        if(numCourses == 0){
            std::cout << "[NO DATA]\n";
        } else {
            std::cout << "\nAverage: " << gradeSum/numCourses << "%\n";
        }
        
        std::cout << "\n";
    }

    // Options
    int choice;
    std::cout << "\nEnter 0 to go back to menu and 1 to quit.\n";
    std::cin >> choice;

    if(choice == 1){
        std::cout << "\n\nClosing program...\n";
        exit(0);
    }

    std::cout << "\n\n";
}
