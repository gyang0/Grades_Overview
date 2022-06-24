#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    // File
    fstream file;
    
    char again = 'Y';
    
    file.open("grades.txt");
        if(file.fail())
        {
            cout << "Failed to open file.";
            exit(1);
        }
    
    
    
    do
    {
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
        
        string courseID, courseName,
               line;
        int gradeAverage, gradeTaken;
        
        
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
                while(gradeAverage < 0 || gradeAverage > 100)
                {
                    cout << "Again: ";
                    cin >> gradeAverage;
                }
                
                cout << "Enter your grade when you took this course: ";
                cin >> gradeTaken;
                while(gradeTaken < 7 || gradeTaken > 12)
                {
                    cout << "Again: ";
                    cin >> gradeTaken;
                }
                
                // Echo back
                cout << "\nAdded " << courseName << " (" << courseID << ") with a GPA of "
                     << gradeAverage << " to grade " << gradeTaken;
                
                // Write to file
                file << gradeTaken << " " << gradeAverage << "                 [" << courseID << "] " << courseName << "\n";
                
            break;
            
            case 2:
                // Delete a course
                
                
            break;
            
            case 3:
                for(int i = 7; i <= 12; i++)
                {
                    cout << i << "th grade\n";
                    cout << "Grade               Course\n";
                    
                    while(getline(file, line))
                    {
                        for(int j = 2; j < line.length(); j++)
                            cout << line[j];
                        
                        cout << "\n";
                    }
                    
                    cout << "\n";
                }
                
                
            break;
        }
        
        
        cout << "\nAgain? (Y/N)\n";
        cin >> again;
        
        
    } while(again == 'Y' || again == 'y');
    
    
    file.close();
    
    
    return 0;
}
