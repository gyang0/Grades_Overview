#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include "course.h"
#include "funcs.h"

// Courses taken
std::vector<Course> courseload;


Course getCourseFromStr(std::string str){
    int gradeTaken;
    std::pair<double, double> score;
    std::string courseCode;
    std::string courseName;

    std::string cur = "";
    int dataNum = 0;
    for(char c : str){
        if(c == ' ' && dataNum <= 3){
            if(dataNum == 0) gradeTaken = std::stoi(cur);
            else if(dataNum == 1) score.first = std::stoi(cur);
            else if(dataNum == 2) score.second = std::stoi(cur);
            else if(dataNum == 3) courseCode = cur;

            cur = "";
            dataNum++;
        } else {
            cur += c;
        }
    }

    // Course name
    courseName = cur;

    return Course(gradeTaken, courseCode, courseName, score);
}

/**
 * Reads from grades.txt and updates the courseload vector with specified courses.
 * 
 * There are 4 lines of data associated with a class.
 * To change, fix LINES_PER_COURSE defined above.
 * 
 * Courses are stored in the following form:
 *  [GRADE TAKEN] [SEMESTER 1 SCORE] [SEMSTER 2 SCORE] [COURSE CODE] [COURSE NAME]
 */ 
void updateCourseload(){
    courseload = {};

    std::ifstream file("grades.txt");
    std::string line;

    int gradeTaken;
    std::pair<double, double> score;
    std::string courseCode;
    std::string courseName;

    int index = 0;
    while(getline(file, line)){
        // Ignore blank lines
        if(line.length() == 0)
            continue;

        // New course to add
        courseload.push_back(getCourseFromStr(line));
    }

    file.close();
}


/**
 * Replaces the relevant lines in grades.txt for a specific course with blanks.
 * The blanks are skipped over by the updateCourseload method when reading.
 * 
 * @params fileName - String name of the file
 * @params courseCode - String course code of the file
 */ 
void eraseCourseData(std::string fileName, std::string courseCode){
    // First, the contents of the old file except for the erased course are stored in a string.
    std::ifstream readFile("grades.txt");
    std::string newFile = "";

    
    std::string line;
    int index = 0;
    while(getline(readFile, line)){
        // Ignore blank lines
        if(line.length() == 0)
            continue;
        
        Course test = getCourseFromStr(line);
        if(test.getCourseCode() != courseCode)
            newFile += line;
    }

    readFile.close();


    // Then rewrite the file with the new contents.
    std::ofstream writeFile("grades.txt");
    writeFile << newFile;
    writeFile.close();
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


/**
 * Submenu for adding courses
 * Takes the data associated with a course and adds it to the file.
 * The courseload vector is updated as well.
 */ 
void addCourse(){
    int anotherCourse = 0;
    do {
        std::cout << "---Add Courses---------------\n";
        
        int gradeTaken;
        std::string courseCode;
        std::string courseName;
        std::pair<int, int> score;

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

            std::cout << "Semester 1 score: ";
            std::cin >> score.first;

            std::cout << "Semester 2 score: ";
            std::cin >> score.second;

            std::cout << "\nA course will be added with the following information:\n";
            std::cout << "   Grade taken: " << gradeTaken << "\n";
            std::cout << "   Course code: " << courseCode << "\n";
            std::cout << "   Course name: " << courseName << "\n";
            std::cout << "   Semester scores: " << score.first << ", " << score.second << "\n\n";
            std::cout << "Enter 0 to proceed, 1 to edit this information, and 2 to return to menu: ";

            std::cin >> choice;
            std::cout << "\n";

        } while(choice == 1 || choice == 1);


        // Choice 0: proceed
        if(choice == 0){
            // Add data to file
            std::ofstream file("grades.txt", std::ios_base::app);
            file << gradeTaken << " " << score.first << " " << score.second << " " << courseCode << " " << courseName << "\n";
            file.close();

            // Update courseload vector (just in case)
            updateCourseload();

            std::cout << "The course has been added. Would you like to add another course?\n";
            std::cout << "Enter 0 to add another course and 1 to return to menu: ";
            std::cin >> anotherCourse;
            std::cout << "\n\n";

        } else if(choice == 2){
            return;
        }

    } while (anotherCourse == 0);

    std::cout << "\n\n";
}


/**
 * Submenu for deleting courses
 * Takes the course code, checks if it exists, and deletes the course.
 * 
 * Both the courseload vector and the file are changed. For the file,
 * relevant lines are replaced with blank lines, which are skipped over
 * by the program.
 */ 
