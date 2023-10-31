#include <iostream>
#include <string>
using namespace std;

class people{
public:
    string name,gender,identity;
    //here using string to storage gender for more compatibility
    int serial;
    double id,total_time,weekly_time;
    virtual void output_specific() =0;
};
people *vout;

class people_information: public people //storage all information here
{
public:
    void input();
    void output_specific();
    people_information *next;
};
people_information pi,*p,*head,*scanner,*create;
//the same listpoint initializer as exp_1_1

void people_information::input() {
    string input_name,input_gender;
    int input_serial = 0,who;
    double input_id = 0,input_total_time = 0, input_weekly_time = 0;
    while(input_serial!=-114514){   //endless loop for continuously input
        int exit=0; //when exit==1, exit the function
        create = new people_information;
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

void people_information::output_specific() { //The same output_specific function as exp_1_1
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

class student: virtual public people_information
{
public:
    void output_specific();
};
student s;

void student::output_specific() {   //all output_specific functions are the same, so I only explain the first one.
    scanner = head -> next;
    cout << "Serial" << '\t' << "Name" << '\t' << "Gender" << '\t' << "ID" << '\t' << "Total time" << '\t' << "Weekly time" << endl;
    while (scanner -> next!=NULL) {
        if(scanner -> identity != "student"){
            scanner = scanner -> next;  //If this person is not student, skip the person.
        }else{
            cout << scanner->serial << '\t' << scanner->name << '\t' << scanner->gender << '\t' << scanner->id << '\t' << scanner->total_time << '\t' << scanner->weekly_time << endl;
            scanner = scanner->next;    //If this person is student, output_specific the person's information.
        }
    }
    if(scanner -> identity == "student") cout << scanner -> serial << '\t' << scanner -> name << '\t' << scanner -> gender << '\t' << scanner -> id << '\t' << scanner -> total_time << '\t' << scanner -> weekly_time << endl;
    cout << "All information has shown." << endl;   //Check if last node is student. If yes, output_specific the person's information.
    scanner = head -> next;
}

class teacher: virtual public people_information
{
public:
    void output_specific();
};
teacher te;

void teacher::output_specific() {
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
    void output_specific();
};
graduate g;

void graduate::output_specific() {
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
    void output_specific();
};
TA ta;

void TA::output_specific() {
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

//objects: pi for all people, s for students, g for graduates, te for teachers, ta for TA.
//pointers: vout for polymorphism, p for class people

int main() {    //The same user interface as exp_1_1
    cout << "Information system." << endl;
    cout << "Please input information." << endl;
    head = new people_information;
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
        case 2: //Choose output_specific category
            int identity;
            cout << "What kind of information do you want to output_specific?" << endl;
            cout << "1 all people, 2 students, 3 teachers, 4 graduate, 5 TA" << endl;
        input_identity:
            cin >> identity;
            switch (identity) {
                case 1:
                    vout = &pi;//adjust output_specific to all people
                    break;
                case 2:
                    vout = &s;//adjust output_specific to students only
                    break;
                case 3:
                    vout = &te;//adjust output_specific to teachers only
                    break;
                case 4:
                    vout = &g;//adjust output_specific to graduates only
                    break;
                case 5:
                    vout = &ta;//adjust output_specific to TAs only
                    break;
                default:
                    goto input_identity;//re-input in case user input something else
            }
            break;
        case 114514:
            abort();
        default:
            cout << "Input not correct, please input again." << endl;
            goto input;
    }
    vout -> output_specific();  //execute output_specific function here
    goto home;
}