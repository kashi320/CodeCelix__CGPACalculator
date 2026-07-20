#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Course {
    string name;
    double gradePoint;
    int credits;
};

int main() {
    int numCourses;
    double totalGradePoints = 0;
    int totalCredits = 0;

    cout << "--- CGPA Calculator ---" << endl;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << "\nCourse " << i + 1 << " Name: ";
        cin >> courses[i].name;
        
        cout << "Enter Grade Points (4.0, 3.0, etc.): ";
        cin >> courses[i].gradePoint;
        
        cout << "Enter Credit Hours: ";
        cin >> courses[i].credits;

        totalGradePoints += (courses[i].gradePoint * courses[i].credits);
        totalCredits += courses[i].credits;
    }

    // Display Results
    cout << "\n" << setw(15) << "Course" << setw(10) << "Grade" << setw(10) << "Credits" << endl;
    cout << "------------------------------------------" << endl;
    
    for (const auto& c : courses) {
        cout << setw(15) << c.name 
             << setw(10) << c.gradePoint 
             << setw(10) << c.credits << endl;
    }

    double cgpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0;

    cout << "\n------------------------------------------" << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Final CGPA: " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}