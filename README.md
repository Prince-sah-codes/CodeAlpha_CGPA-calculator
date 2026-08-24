# CGPA Calculator

A simple **C++ based CGPA Calculator** that calculates semester SGPA and overall CGPA using course grades and credit hours.

I built this project to practice **C++ OOP concepts, arrays, loops, functions, input validation, and basic project structure** while working on a practical problem that students can actually use.

## Features

* Calculate SGPA for individual semesters
* Calculate overall CGPA for multiple semesters
* Enter grades as letters such as `A+`, `A`, `B+`, etc.
* Automatically convert grades into grade points
* Calculate SGPA using credit-weighted grade points
* Supports multiple courses in each semester
* Handles invalid grades and incorrect numeric inputs
* Validates course and credit-hour values
* Uses OOP concepts with a dedicated `SGPACalculator` class

## How It Works

For each semester, the program asks for:

1. Number of courses
2. Grade obtained in each course
3. Credit hours for each course

The program then converts the entered grade into its corresponding grade point and calculates:

```text
Weighted Points = Grade Point × Credit Hours
```

The semester SGPA is calculated using:

```text
SGPA = Total Weighted Points / Total Credit Hours
```

For multiple semesters, the program combines the weighted points and total credits from all semesters to calculate the overall CGPA:

```text
CGPA = Total Weighted Points of All Semesters
       ---------------------------------------
             Total Credits of All Semesters
```

This approach also handles semesters with different total credit hours correctly.

## Grading System

The calculator follows the grade-point conversion used by **IKG Punjab Technical University (IKGPTU)**:

| Grade | Grade Point |
| ----- | ----------- |
| O     | 10          |
| A+    | 9           |
| A     | 8           |
| B+    | 7           |
| B     | 6           |
| C     | 5           |
| P     | 4           |

The program takes the grade as a string and automatically converts it into the corresponding grade point before calculating the SGPA.

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

If an unsupported grade is entered, the program treats it as invalid and asks the user to enter a valid grade again.

> **Note:** The grading scale is implemented according to the IKGPTU grading scheme used for this project.


## OOP Concepts Used

This project uses basic Object-Oriented Programming concepts:

* **Class** — `SGPACalculator`
* **Object** — Each semester is handled using an object of the class
* **Encapsulation** — Course data and calculation logic are kept inside the class
* **Private members** — Store grades, credits, and calculation data
* **Public member functions** — Handle input, calculations, and results
* **Constructor** — Initializes the calculator's data

## Input Validation

The program also checks for common input mistakes, including:

* Invalid number of courses
* More than 50 courses
* Invalid grade names
* Negative or zero credit hours
* Non-numeric input where a number is expected

Instead of stopping the program, invalid input is rejected and the user is asked to enter it again.

## Example

```text
========================================
          CGPA CALCULATOR
========================================

Enter number of semesters: 2

========================================
              SEMESTER 1
========================================

Enter number of courses: 3

Enter grade for Course 1: A+
Enter credit hours for Course 1: 4

Enter grade for Course 2: A
Enter credit hours for Course 2: 3

Enter grade for Course 3: B+
Enter credit hours for Course 3: 3

----------------------------------
Total Credit Hours : 10
Weighted Points    : 92
SGPA               : 9.2
----------------------------------
```

The same process is repeated for the remaining semesters, after which the program displays the final CGPA.

## Technologies Used

* **C++**
* Object-Oriented Programming
* Arrays
* Loops
* Functions
* Input Validation
* Standard C++ Library

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/Prince-sah-codes/CodeAlpha_CGPA-calculator.git
```

### 2. Open the project

Open the project folder in **VS Code** or any C++ IDE.

### 3. Compile the program

Using g++:

```bash
g++ main.cpp -o cgpa
```

### 4. Run

On Windows:

```bash
cgpa
```

Or run the program directly through your C++ IDE.

## Future Improvements

Some improvements I would like to add in future versions:

* A graphical user interface
* Saving student results to a file
* Displaying complete semester-wise results
* Support for more grading systems
* Better menu-based navigation
* Option to update or remove course records

## What I Learned

Building this project helped me understand how individual C++ concepts come together in a complete program.

Instead of only practicing classes, loops, or arrays separately, I used them together to solve an actual problem. It also gave me a better understanding of **encapsulation, input validation, credit-weighted calculations, and organizing code using OOP**.

## Author

**Prince Sah**

B.Tech CSE Student | Learning C++, DSA & Full-Stack Development

---

⭐ If you find this project useful, feel free to explore the code and suggest improvements.
