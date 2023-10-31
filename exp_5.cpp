#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//This demo was built on Linux/Unix system. System command "clear" is being used. If it runs on Windows, errors may occur.

class people
{
public:
    string name,gender,identity;
    //here using string to storage gender for more compatibility
    int serial;
    double id,total_time,weekly_time;
    void input();
    void output(string who);
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
        if(scanner -> next != NULL) scanner = scanner -> next;
        scanner -> next = create;
        create  -> next = NULL;
        input_identity:
        system("clear");
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

void people::output(string who) { //The same output function as exp_1_1
    system("clear");
    scanner = head -> next;
    //if output all people, add identity in front of the list so that simplify viewing
    if(who == "all")    cout << left << setw(20) << "Identity" << '\t' << left << setw(20) << "Serial" << '\t' << left << setw(20) << "Name"   << '\t' << left << setw(20) << "Gender" << '\t' << left << setw(20) << "ID"         << '\t' << left << setw(20) << "Total time"  << '\t' << left << setw(20) << "Weekly time" << endl;
    else                cout << left << setw(20) << "Serial"   << '\t' << left << setw(20) << "Name"   << '\t' << left << setw(20) << "Gender" << '\t' << left << setw(20) << "ID"     << '\t' << left << setw(20) << "Total time" << '\t' << left << setw(20) << "Weekly time" << endl;
    while (scanner -> next!=NULL) {
        if(who == "all") {
            cout << left << setw(20) << scanner-> identity << '\t' << left << setw(20) << scanner->serial << '\t' << left << setw(20) << scanner->name  << '\t' << left<< setw(20) << scanner->gender << '\t' << left << setw(20) << scanner->id        << '\t' << left << setw(20) << scanner->total_time  << '\t' << left << setw(20) << scanner->weekly_time << endl;
            scanner = scanner->next;    //If output all people, add identity in front of the list.
        }else if(scanner -> identity == who){
            cout << left << setw(20) << scanner-> serial   << '\t' << left << setw(20) << scanner->name   << '\t' << left<< setw(20) << scanner->gender << '\t' << left << setw(20) << scanner->id    << '\t' << left << setw(20)<< scanner->total_time << '\t' << left << setw(20) << scanner->weekly_time << endl;
            scanner = scanner->next;    //If this person is the person you want, output the person's information.
        }else{
            scanner = scanner->next;  //If this person is not the person you want, skip the person.
        }
    }
    //last node
    if(who == "all")               cout << left << setw(20) << scanner-> identity << '\t' << left << setw(20) << scanner->serial << '\t' << left << setw(20) << scanner->name   << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(20) << scanner->id         << '\t' << left << setw(10) << scanner->total_time  << '\t' << left << setw(10) << scanner->weekly_time << endl;
    if(scanner -> identity == who) cout << left << setw(20) << scanner-> serial   << '\t' << left << setw(20) << scanner->name   << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(20) << scanner->id     << '\t' << left << setw(20) << scanner->total_time << '\t' << left << setw(10) << scanner->weekly_time << endl;
    cout << "All information has shown. Press enter to go home." << endl;   //Check if last node is the person you want. If yes, output the person's information.
    scanner = head -> next; //reposition the scanner for next use
    getchar();              //press enter to continue
}

int main() {    //The same user interface as exp_1_1
    cout << "Information system." << endl;
    cout << "Input password to login." << endl;
    cout << "Debug mode: Password = root&admin114514" << endl;
    //login
    for(int count=0;;){
        if(count == 3) {
            cout << "Reached maximum try count. Exiting..." << endl;
            abort();
        }
        string password;
        cin >> password;
        if(password == "root&admin114514")  break;
        else {
            count ++;
            if(count<3) cout << "Password incorrect, please input again." << endl;
            //Here, if incorrectly input 3 times, "incorrect" would not show up.
            //Instead, it would directly show "exiting"
        }
    }

    head = new people;
    scanner = head;
    p->input();

    home:
    system("clear");
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
                    p->output("all");       //output all
                    goto home;
                case 2:
                    p->output("student");   //output students only
                    goto home;
                case 3:
                    p->output("teacher");   //output teachers only
                    goto home;
                case 4:
                    p->output("graduate");  //output graduates only
                    goto home;
                case 5:
                    p->output("TA");        //output TAs only
                    goto home;
                default:
                    goto input_identity;         //re-input in case user input something else
            }
        case 114514:
            abort();
        default:
            cout << "Input not correct, please input again." << endl;
            goto input;
    }
}