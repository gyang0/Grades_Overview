#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    // File
    fstream file;
    
    
    
    
    int choice = 0;
    
    cout << "Academic Scores\n";
    cout << "Pick one:\n";
    cout << "   1. Add a new course\n";
    cout << "   2. Delete a course\n";
    cout << "   3. See overview\n";
    
    cin >> choice;
    while(choice < 0 || choice > 3)
    {
        cout << "Try again: ";
        cin >> choice;
    }
    
    string courseID, courseName;
    int gradeAverage, gradeTaken;
    
    
    
    
    file.open("grades.txt");
    if(file.fail())
    {
        cout << "Failed to open file.";
        exit(1);
    }
    
    
    switch(choice)
    {
        case 1:
            // Add a course
            cout << "Enter the course ID: ";
            cin >> courseID;
            
            cin.ignore();
            cout << "Enter the course name: ";
            getline(cin, courseName);
            
            cout << "Enter your grade average: ";
            cin >> gradeAverage;
            
            cout << "Enter your grade when you took this course: ";
            cin >> gradeTaken;
            
            
            cout << "\nAdded " << courseName << " (" << courseID << ") with a GPA of "
                 << gradeAverage << " to grade " << gradeTaken;
            
            file << gradeTaken << " " << courseID << " " << gradeAverage << " " << courseName << "\n";
            
        break;
        
        case 2:
            // Delete a course
        break;
        
        case 3:
            // See overview
        break;
    }
    
    file.close();
    
    
    return 0;
}
