#include <iostream>
#include <string>
using namespace std;

class people
{
public:
    string name,gender,identity;
    //here using string to storage gender for more compatibility
    int serial;
    double id,total_time,weekly_time;
    void input();
    void output();
    people *next;
};
people *p,*head,*scanner,*create;
//the same listpoint initializer as exp_1_1

void people::input() {
    string input_name,input_gender;
    int input_serial = 0,who;
    double input_id = 0,input_total_time = 0, input_weekly_time = 0;
    while(input_serial!=-114514){   //endless loop for continuously input
        int exit=0; //when exit==1, exit the function
        create = new people;
        scanner -> next = create;
        create -> next = NULL;
        input_identity:
        cout << "Please input identity." << endl;
        cout << "1 student, 2 teacher, 3 graduate, 4 TA, 5 exit input" << endl;
        cin >> who;
        switch (who) {
            case 1:
                create -> identity = "student";
                break;
            case 2:
                create -> identity = "teacher";
                break;
            case 3:
                create -> identity = "graduate";
                break;
            case 4:
                create -> identity = "TA";
                break;
            case 5:
                exit=1;
                break;
            default:    //re-input in case user input something else
                cout << "Input not correct, please input again." << endl;
                goto input_identity;
        }
        if(exit==1) break;
        cout << "Please input serial number." << endl;
        cin >> input_serial;
        cout << "Please input name." << endl;
        cin >> input_name;
        cout << "Please input gender." << endl;
        cin >> input_gender;
        cout << "Please input id." << endl;
        cin >> input_id;
        cout << "Please input total time." << endl;
        cin >> input_total_time;
        cout << "Please input weekly time." << endl;
        cin >> input_total_time;
        create -> serial = input_serial;
        create -> name = input_name;
        create -> gender = input_gender;
        create -> id = input_id;
        create -> total_time = input_total_time;
        create -> weekly_time = input_weekly_time;
        scanner = create;
    }
}

void people::output() { //The same output function as exp_1_1
    scanner = head -> next;
    cout << "Identity" << '\t' << "Serial" << '\t' << "Name" << '\t' << "Gender" << '\t' << "ID" << '\t' << "Total time" << '\t' << "Weekly time" << endl;
    while (scanner -> next!=NULL) {
        cout << scanner -> identity << '\t' << scanner -> serial << '\t' << scanner -> name << '\t' << scanner -> gender << '\t' << scanner -> id << '\t' << scanner -> total_time << '\t' << scanner -> weekly_time << endl;
        scanner = scanner -> next;
    }
    cout << scanner -> serial << '\t' << scanner -> name << '\t' << scanner -> gender << '\t' << scanner -> id << '\t' << scanner -> total_time << '\t' << scanner -> weekly_time << endl;
    cout << "All information has shown." << endl;
    scanner = head -> next;
}

class student: virtual public people
{
public:
    void output_student();
};
student *s;

void student::output_student() {   //all output functions are the same, so I only explain the first one.
    scanner = head -> next;
    cout << "Serial" << '\t' << "Name" << '\t' << "Gender" << '\t' << "ID" << '\t' << "Total time" << '\t' << "Weekly time" << endl;
    while (scanner -> next!=NULL) {
        if(scanner -> identity != "student"){
            scanner = scanner -> next;  //If this person is not student, skip the person.
        }else{
            cout << scanner->serial << '\t' << scanner->name << '\t' << scanner->gender << '\t' << scanner->id << '\t' << scanner->total_time << '\t' << scanner->weekly_time << endl;
            scanner = scanner->next;    //If this person is student, output the person's information.
        }
    }
    if(scanner -> identity == "student") cout << scanner -> serial << '\t' << scanner -> name << '\t' << scanner -> gender << '\t' << scanner -> id << '\t' << scanner -> total_time << '\t' << scanner -> weekly_time << endl;
    cout << "All information has shown." << endl;   //Check if last node is student. If yes, output the person's information.
    scanner = head -> next;
}

class teacher: virtual public people
{
public:
    void output_teacher();
};
teacher *te;