void deleteCourse(){
    std::cout << "---Delete courses------------\n";

    // Delete more courses
    int choice = -1;
    do {

        choice = -1;

        // Edit information
        int editInfo = -1;

        // Delete more courses
        int deleteMore = -1;

        do {

            editInfo = -1;
            deleteMore = -1;
            
            std::string courseCode;
            std::cout << "Enter the course code of the course you wish to delete: ";
            std::cin >> courseCode;

            std::cout << std::endl;

            // Find cours
            int courseIndex = -1;
            for(int i = 0; i < courseload.size(); i++){
                if(courseload[i].getCourseCode() == courseCode){
                    courseIndex = i;
                    break;
                }
            }

            
            if(courseIndex == -1){
                std::cout << "Error: could not find course associated with that course code.\n";
                std::cout << "Enter 0 to try again and 1 to return to menu: ";
                std::cin >> choice;
            } else {
                std::cout << "The following course will be deleted:\n";
                std::cout << "   Grade taken: " << courseload[courseIndex].getGradeTaken() << "\n";
                std::cout << "   Course code: " << courseload[courseIndex].getCourseCode() << "\n";
                std::cout << "   Course name: " << courseload[courseIndex].getCourseName() << "\n";
                std::cout << "   Semester scores: " << courseload[courseIndex].getScore().first << ", " << courseload[courseIndex].getScore().second << "\n\n";
                std::cout << "Enter 0 to proceed, 1 to edit this information, and 2 to return to menu: ";
                std::cin >> editInfo;
            }

            // Return to menu
            if(editInfo == 2)
                return;

            // Delete the course.
            else if(editInfo == 0){

                // Erase the course data in the file.
                eraseCourseData("grades.txt", courseCode);
                updateCourseload();

                std::cout << "\n\nCourse successfully deleted.\n\n";
                std::cout << "Enter 0 to delete another course and 1 to return to menu: ";
                std::cin >> deleteMore;

                std::cout << std::endl;
            }

        } while(editInfo == 1 || deleteMore == 0);

    } while(choice == 0);
}



// Spacings for table
#define COURSE_ID_SPACE 10
#define COURSE_NAME_SPACE 46
#define SEM_SCORE_SPACE 8
const int TOTAL_SPACE = COURSE_ID_SPACE + COURSE_NAME_SPACE + 2*SEM_SCORE_SPACE + 5;

std::string centerText(std::string toCenter, int containerSize){
    // May be off by 1 char for containers with odd # of characters
    int spacingsLeft = (containerSize - toCenter.size())/2;
    std::string l = std::string(spacingsLeft, ' ');
    std::string r = std::string(containerSize - spacingsLeft - toCenter.size(), ' ');

    return l + toCenter + r;
}

std::string leftText(std::string toCenter, int containerSize, int spacingsLeft){
    std::string l = std::string(spacingsLeft, ' ');
    std::string r = std::string(containerSize - toCenter.size() - spacingsLeft, ' ');

    return l + toCenter + r;
}

bool dataExists(int grade){
    for(Course course : courseload){
        if(course.getGradeTaken() == grade)
            return true;
    }
    return false;
}

/**
 * Submenu for showing the overview of courses for different grades
 * Nothing too fancy, just some tables and average grade reports.
 */ 
void showOverview(){
    // Show courses taken for every grade
    for(int grade = 8; grade <= 12; grade++){
        if(!dataExists(grade)){
            continue;
        }

        std::cout << " " << std::string(20, '-') << "\n";
        std::cout << "|" << (grade < 10 ? "  " : " ") << grade << "th Grade Courses |\n";
        //std::cout << "---" << (grade < 10 ? "- " : " ") << grade << "th Grade Courses ---------\n\n";
        
        std::cout << "|" << std::string(TOTAL_SPACE - 1, '-') << "\n";

        std::cout << "| ";
        std::cout << centerText("Course ID", COURSE_ID_SPACE) << "|";
        std::cout << centerText("Course Name", COURSE_NAME_SPACE) << "|";
        std::cout << centerText("S1", SEM_SCORE_SPACE) << "|";
        std::cout << centerText("S2", SEM_SCORE_SPACE) << "|\n";

        std::cout << "|" << std::string(TOTAL_SPACE - 1, '-') << "|\n";

        double gradeSum = 0.0;
        int numGrades = 0;

        for(Course course : courseload){
            if(course.getGradeTaken() == grade){
                // Course ID and name
                std::cout << "| ";
                std::cout << centerText(course.getCourseCode(), COURSE_ID_SPACE) << "|";
                std::cout << leftText(course.getCourseName(), COURSE_NAME_SPACE, 3) << "|";
                
                // Grade not applicable for semester 1
                if(course.getScore().first == -1){
                    std::cout << leftText("N/A", SEM_SCORE_SPACE, 2) << "|";
                } else {
                    std::cout << leftText(std::to_string(course.getScore().first), SEM_SCORE_SPACE, 2) << "|";
                    gradeSum += course.getScore().first;
                    
                    numGrades++;
                }

                // Grade not applicable for semester 2
                if(course.getScore().second == -1){
                    std::cout << leftText("N/A", SEM_SCORE_SPACE, 2) << "|";
                } else {
                    std::cout << leftText(std::to_string(course.getScore().second), SEM_SCORE_SPACE, 2) << "|";
                    gradeSum += course.getScore().second;
                    
                    numGrades++;
                }

                std::cout << "\n";

            }
        }
        std::cout << "|" << std::string(TOTAL_SPACE - 1, '-') << "|\n";
        
        if(numGrades == 0)
            std::cout << "|" << leftText("Average: N/A", TOTAL_SPACE - 1, 1) << "|\n";
        else
            std::cout << "|" << leftText("Average: " + std::to_string(gradeSum/numGrades) + "%", TOTAL_SPACE - 1, 1) << "|\n";
        
        std::cout << " " << std::string(TOTAL_SPACE - 1, '-') << "\n";
        
        std::cout << "\n\n";
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
