                                                                                                                                                                                                                                                                  #include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <limits>

using namespace std;



template <class T>
class Display
{
public:
    static void show(const T& value)
    {
        cout << value << endl;
    }
};



class Person
{
protected:
    string id;
    string name;
    string department;

public:
    Person() : id(""), name(""), department("") {}

    Person(string id, string name, string department)
        : id(id), name(name), department(department) {}

    virtual void input() = 0;
    virtual void display() const = 0;

    string getID() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }

    virtual ~Person() {}
};



class Student : public Person
{
private:
    string researchTopic;
    int semester;
    double cgpa;

public:
    Student() : Person(), researchTopic(""), semester(0), cgpa(0.0) {}

    Student(string id, string name, string department,
            string topic, int semester, double cgpa)
        : Person(id, name, department), researchTopic(topic), semester(semester), cgpa(cgpa) {}

    void input() override
    {
        cout << "\n===== Add Student =====\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Student ID : ";
        getline(cin, id);

        cout << "Name : ";
        getline(cin, name);

        cout << "Department : ";
        getline(cin, department);

        cout << "Research Topic : ";
        getline(cin, researchTopic);

        cout << "Semester : ";
        cin >> semester;

        cout << "CGPA : ";
        cin >> cgpa;

        // Clear trailing newline left by cin >> cgpa
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() const override
    {
        cout << "\n-------------------------\n";
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "Research Topic : " << researchTopic << endl;
        cout << "Semester : " << semester << endl;
        cout << "CGPA : " << fixed << setprecision(2) << cgpa << endl;
    }

    string getResearchTopic() const { return researchTopic; }
    int getSemester() const { return semester; }
    double getCGPA() const { return cgpa; }

    ~Student() override {}
};



class Faculty : public Person
{
private:
    string designation;
    string specialization;

public:
    Faculty() : Person(), designation(""), specialization("") {}

    Faculty(string id, string name, string department,
            string designation, string specialization)
        : Person(id, name, department), designation(designation), specialization(specialization) {}

    void input() override
    {
        cout << "\n===== Add Faculty =====\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Faculty ID : ";
        getline(cin, id);

        cout << "Name : ";
        getline(cin, name);

        cout << "Department : ";
        getline(cin, department);

        cout << "Designation : ";
        getline(cin, designation);

        cout << "Specialization : ";
        getline(cin, specialization);
    }

    void display() const override
    {
        cout << "\n-------------------------\n";
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "Designation : " << designation << endl;
        cout << "Specialization : " << specialization << endl;
    }

    string getDesignation() const { return designation; }
    string getSpecialization() const { return specialization; }

    ~Faculty() override {}
};



class ResearchProject
{
private:
    string projectID;
    string title;
    string studentID;
    string supervisorID;
    string status;
    double budget;

public:
    ResearchProject() : projectID(""), title(""), studentID(""), supervisorID(""), status("Ongoing"), budget(0.0) {}

    ResearchProject(string pid, string title, string sid, string fid, string status, double budget)
        : projectID(pid), title(title), studentID(sid), supervisorID(fid), status(status), budget(budget) {}

    void input()
    {
        cout << "\n===== Add Research Project =====\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Project ID : ";
        getline(cin, projectID);

        cout << "Project Title : ";
        getline(cin, title);

        cout << "Student ID : ";
        getline(cin, studentID);

        cout << "Supervisor ID : ";
        getline(cin, supervisorID);

        cout << "Status : ";
        getline(cin, status);

        cout << "Budget : ";
        cin >> budget;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() const
    {
        cout << "\n------------------------------\n";
        cout << "Project ID : " << projectID << endl;
        cout << "Title : " << title << endl;
        cout << "Student ID : " << studentID << endl;
        cout << "Supervisor ID : " << supervisorID << endl;
        cout << "Status : " << status << endl;
        cout << "Budget : " << budget << endl;
    }

    string getProjectID() const { return projectID; }
    string getTitle() const { return title; }
    string getStudentID() const { return studentID; }
    string getSupervisorID() const { return supervisorID; }
    string getStatus() const { return status; }
    double getBudget() const { return budget; }
};


class Publication
{
private:
    string publicationID;
    string title;
    string journal;
    int year;

public:
    Publication() : publicationID(""), title(""), journal(""), year(0) {}

    Publication(string id, string title, string journal, int year)
        : publicationID(id), title(title), journal(journal), year(year) {}

