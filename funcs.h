#ifndef FUNCS_H
#define FUNCS_H

#include <string>

void updateCourseload();
// Reads from grades.txt and updates the list of courses accordingly.

std::string numberToLetter(int grade);
// Converts a number grade to a letter grade.

void addCourse();
// Adds a course to the file.

void deleteCourse();
// Deletes a course from the file.

void showOverview();
// Shows grade overview (courses, grade earned, average score, etc.).

#endif