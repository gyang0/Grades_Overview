#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include "course.h"
#include "funcs.h"
#include "exam.h"

// Courses taken
std::vector<Course> courseload;

// Exams taken
std::vector<Exam> exams;


Course getCourseFromStr(std::string str){
    char status;
    int gradeTaken;
    std::pair<double, double> score;
    std::string courseCode;
    std::string courseName;

    std::string cur = "";
    int dataNum = 0;
    for(char c : str){
        if(c == ' ' && dataNum <= 4){
            if(dataNum == 0) status = cur[0];
            else if(dataNum == 1) gradeTaken = std::stoi(cur);
            else if(dataNum == 2) score.first = std::stoi(cur);
            else if(dataNum == 3) score.second = std::stoi(cur);
            else if(dataNum == 4) courseCode = cur;

            cur = "";
            dataNum++;
        } else {
            cur += c;
        }
    }

    // Course name
    courseName = cur;

    return Course(status, gradeTaken, courseCode, courseName, score);
}

Exam getExamFromStr(std::string str){
    char status;
    int gradeTaken;
    std::string date;
    int score;
    std::string examName;

    std::string cur = "";
    int dataNum = 0;
    for(char c : str){
        if(c == ' ' && dataNum <= 3){
            if(dataNum == 0) status = cur[0];
            else if(dataNum == 1) gradeTaken = std::stoi(cur);
            else if(dataNum == 2) date = cur;
            else if(dataNum == 3) score = std::stoi(cur);

            cur = "";
            dataNum++;
        } else {
            cur += c;
        }
    }

    // Exam name
    examName = cur;

    return Exam(status, gradeTaken, date, score, examName);
}

/**
 * Reads from grades.txt and updates the courseload & exams vectors with specified courses.
 * 
 * Data is stored in the following form:
 *  School courses:   S [GRADE TAKEN] [SEMESTER 1 SCORE] [SEMSTER 2 SCORE] [COURSE CODE] [COURSE NAME]
 *  External courses: E [GRADE TAKEN] [SEMESTER 1 SCORE] [SEMSTER 2 SCORE] [COURSE CODE] [COURSE NAME]
 *  Quizzes:          Q [GRADE TAKEN] [YYYY/MM/DD] [SCORE] [EXAM NAME]
 */ 
void updateData(){
    courseload = {};
    exams = {};

    std::ifstream file("grades.txt");
    std::string line;

    int index = 0;
    while(getline(file, line)){
        // Ignore blank lines
        if(line.length() == 0)
            continue;

        if(line[0] == 'Q') exams.push_back(getExamFromStr(line));
        else courseload.push_back(getCourseFromStr(line));
    }

    file.close();
}


