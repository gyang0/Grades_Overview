#include <iostream>
#include <fstream>
#include <cstdlib>
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
        
        
        string line;
        
        switch(choice)
        {
            case 1:
                addCourse();
            break;
            
            case 2:
                // Delete a course
                
                
            break;
            
            case 3:
                int grade = 0;
                int count = 0;
                int word;
                
                
                for(int i = 7; i <= 12; i++)
                {
                    // Open file
                    file.open("grades.txt");
                    
                    cout << i << "th grade\n";
                    cout << "Grade               Course\n";
                    
                    
                    while(getline(file, line))
                    {
                        if(line[1] == ' ')
                            grade = ((int)line[0] - 48);
                        else
                            grade = ((int)line[0] - 48) * 10 + ((int)line[1] - 48);
                        
                        
                        if(grade == i)
                        {
                            cout << "  ";
                            for(int j = 2; j < line.length(); j++)
                                cout << line[j];
                        
                            cout << "\n";
                        }
                        
                    }
                    
                    
                    cout << "\n";
                    
                    // Close file
                    file.close();
                }
                
            break;
        }
        
        
        cout << "\nAgain? (Y/N)\n";
        cin >> again;
        
        
    } while(again == 'Y' || again == 'y');
    
    
    return 0;
}
