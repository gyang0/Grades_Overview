#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    // File
    fstream file;
    
    file.open("grades.txt");
    if(file.fail())
    {
        cout << "Failed to open file.";
        exit(1);
    }
    
    
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
            // Add a course
        break;
        
        case 2:
            // Delete a course
        break;
        
        case 3:
            // See overview
        break;
    }
    
    
    return 0;
}