void teacher::output_teacher() {
    scanner = head -> next;
    cout << "Serial" << '\t' << "Name" << '\t' << "Gender" << '\t' << "ID" << '\t' << "Total time" << '\t' << "Weekly time" << endl;
    while (scanner -> next!=NULL) {
        if(scanner -> identity != "teacher"){
            scanner = scanner -> next;
        }else{
            cout << scanner->serial << '\t' << scanner->name << '\t' << scanner->gender << '\t' << scanner->id << '\t' << scanner->total_time << '\t' << scanner->weekly_time << endl;
            scanner = scanner->next;
        }
    }
    if(scanner -> identity == "teacher") cout << scanner -> serial << '\t' << scanner -> name << '\t' << scanner -> gender << '\t' << scanner -> id << '\t' << scanner -> total_time << '\t' << scanner -> weekly_time << endl;
    cout << "All information has shown." << endl;
    scanner = head -> next;
}

class graduate: public student
{
public:
    void output_graduate();
};
graduate *g;

void graduate::output_graduate() {
    scanner = head -> next;
    cout << "Serial" << '\t' << "Name" << '\t' << "Gender" << '\t' << "ID" << '\t' << "Total time" << '\t' << "Weekly time" << endl;
    while (scanner -> next!=NULL) {
        if(scanner -> identity != "graduate"){
            scanner = scanner -> next;
        }else{
            cout << scanner->serial << '\t' << scanner->name << '\t' << scanner->gender << '\t' << scanner->id << '\t' << scanner->total_time << '\t' << scanner->weekly_time << endl;
            scanner = scanner->next;
        }
    }
    if(scanner -> identity == "graduate") cout << scanner -> serial << '\t' << scanner -> name << '\t' << scanner -> gender << '\t' << scanner -> id << '\t' << scanner -> total_time << '\t' << scanner -> weekly_time << endl;
    cout << "All information has shown." << endl;
    scanner = head -> next;
}

class TA: public graduate, public teacher
{
public:
    void output_TA();
};
TA *ta;

void TA::output_TA() {
    scanner = head -> next;
    cout << "Serial" << '\t' << "Name" << '\t' << "Gender" << '\t' << "ID" << '\t' << "Total time" << '\t' << "Weekly time" << endl;
    while (scanner -> next!=NULL) {
        if(scanner -> identity != "TA"){
            scanner = scanner -> next;
        }else{
            cout << scanner->serial << '\t' << scanner->name << '\t' << scanner->gender << '\t' << scanner->id << '\t' << scanner->total_time << '\t' << scanner->weekly_time << endl;
            scanner = scanner->next;
        }
    }
    if(scanner -> identity == "TA") cout << scanner -> serial << '\t' << scanner -> name << '\t' << scanner -> gender << '\t' << scanner -> id << '\t' << scanner -> total_time << '\t' << scanner -> weekly_time << endl;
    cout << "All information has shown." << endl;
    scanner = head -> next;
}

//pointers: p for people, s for students, g for graduates, te for teachers, ta for TA.

int main() {    //The same user interface as exp_1_1
    cout << "Information system." << endl;
    cout << "Please input information." << endl;
    head = new people;
    scanner = head;
    p->input();

    home:
    cout << "------------------------------------------------------------" << endl;
    cout << "Information system." << endl;
    input:
    int selection;
    cout << "Input 1 to add more people's information." << endl;
    cout << "Input 2 to view people's information." << endl;
    cout << "Input 114514 to exit. Your information would not be saved!" << endl;
    cin >> selection;
    switch (selection) {
        case 1: //Input
            p->input();
            goto home;
        case 2: //Choose output category
            int identity;
            cout << "What kind of information do you want to output?" << endl;
            cout << "1 all people, 2 students, 3 teachers, 4 graduate, 5 TA" << endl;
            input_identity:
            cin >> identity;
            switch (identity) {
                case 1:
                    p->output();//output all
                    goto home;
                case 2:
                    s->output_student();//output students only
                    goto home;
                case 3:
                    te->output_teacher();//output teachers only
                    goto home;
                case 4:
                    g->output_graduate();//output graduates only
                    goto home;
                case 5:
                    ta->output_TA();//output TAs only
                    goto home;
                default:
                    goto input_identity;//re-input in case user input something else
            }
        case 114514:
            abort();
        default:
            cout << "Input not correct, please input again." << endl;
            goto input;
    }
}