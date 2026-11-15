# 🎓 University Research Management System

A **C++ Console-Based Application** developed as a 2nd Semester academic project using **Object-Oriented Programming (OOP)**. This system is designed to manage university research-related records, including students, faculty members, research projects, and publications.

## ✨ Features

- **Student Management:** Add and view student information (ID, Name, Department, Research Topic, Semester, and CGPA).
- **Faculty Management:** Add and view faculty details (ID, Name, Department, Designation, and Specialization).
- **Research Project Management:** Add and view research projects (Project ID, Title, Student, Supervisor, Status, and Budget).
- **Publication Management:** Add and view publication records (ID, Title, Journal, and Year).
- **File Handling:** Save all records into a text file (`research_data.txt`).

## 🧠 OOP Concepts Implemented

This project demonstrates the following Object-Oriented Programming concepts:

- **Abstraction:** `Person` is an abstract base class containing pure virtual functions.
- **Inheritance:** `Student` and `Faculty` classes inherit from the `Person` class.
- **Polymorphism:** Derived classes override the `input()` and `display()` virtual functions.
- **Encapsulation:** Data members are protected using private/protected access modifiers and accessed through getter functions.
- **Templates:** A generic `Display<T>` class is implemented.
- **Exception Handling:** Handles invalid inputs, including empty IDs and negative budgets.
- **File Handling:** Uses `fstream` to store records in a text file.

## ⚙️ Technologies Used

- **Language:** C++
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Compiler:** g++ 
- **Storage:** Text File (`research_data.txt`)

## 🚀 How to Run

### Prerequisites
- Install a C++ compiler (such as GCC/g++).

### Compilation

Open a terminal in the project directory and run:

```bash
g++ main.cpp -o main
```

### Execution

**Windows:**
```bash
main.exe
```

**Mac / Linux:**
```bash
./main
```

## 📋 Application Menu

The application provides the following menu options:

| Option | Function |
|:---:|---|
| 1 | Add Student |
| 2 | View Students |
| 3 | Add Faculty |
| 4 | View Faculty |
| 5 | Add Research Project |
| 6 | View Projects |
| 7 | Add Publication |
| 8 | View Publications |
| 9 | Save Data |
| 10 | Exit |

## 📝 Important Notes

- All records are saved to `research_data.txt` when the user selects **Option 9 (Save Data)**.
- The file is created automatically when data is saved.
- The data file is not included in the repository.
- **Current Limitation:** Saved records are not automatically loaded when the application restarts.

## 👨‍💻 Author

**Tajmul Hasan Chowdhury**

- GitHub: [@tajmul101844](https://github.com/tajmul101844)

---

⭐ *Developed as a 2nd Semester Object-Oriented Programming (OOP) project.*