    void input()
    {
        cout << "\n===== Add Publication =====\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Publication ID : ";
        getline(cin, publicationID);

        cout << "Title : ";
        getline(cin, title);

        cout << "Journal : ";
        getline(cin, journal);

        cout << "Year : ";
        cin >> year;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() const
    {
        cout << "\n------------------------------\n";
        cout << "Publication ID : " << publicationID << endl;
        cout << "Title : " << title << endl;
        cout << "Journal : " << journal << endl;
        cout << "Year : " << year << endl;
    }

    string getPublicationID() const { return publicationID; }
    string getTitle() const { return title; }
    string getJournal() const { return journal; }
    int getYear() const { return year; }
};



vector<Student> students;
vector<Faculty> faculties;
vector<ResearchProject> projects;
vector<Publication> publications;

/*========================================
         EXCEPTION HANDLING
========================================*/

void checkID(const string& id)
{
    if (id.empty())
    {
        throw runtime_error("Error: ID cannot be empty!");
    }
}

void checkBudget(double amount)
{
    if (amount < 0)
    {
        throw runtime_error("Error: Invalid Budget!");
    }
}

/*========================================
            FILE HANDLING
========================================*/

void saveData()
{
    ofstream file("research_data.txt");

    if (!file.is_open())
    {
        cout << "Failed to open file for writing.\n";
        return;
    }

    file << "STUDENT\n";
    for (const auto& s : students)
    {
        file << s.getID() << "|" << s.getName() << "|" << s.getDepartment() << "\n";
    }

    file << "FACULTY\n";
    for (const auto& f : faculties)
    {
        file << f.getID() << "|" << f.getName() << "|" << f.getDepartment() << "\n";
    }

    file << "PROJECT\n";
    for (const auto& p : projects)
    {
        file << p.getProjectID() << "|" << p.getTitle() << "|" << p.getStudentID() << "\n";
    }

    file << "PUBLICATION\n";
    for (const auto& p : publications)
    {
        file << p.getPublicationID() << "|" << p.getTitle() << "\n";
    }

    file.close();
    cout << "\nData Saved Successfully.\n";
}

/*========================================
            ADD FUNCTIONS
========================================*/

void addStudent()
{
    try
    {
        Student s;
        s.input();
        checkID(s.getID());
        students.push_back(s);
        cout << "\nStudent Added Successfully.\n";
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}

void addFaculty()
{
    try
    {
        Faculty f;
        f.input();
        checkID(f.getID());
        faculties.push_back(f);
        cout << "\nFaculty Added Successfully.\n";
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}

void addProject()
{
    try
    {
        ResearchProject p;
        p.input();
        checkID(p.getProjectID());
        checkBudget(p.getBudget());
        projects.push_back(p);
        cout << "\nProject Added Successfully.\n";
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}

void addPublication()
{
    try
    {
        Publication p;
        p.input();
        checkID(p.getPublicationID());
        publications.push_back(p);
        cout << "\nPublication Added Successfully.\n";
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}

/*========================================
            VIEW FUNCTIONS
========================================*/

void viewStudents()
{
    if (students.empty()) { cout << "\nNo students found.\n"; return; }
    for (const auto& s : students)
    {
        s.display();
    }
}

void viewFaculty()
{
    if (faculties.empty()) { cout << "\nNo faculty members found.\n"; return; }
    for (const auto& f : faculties)
    {
        f.display();
    }
}

void viewProjects()
{
    if (projects.empty()) { cout << "\nNo projects found.\n"; return; }
    for (const auto& p : projects)
    {
        p.display();
    }
}

void viewPublications()
{
    if (publications.empty()) { cout << "\nNo publications found.\n"; return; }
    for (const auto& p : publications)
    {
        p.display();
    }
}

/*========================================
                  MAIN
========================================*/

int main()
{
    int choice = 0;

    do
    {
        cout << "\n====================================\n";
        cout << " UNIVERSITY RESEARCH MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Add Faculty\n";
        cout << "4. View Faculty\n";
        cout << "5. Add Research Project\n";
        cout << "6. View Projects\n";
        cout << "7. Add Publication\n";
        cout << "8. View Publications\n";
        cout << "9. Save Data\n";
        cout << "10. Exit\n";
        cout << "\nEnter Choice : ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1: addStudent(); break;
        case 2: viewStudents(); break;
        case 3: addFaculty(); break;
        case 4: viewFaculty(); break;
        case 5: addProject(); break;
        case 6: viewProjects(); break;
        case 7: addPublication(); break;
        case 8: viewPublications(); break;
        case 9: saveData(); break;
        case 10: cout << "Program Closed.\n"; break;
        default: cout << "Invalid Choice!\n";
        }

    } while (choice != 10);

    return 0;
}