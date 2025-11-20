#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    string name;
    int age;
    string course;

public:
    Student() {}
    Student(int r, string n, int a, string c) {
        roll = r;
        name = n;
        age = a;
        course = c;
    }

    // Setters
    void setRoll(int r) { roll = r; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setCourse(string c) { course = c; }

    // Getters
    int getRoll() { return roll; }
    string getName() { return name; }
    int getAge() { return age; }
    string getCourse() { return course; }

    // Display student info
    void displayStudent() {
        cout << "Roll: " << roll 
             << " | Name: " << name 
             << " | Age: " << age 
             << " | Course: " << course 
             << endl;
    }
};

#endif
