#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    // Constructor
    Student(string name, int id, double gpa) : name(name), id(id), gpa(gpa) {}

    // Display student information
    void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nGPA: " << gpa << "\n\n";
    }

    // Getter for student ID
    int getID() const {
        return id;
    }


private:
    string name;
    int id;
    double gpa;
};

class StudentInformationSystem {
public:
    // Add a new student to the system
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Display information for all students in the system
    void displayAllStudents() const {
        for (const auto& student : students) {
            student.displayInfo();
        }
    }

    // Search for a student by ID and display their information
    void searchStudentByID(int id) const {
        for (const auto& student : students) {
            if (student.getID() == id) {
                student.displayInfo();
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n\n";
    }

private:
    vector<Student> students;
};

// Function to add a new student from user input
void addNewStudentFromInput(StudentInformationSystem& sis) {
    string name;
    int id;
    double gpa;

    cout << "Enter student name: ";
    cin>>name;

    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter student GPA: ";
    cin >> gpa;

    cin.ignore(); // Consume the newline character left in the buffer

    // Create a new student and add it to the system
    sis.addStudent(Student(name, id, gpa));

    cout << "Student added successfully!\n\n";
}

int main() {
    StudentInformationSystem sis;

    // Adding sample students
    sis.addStudent(Student("Raghav", 1001, 3.8));
    sis.addStudent(Student("Varun", 1002, 3.5));
    sis.addStudent(Student("Shivam", 1003, 4.0));

    int choice;
    do {
        cout << "1. Display all students\n";
        cout << "2. Search for a student by ID\n";
        cout << "3. Add a new student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sis.displayAllStudents();
                break;
            case 2:
                int searchID;
                cout << "Enter student ID to search: ";
                cin >> searchID;
                sis.searchStudentByID(searchID);
                break;
            case 3:
                addNewStudentFromInput(sis);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