/**
 * Replaces the relevant lines in grades.txt for a specific course with blanks.
 * The blanks are skipped over by the updateData method when reading.
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
            updateData();

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
                updateData();

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
const int TOTAL_COURSE_SPACE = COURSE_ID_SPACE + COURSE_NAME_SPACE + 2*SEM_SCORE_SPACE + 5;

#define DATE_SPACE 13
#define EXAM_SCORE_SPACE 8
#define EXAM_NAME_SPACE 28
const int TOTAL_EXAM_SPACE = DATE_SPACE + EXAM_SCORE_SPACE + EXAM_NAME_SPACE + 5;

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

bool courseExists(int grade){
    for(Course course : courseload){
        if(course.getGradeTaken() == grade)
            return true;
    }
    return false;
}

bool examExists(int grade){
    for(Exam exam : exams){
        if(exam.getGradeTaken() == grade)
            return true;
    }
    return false;
}

void displayCourse(Course course){
    // Course ID and name
    std::cout << "| ";
    std::cout << centerText(course.getCourseCode(), COURSE_ID_SPACE) << "|";
    std::cout << leftText(course.getCourseName(), COURSE_NAME_SPACE, 3) << "|";
    
    // Grade not applicable for semester 1
    if(course.getScore().first == -1){
        std::cout << centerText("N/A", SEM_SCORE_SPACE) << "|";
    } else {
        std::cout << centerText(std::to_string(course.getScore().first), SEM_SCORE_SPACE) << "|";
    }

    // Grade not applicable for semester 2
    if(course.getScore().second == -1){
        std::cout << centerText("N/A", SEM_SCORE_SPACE) << "|";
    } else {
        std::cout << centerText(std::to_string(course.getScore().second), SEM_SCORE_SPACE) << "|";
    }

    std::cout << "\n";
}

void displayExam(Exam exam){
    // Course ID and name
    std::cout << "| ";
    std::cout << leftText(exam.getDate(), DATE_SPACE, 1) << "|";
    std::cout << leftText(exam.getExamName(), EXAM_NAME_SPACE, 3) << "|";
    std::cout << centerText(std::to_string(exam.getScore()), EXAM_SCORE_SPACE) << "|\n";
}

void showCourseOverview(int grade){
    if(!courseExists(grade))
        return;

    std::cout << " " << std::string(20, '-') << "\n";
    std::cout << "|" << (grade < 10 ? "  " : " ") << grade << "th Grade Courses |\n";
        
    std::cout << "|" << std::string(TOTAL_COURSE_SPACE - 1, '-') << "\n";

    std::cout << "| ";
    std::cout << centerText("Course ID", COURSE_ID_SPACE) << "|";
    std::cout << centerText("Course Name", COURSE_NAME_SPACE) << "|";
    std::cout << centerText("S1", SEM_SCORE_SPACE) << "|";
    std::cout << centerText("S2", SEM_SCORE_SPACE) << "|\n";

    std::cout << "|" << std::string(TOTAL_COURSE_SPACE - 1, '-') << "|\n";


    // School courses
    for(Course course : courseload){
        if(course.getGradeTaken() == grade && course.getStatus() == 'S')
            displayCourse(course);
    }
    std::cout << "|" << std::string(TOTAL_COURSE_SPACE - 1, '-') << "|\n";

    // External courses
    for(Course course : courseload){
        if(course.getGradeTaken() == grade && course.getStatus() == 'E')
            displayCourse(course);
    }
    std::cout << "|" << std::string(TOTAL_COURSE_SPACE - 1, '=') << "|\n";
    

    // Get average
    double gradeSum = 0.0;
    int numGrades = 0;

    for(Course course : courseload){
        if(course.getGradeTaken() == grade){
            if(course.getScore().first != -1){
                gradeSum += course.getScore().first;
                numGrades++;
            }
            if(course.getScore().second != -1){
                gradeSum += course.getScore().second;
                numGrades++;
            }
        }
    }

    if(numGrades == 0)
        std::cout << "|" << leftText("Average: N/A", TOTAL_COURSE_SPACE - 1, 1) << "|\n";
    else
        std::cout << "|" << leftText("Average: " + std::to_string(gradeSum/numGrades) + "%", TOTAL_COURSE_SPACE - 1, 1) << "|\n";
    
    std::cout << " " << std::string(TOTAL_COURSE_SPACE - 1, '-') << "\n\n";
}

void showExamOverview(int grade){
    if(!examExists(grade))
        return;

    std::cout << " " << std::string(18, '-') << "\n";
    std::cout << "|" << (grade < 10 ? "  " : " ") << grade << "th Grade Exams |\n";

    std::cout << "|" << std::string(TOTAL_EXAM_SPACE - 1, '-') << "\n";

    std::cout << "| ";
    std::cout << centerText("Date Taken", DATE_SPACE) << "|";
    std::cout << centerText("Exam Name", EXAM_NAME_SPACE) << "|";
    std::cout << centerText("Score", EXAM_SCORE_SPACE) << "|\n";

    std::cout << "|" << std::string(TOTAL_EXAM_SPACE - 2, '-') << "|\n";


    // Display exams
    for(Exam exam : exams){
        if(exam.getGradeTaken() == grade)
            displayExam(exam);
    }
    
    std::cout << " " << std::string(TOTAL_EXAM_SPACE - 2, '-') << "\n\n";
}

/**
 * Submenu for showing the overview of courses for different grades
 * Nothing too fancy, just some tables and average grade reports.
 */ 
void showOverview(){
    // Show courses taken for every grade
    for(int grade = 8; grade <= 12; grade++){
        if(!courseExists(grade) && !examExists(grade))
            continue;

        showCourseOverview(grade);
        showExamOverview(grade);

        std::cout << "\n\n";
    }

    // Options
    int choice;
    std::cout << "Enter 0 to go back to menu and 1 to quit.\n";
    std::cin >> choice;

    if(choice == 1){
        std::cout << "\n\nClosing program...\n";
        exit(0);
    }

    std::cout << "\n\n";
}
