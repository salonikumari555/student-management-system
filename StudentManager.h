#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <fstream>
#include <vector>

class StudentManager {
private:
    vector<Student> students;
    string filename = "students.txt";

public:
    StudentManager() {
        loadFromFile();
    }

    // Load data from file
    void loadFromFile() {
        ifstream file(filename);
        if (!file) return;

        int roll, age;
        string name, course;

        while (file >> roll >> name >> age >> course) {
            students.push_back(Student(roll, name, age, course));
        }
        file.close();
    }

    // Save to file
    void saveToFile() {
        ofstream file(filename);
        for (auto &s : students) {
            file << s.getRoll() << " "
                 << s.getName() << " "
                 << s.getAge() << " "
                 << s.getCourse() << endl;
        }
        file.close();
    }

    // Add student
    void addStudent() {
        int roll, age;
        string name, course;

        cout << "Enter Roll: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Course: ";
        cin >> course;

        students.push_back(Student(roll, name, age, course));
        saveToFile();
        cout << "Student added successfully.\n";
    }

    // Display all students
    void displayStudents() {
        for (auto &s : students) {
            s.displayStudent();
        }
    }

    // Search student
    void searchStudent() {
        int roll;
        cout << "Enter Roll to search: ";
        cin >> roll;

        for (auto &s : students) {
            if (s.getRoll() == roll) {
                s.displayStudent();
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Update student
    void updateStudent() {
        int roll;
        cout << "Enter Roll to update: ";
        cin >> roll;

        for (auto &s : students) {
            if (s.getRoll() == roll) {
                string name, course;
                int age;

                cout << "Enter New Name: ";
                cin >> name;
                cout << "Enter New Age: ";
                cin >> age;
                cout << "Enter New Course: ";
                cin >> course;

                s.setName(name);
                s.setAge(age);
                s.setCourse(course);

                saveToFile();
                cout << "Student updated.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Delete student
    void deleteStudent() {
        int roll;
        cout << "Enter Roll to delete: ";
        cin >> roll;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getRoll() == roll) {
                students.erase(students.begin() + i);
                saveToFile();
                cout << "Student deleted.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

#endif
