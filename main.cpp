/* TODO
1. Add semester grades
2. Add stuff for external institution courses
3. More compact data storage
4. Exam scores and such

Less hardcoded values for overview table spacing
Organize helper functions better (funcs.cpp)
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "funcs.cpp"
#include "course.cpp"
using namespace std;


int main(){
    // Main loop
    do {
        // Check for any updates of courses
        updateCourseload();


        int choice = 0;
        
        cout << " __________________________\n";
        cout << "|                           |\n";
        cout << "|  Academic Scores Record   |\n";
        cout << "|                           |\n";
        cout << "----------------------------\n";
        cout << "This is a program to help keep track of your academic scores.\n\n";
        cout << "Enter one of the following choices:\n";
        cout << "   1. Add a new course\n";
        cout << "   2. Delete a course\n";
        cout << "   3. See overview\n";
        cout << "   4. Quit program" << endl;
        
        cin >> choice;
        cout << endl;
        
        switch(choice){
        case 1:
            addCourse();
            break;
        case 2:
            deleteCourse();
            break;
        case 3:
            showOverview();
            break;
        case 4:
            cout << "\n\nClosing program...\n";
            exit(0);
            break;
        default:
            while(choice < 0 || choice > 4){
                cout << "Please try again with a number between 1 and 4: \n";
                cin >> choice;
            }
        }
        
    } while(true);
    
    
    return 0;
}