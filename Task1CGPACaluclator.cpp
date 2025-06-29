#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Course {
    string name;
    float grade;       // Grade out of 10.0
    int creditHours;
};

struct Semester {
    vector<Course> courses;
    float totalGradePoints = 0.0;
    int totalCredits = 0;
    float gpa = 0.0;

    void inputCourses(int semesterNumber) {
        int numCourses;
        cout << "\nEnter number of courses for Semester " << semesterNumber << ": ";
        cin >> numCourses;
        cin.ignore(); // To clear newline from input buffer

        courses.resize(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            cout << "\nCourse #" << i + 1 << ":\n";
            cout << "Course name: ";
            getline(cin, courses[i].name);

            cout << "Grade (out of 10): ";
            cin >> courses[i].grade;

            cout << "Credit hours: ";
            cin >> courses[i].creditHours;
            cin.ignore();

            totalGradePoints += courses[i].grade * courses[i].creditHours;
            totalCredits += courses[i].creditHours;
        }

        gpa = totalGradePoints / totalCredits;
    }

    void display(int semesterNumber) {
        cout << "\n--- Semester " << semesterNumber << " Courses ---\n";
        cout << left << setw(25) << "Course Name"
             << setw(10) << "Grade"
             << setw(15) << "Credit Hours" << endl;

        for (const auto& course : courses) {
            cout << left << setw(25) << course.name
                 << setw(10) << course.grade
                 << setw(15) << course.creditHours << endl;
        }

        cout << fixed << setprecision(2);
        cout << "Semester " << semesterNumber << " GPA: " << gpa << "\n";
    }
};

int main() {
    Semester sem1, sem2;

    cout << "=== CGPA Calculator for 2 Semesters (Scale: 10.0) ===\n";

    sem1.inputCourses(1);
    sem2.inputCourses(2);

    sem1.display(1);
    sem2.display(2);

    // Compute overall CGPA
    int totalCredits = sem1.totalCredits + sem2.totalCredits;
    float totalGradePoints = sem1.totalGradePoints + sem2.totalGradePoints;
    float cgpa = totalGradePoints / totalCredits;

    cout << "\n--- Overall CGPA ---\n";
    cout << "Total Credits (Both Semesters): " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Final CGPA: " << cgpa << " / 10.0\n";

    return 0;
}
