#include <iostream>
#include <string>
#include <limits>
using namespace std;

class SGPACalculator {
private:
    int courses;
    string grades[50];
    float credits[50];

    float totalPoints;
    float totalCredits;

    // Convert grade to grade point
    //according to my Universityy (IKG PTU)
    float getGradePoint(string grade) {
        if (grade == "O")
            return 10;
        else if (grade == "A+")
            return 9;
        else if (grade == "A")
            return 8;
        else if (grade == "B+")
            return 7;
        else if (grade == "B")
            return 6;
        else if (grade == "C")
            return 5;
        else if (grade == "P")
            return 4;
        else
            return -1;
    }

public:
    SGPACalculator() {
        courses = 0;
        totalPoints = 0;
        totalCredits = 0;
    }

    void inputCourses() {
        while (true) {
            cout << "Enter number of courses: ";
            cin >> courses;

            if (cin.fail()) {
                cout << "Invalid input. Please enter a number.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (courses <= 0 || courses > 50) {
                cout << "Number of courses should be between 1 and 50.\n";
                continue;
            }

            break;
        }
    }

    void inputGradesAndCredits() {
        for (int i = 0; i < courses; i++) {

            // Get grade
            while (true) {
                cout << "\nEnter grade for Course " << i + 1 << ": ";
                cin >> grades[i];

                if (getGradePoint(grades[i]) == -1) {
                    cout << "Invalid grade. Use O, A+, A, B+, B, C or P.\n";
                    continue;
                }

                break;
            }

            // Get credit hours
            while (true) {
                cout << "Enter credit hours for Course "
                     << i + 1 << ": ";
                cin >> credits[i];

                if (cin.fail()) {
                    cout << "Invalid input. Please enter a number.\n";

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (credits[i] <= 0) {
                    cout << "Credit hours must be greater than 0.\n";
                    continue;
                }

                break;
            }
        }
    }

    float calculateSGPA() {
        totalPoints = 0;
        totalCredits = 0;

        for (int i = 0; i < courses; i++) {
            float gradePoint = getGradePoint(grades[i]);

            totalPoints += gradePoint * credits[i];
            totalCredits += credits[i];
        }

        return totalPoints / totalCredits;
    }

    float getTotalPoints() {
        return totalPoints;
    }

    float getTotalCredits() {
        return totalCredits;
    }

    void showResult(float sgpa) {
        cout << "\n-----------------------------\n";
        cout << "Total Credits   : " << totalCredits << endl;
        cout << "Weighted Points : " << totalPoints << endl;
        cout << "SGPA            : " << sgpa << endl;
        cout << "-----------------------------\n";
    }
};

int main() {
    int semesters;

    cout << "================================\n";
    cout << "       CGPA CALCULATOR\n";
    cout << "================================\n";

    // Number of semesters
    while (true) {
        cout << "\nEnter number of semesters: ";
        cin >> semesters;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (semesters <= 0) {
            cout << "Number of semesters must be greater than 0.\n";
            continue;
        }

        break;
    }

    float overallPoints = 0;
    float overallCredits = 0;

    // Calculate SGPA for each semester
    for (int i = 0; i < semesters; i++) {
        cout << "\n================================\n";
        cout << "           SEMESTER " << i + 1 << endl;
        cout << "================================\n";

        SGPACalculator semester;

        semester.inputCourses();
        semester.inputGradesAndCredits();

        float sgpa = semester.calculateSGPA();

        semester.showResult(sgpa);

        overallPoints += semester.getTotalPoints();
        overallCredits += semester.getTotalCredits();
    }

    // Final CGPA
    float cgpa = overallPoints / overallCredits;

    cout << "\n================================\n";
    cout << "          FINAL RESULT\n";
    cout << "================================\n";

    cout << "Total Credits : " << overallCredits << endl;
    cout << "Overall CGPA  : " << cgpa << endl;

    cout << "================================\n";

    return 0;
}