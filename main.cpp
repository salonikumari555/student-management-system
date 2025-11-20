#include <iostream>
#include "StudentManager.h"
using namespace std;

int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.displayStudents(); break;
            case 3: manager.searchStudent(); break;
            case 4: manager.updateStudent(); break;
            case 5: manager.deleteStudent(); break;
            case 6: 
                cout << "Exiting..."; 
                exit(0);

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
