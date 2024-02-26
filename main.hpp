#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int N = 5;
struct Student
{
    int id;
    char name[20];
    char major[20];
    //string name;
    //string major;
    Student *next;
};

Student *makeStudent();
void printStudent(Student *head);

Student *makeStudent()
{
    Student *head, *temp, *prev;
    char tstr[10];
    ifstream ifs;
    ifs.open("students.txt");
    if(!ifs) {
        cerr << "ERROR: FILE COOKED" << endl;
        exit(0);
    }

    for(int i = 0; i < N; i++) {
        temp = (Student *)malloc(sizeof(Student));
        //ifs >> temp->id >> temp->name >> temp->major;
        ifs.getline(tstr, 20, ' ');
        temp->id = atoi(tstr);
        ifs.getline(temp->name, 20, ' ');
        ifs.getline(temp->major, 20);
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

//ERROR with string data type! String data type does not have a SET amount of space needed. It is DYNAMIC, changes whenever.
//Malloc for student struct does not allocate enough memory for the string, doesn't have a specified amount!
//CHANGE STRINGS AND STRING FUNCTIONS TO CHAR TYPE!!