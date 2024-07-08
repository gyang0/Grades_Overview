/* TODO
6. Test adding/deleting courses

Organize helper functions better (funcs.cpp)
Comment methods (& revise outdated ones)
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "funcs.cpp"
#include "course.cpp"
#include "exam.cpp"
using namespace std;


int main(){
    // Main loop
    do {
        // Check for new data
        updateData();

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