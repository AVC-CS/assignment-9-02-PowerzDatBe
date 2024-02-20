#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int N = 5;
struct Student
{
    int id;
    string name;
    string major;
    Student *next;
};

Student *makeStudent();
void printStudent(Student *head);

Student *makeStudent()
{
    Student *head, *temp, *prev;
    ifstream ifs;
    ifs.open("students.txt");
    if(!ifs) {
        cerr << "ERROR: FILE COOKED" << endl;
        exit(0);
    }

    for(int i = 0; i < N; i++) {
        temp = (Student *)malloc(sizeof(Student));
        ifs >> temp->id >> temp->name >> temp->major;
        temp->next = NULL;
        if (i == 0) {
            head = temp;
        }
        else {
            prev->next = temp;
        }
        prev = temp;
    }

    return head;
}
void printStudent(Student *head)
{
    Student *temp;
    temp = head;
    
    while(temp != NULL) {
        cout << temp->id << "\t";
        cout << temp->name << "\t";
        cout << temp->major << "\n";
        temp = temp->next;
    }
}