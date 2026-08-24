# CGPA Calculator — CodeAlpha Internship

A **C++ OOP-based CGPA Calculator** developed as **Task 1 of my CodeAlpha Internship**.

The project calculates semester-wise SGPA and overall CGPA using course grades and credit hours. I built it while practicing C++ fundamentals and Object-Oriented Programming concepts.

## 📌 Internship Task

**Program:** CodeAlpha Internship
**Task:** Task 1 — CGPA Calculator
**Language:** C++
**Concept:** Object-Oriented Programming (OOP)

## About the Project

This project allows a student to enter the number of semesters, courses, grades, and credit hours. The program automatically converts each grade into its corresponding grade point and calculates the semester SGPA and overall CGPA.

The calculation is credit-weighted, so courses with different credit hours are handled correctly.

## ✨ Features

* Semester-wise SGPA calculation
* Overall CGPA calculation
* Multiple semesters and courses
* Grade entered as a letter (`O`, `A+`, `A`, etc.)
* Automatic grade-to-point conversion
* Credit-weighted SGPA calculation
* Input validation and error handling
* Object-Oriented Programming structure
* Clean and modular C++ code

## 🎓 IKGPTU Grading System

The grade-point conversion used in this project follows the grading system implemented for **IKG Punjab Technical University (IKGPTU)**:

| Grade | Grade Point |
| ----- | ----------- |
| O     | 10          |
| A+    | 9           |
| A     | 8           |
| B+    | 7           |
| B     | 6           |
| C     | 5           |
| P     | 4           |

The program accepts the grade as a string and automatically converts it into the corresponding grade point.

For example:

```text
O  → 10
A+ → 9
A  → 8
B+ → 7
B  → 6
C  → 5
P  → 4
```

## 🧮 How the Calculation Works

For every course, the program calculates:

```text
Weighted Points = Grade Point × Credit Hours
```

Then the semester SGPA is:

```text
SGPA = Total Weighted Points / Total Credit Hours
```

For multiple semesters, the program combines the weighted points and credits from all semesters:

```text
CGPA = Overall Weighted Points / Overall Credit Hours
```

This ensures that the CGPA remains credit-weighted even when different semesters have different total credit hours.

## 🛡️ Input Validation

The program handles common invalid inputs such as:

* Invalid number of semesters
* Invalid number of courses
* Unsupported grades
* Negative or zero credit hours
* Non-numeric input where numeric values are expected

The user is asked to enter the value again instead of the program terminating unexpectedly.

## 🧠 OOP Concepts Used

This project was also an opportunity to apply the following C++ OOP concepts:

* **Class** — `SGPACalculator`
* **Objects** — Used to process individual semesters
* **Encapsulation** — Internal calculation data is kept private
* **Constructors** — Used to initialize object data
* **Member Functions** — Used for input, calculation, and result handling

## 🛠️ Technologies Used

* C++
* Object-Oriented Programming
* C++ Standard Library
* VS Code
* Git & GitHub

## ▶️ How to Run

Clone the repository:

```bash
git clone <your-repository-link>
```

Open the project in VS Code and compile:

```bash
g++ main.cpp -o cgpa
```

Run the program:

```bash
cgpa
```

## 📈 Future Improvements

I plan to improve the project further by adding:

* GUI interface
* Semester-wise result history
* File-based result storage
* Support for additional grading systems
* Better user interface and navigation

## 👨‍💻 About

This project was developed as part of my **CodeAlpha Internship** while learning and strengthening my C++ and OOP skills.

**Prince Sah**
B.Tech CSE Student

---

⭐ Built as part of the CodeAlpha Internship — Task 1.
