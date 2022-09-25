#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "funcs.h"
using namespace std;

int main()
{
    
    // File
    fstream file;
    
    char again = 'Y';
    
    // Check if file opens
    file.open("grades.txt");
    if(file.fail())
    {
        cout << "Failed to open file.";
        exit(1);
    }
    file.close();
    
    
    
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
        
        
        switch(choice)
        {
            case 1:
                addCourse();
            break;
            
            case 2:
                deleteCourse();
            break;
            
            case 3:
                showOverview();
                
            break;
        }
        
        
        cout << "\nAgain? (Y/N)\n";
        cin >> again;
        
        
    } while(again == 'Y' || again == 'y');
    
    
    
    return 0;
}
