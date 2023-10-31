#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//This demo was built on Linux/Unix system. System command "clear" is being used. If it runs on Windows, errors may occur.

class people
{
public:
    string name,majorname,departmentname,gender,serial;
    //here using string to storage gender for more compatibility
    int age,classnum;
    void load_eg();
    void input();
    void del();
    void edit();
    void output_all();
    void output_specific_name(string who);
    void output_specific_serial(string which_serial);
    void output_by_gender(string which_gender);
    void output_by_classnum(int which_classnum);
    void count_by_gender(string which_gender);
    void count_by_classnum(int which_classnum);
    void count_by_age(int which_age);
    void count_by_departmentname(string which_department);
    void output_file();
    people *next;
};
people *p,*head,*scanner,*create;
//the same listpoint initializer as exp_1_1

void people::load_eg() {
    ifstream file;
    file.open("eg.dat");
    for(int t=0;t!=10;t++){
        create = new people;
        scanner -> next = create;
        create  -> next = NULL;
        file >> create -> serial >> create -> name >> create -> gender >> create -> age >> create -> classnum >> create -> majorname >> create -> departmentname;
        scanner = create;
    }
}

void people::input() {
    string input_name,input_majorname,input_departmentname,input_gender;
    int input_serial = 0, input_age = 0, input_classnum = 0;
    while(input_serial!=-114514){   //endless loop for continuously input
        create = new people;
        while(scanner -> next != NULL) scanner = scanner -> next;  //move pointer to the end of the node list
        scanner -> next = create;
        create  -> next = NULL;
        cout << "Please input serial number. Input 114514 to quit." << endl;
        cin >> input_serial;
        if(input_serial==114514) break;
        cout << "Please input name." << endl;
        cin >> input_name;
        cout << "Please input gender." << endl;
        cin >> input_gender;
        cout << "Please input age." << endl;
        cin >> input_age;
        cout << "Please input class number." << endl;
        cin >> input_classnum;
        cout << "Please input major name." << endl;
        cin >> input_majorname;
        cout << "Please input department name." << endl;
        cin >> input_departmentname;
        create -> serial = input_serial;
        create -> name = input_name;
        create -> gender = input_gender;
        create -> age = input_age;
        create -> classnum = input_classnum;
        create -> majorname = input_majorname;
        create -> departmentname = input_departmentname;
        scanner = create;   //reposition the scanner for next use
    }
}

void people::del() {
    people *connect1,*connect2;  //these pointers connect previous and next node of the deleted node
    string serial2del; //serial to delete
    cout << "Please input serial of the person you want to delete: ";
    cin >> serial2del;
    scanner = head; //here, due to scanning the nodes is a one-way trip, we must stop at delete->previous and make it connect 1 so that we can connect them
    while(scanner -> next -> serial != serial2del && scanner -> next -> next != NULL){
        scanner = scanner -> next;
    }
    if(scanner -> next -> serial == serial2del){    //person found
        connect1 = scanner;                         //connect 1 = delete -> previous
        connect2 = scanner -> next -> next;         //connect 2 = delete -> next
        connect1 -> next = connect2;                //delete -> previous -> next = delete -> next
    }else{  //person not found
        cout << "No relevant information found. Check your input." << endl;
    }
    scanner = head -> next; //reposition the scanner for next use
}

void people::edit() {
    string serial2edit; //serial to delete
    cout << "Please input serial of the person you want to edit: ";
    cin >> serial2edit;
    while(scanner -> serial != serial2edit && scanner -> next != NULL){
        scanner = scanner -> next;
    }
    if(scanner -> serial == serial2edit){    //person found
        cout << "The person's information is" << endl;  //show information before change
        cout << left << setw(10) << "Serial" << '\t' << left << setw(20) << "Name" << '\t' << left << setw(20) << "Gender"  << '\t' << left << setw(5) << "Age" << '\t' << left << setw(10) << "Class number" << '\t' << left << setw(20) << "Major name" << '\t' << left << setw(20) << "Department name" << endl;
        cout << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
        cout << "Please input changed serial number." << endl;
        cin >> scanner -> serial;
        cout << "Please input changed name." << endl;
        cin >> scanner -> name;
        cout << "Please input changed gender." << endl;
        cin >> scanner -> gender;
        cout << "Please input changed age." << endl;
        cin >> scanner -> age;
        cout << "Please input changed class number." << endl;
        cin >> scanner -> classnum;
        cout << "Please input changed major name." << endl;
        cin >> scanner -> majorname;
        cout << "Please input changed department name." << endl;
        cin >> scanner -> departmentname;
    }else{  //person not found
        cout << "No relevant information found. Check your input." << endl;
    }
    scanner = head -> next; //reposition the scanner for next use
}

void people::output_all() { //The same output function as exp_1_1
    system("clear");
    scanner = head->next;
    cout << left << setw(10) << "Serial"          << '\t' << left << setw(20) << "Name"          << '\t' << left << setw(20) << "Gender"          << '\t' << left << setw(5) << "Age"          << '\t' << left << setw(10) << "Class number"      << '\t' << left << setw(20) << "Major name"         << '\t' << left << setw(20) << "Department name"         << endl;
    while (scanner->next != NULL) {
        cout << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
        scanner = scanner->next;    //If this person match, output the person's information.
    }
    //last node
    cout << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
    cout << "All information has shown." << endl;
    scanner = head->next; //reposition the scanner for next use
}

void people::output_specific_serial(string which_serial) { //Output function in exp_1_1 but changed a little.
    system("clear");
    scanner = head->next;
    cout << left << setw(10) << "Serial" << '\t' << left << setw(20) << "Name" << '\t' << left << setw(20) << "Gender"  << '\t' << left << setw(5) << "Age" << '\t' << left << setw(10) << "Class number" << '\t' << left << setw(20) << "Major name" << '\t' << left << setw(20) << "Department name" << endl;
    while (scanner->serial != which_serial && scanner->next != NULL) { //Check whether the person is you want. If yes, output. If not, skip.
        scanner = scanner->next;
    }
    if (scanner->next != NULL) {
        cout << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
    }else{
        if (scanner->serial == which_serial) {  //check last node, if yes, output
            cout << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
        }else{
            cout << "No relevant information found. Check your input." << endl;
        }
        cout << "All information has shown." << endl;
        scanner = head->next; //reposition the scanner for next use
    }
}

void people::output_specific_name(string who) {    //Output function in exp_1_1 but changed a little.
    system("clear");
    scanner = head->next;
    cout << left << setw(10) << "Serial" << '\t' << left << setw(20) << "Name" << '\t' << left << setw(20) << "Gender" << '\t' << left << setw(5) << "Age" << '\t' << left << setw(10) << "Class number" << '\t' << left << setw(20) << "Major name" << '\t' << left << setw(20) << "Department name" << endl;
    while (scanner->name != who &&
           scanner->next != NULL) { //Check whether the person is you want. If yes, output. If not, skip.
        scanner = scanner->next;
    }
    if (scanner->next != NULL) {
        cout << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
    } else {
        if (scanner->name == who) {  //check last node, if yes, output
            cout << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
        } else {
            cout << "No relevant information found. Check your input." << endl;
        }
        cout << "All information has shown." << endl;
        scanner = head->next; //reposition the scanner for next use
    }
}

void people::output_by_gender(string which_gender) { //Output function in exp_1_1 but changed a little.
    int found = 0;  //to check whether the information is found
    system("clear");
    scanner = head -> next;
    cout << left << setw(10) << "Serial"          << '\t' << left << setw(20) << "Name"          << '\t' << left << setw(20) << "Gender"          << '\t' << left << setw(5) << "Age"          << '\t' << left << setw(10) << "Class number"      << '\t' << left << setw(20) << "Major name"         << '\t' << left << setw(20) << "Department name"         << endl;
    while (scanner -> next!=NULL) {
        if(scanner -> gender == which_gender){
            cout << left << setw(10) << scanner -> serial << '\t' << left << setw(20) << scanner -> name << '\t' << left << setw(20) << scanner -> gender << '\t' << left << setw(5) << scanner -> age << '\t' << left << setw(10) << scanner -> classnum << '\t' << left << setw(20) << scanner -> majorname << '\t' << left << setw(20) << scanner -> departmentname << endl;
            scanner = scanner->next;    //If this person match, output the person's information.
            found = 1;
        }else{
            scanner = scanner->next;  //If this person not match, skip the person.
        }
    }
    //last node
    if(scanner -> gender == which_gender) {
        cout << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
        found = 1;
    }
    if (found==0) cout << "No relevant information found. Check your input." << endl;
    cout << "All information has shown." << endl;   //Check if last node is the person you want. If yes, output the person's information.
    scanner = head -> next; //reposition the scanner for next use
}

void people::output_by_classnum(int which_classnum) {   //Output function in exp_1_1 but changed a little.
    int found = 0;
    system("clear");
    scanner = head -> next;
    cout << left << setw(10) << "Serial"          << '\t' << left << setw(20) << "Name"          << '\t' << left << setw(20) << "Gender"          << '\t' << left << setw(5) << "Age"          << '\t' << left << setw(10) << "Class number"      << '\t' << left << setw(20) << "Major name"         << '\t' << left << setw(20) << "Department name"         << endl;
    while (scanner -> next!=NULL) {
        if(scanner -> classnum == which_classnum){
            cout << left << setw(10) << scanner -> serial << '\t' << left << setw(20) << scanner -> name << '\t' << left << setw(20) << scanner -> gender << '\t' << left << setw(5) << scanner -> age << '\t' << left << setw(10) << scanner -> classnum << '\t' << left << setw(20) << scanner -> majorname << '\t' << left << setw(20) << scanner -> departmentname << endl;
            scanner = scanner->next;    //If this person match, output the person's information.
            found = 1;
        }else{
            scanner = scanner->next;  //If this person not match, skip the person.
        }
    }
    //last node
    if(scanner -> classnum == which_classnum){
        cout << left << setw(10) << scanner -> serial << '\t' << left << setw(20) << scanner -> name << '\t' << left << setw(20) << scanner -> gender << '\t' << left << setw(5) << scanner -> age << '\t' << left << setw(10) << scanner -> classnum << '\t' << left << setw(20) << scanner -> majorname << '\t' << left << setw(20) << scanner -> departmentname << endl;
        found = 1;
    }
    if (found==0) cout << "No relevant information found. Check your input." << endl;
    cout << "All information has shown." << endl;   //Check if last node is the person you want. If yes, output the person's information.
    scanner = head -> next; //reposition the scanner for next use
}

void people::count_by_gender(string which_gender){
    int count = 0;  //to check whether the information is found
    scanner = head -> next;
    while (scanner -> next!=NULL) {
        if(scanner -> gender == which_gender){
            scanner = scanner->next;    //If this person match, count the person.
            count++;
        }else{
            scanner = scanner->next;  //If this person not match, skip the person.
        }
    }
    //last node
    if(scanner -> gender == which_gender)   count++;
    //is or are?
    if(count == 1) cout << "There is 1 person match your filter." << endl;
    else cout << "There are " << count << " people match your filter." << endl;
    scanner = head -> next; //reposition the scanner for next use
}

void people::count_by_classnum(int which_classnum){
    int count = 0;  //to check whether the information is found
    scanner = head -> next;
    while (scanner -> next!=NULL) {
        if(scanner -> classnum == which_classnum){
            scanner = scanner->next;    //If this person match, count the person.
            count++;
        }else{
            scanner = scanner->next;  //If this person not match, skip the person.
        }
    }
    //last node
    if(scanner -> classnum == which_classnum)   count++;
    //is or are?
    if(count == 1) cout << "There is 1 person match your filter." << endl;
    else cout << "There are " << count << " people match your filter." << endl;
    scanner = head -> next; //reposition the scanner for next use
}

void people::count_by_age(int which_age){
    int count = 0;  //to check whether the information is found
    scanner = head -> next;
    while (scanner -> next!=NULL) {
        if(scanner -> age == which_age){
            scanner = scanner->next;    //If this person match, count the person.
            count++;
        }else{
            scanner = scanner->next;  //If this person not match, skip the person.
        }
    }
    //last node
    if(scanner -> age == which_age)   count++;
    //is or are?
    if(count == 1) cout << "There is 1 person match your filter." << endl;
    else cout << "There are " << count << " people match your filter." << endl;
    scanner = head -> next; //reposition the scanner for next use
}

void people::count_by_departmentname(string which_department){
    int count = 0;  //to check whether the information is found
    scanner = head -> next;
    while (scanner -> next!=NULL) {
        if(scanner -> departmentname == which_department){
            scanner = scanner->next;    //If this person match, count the person.
            count++;
        }else{
            scanner = scanner->next;  //If this person not match, skip the person.
        }
    }
    //last node
    if(scanner -> departmentname == which_department)   count++;
    //is or are?
    if(count == 1) cout << "There is 1 person match your filter." << endl;
    else cout << "There are " << count << " people match your filter." << endl;
    scanner = head -> next; //reposition the scanner for next use
}

void people::output_file() { //almost the same as output_all()
    ofstream out;
    cout << "Writing file. Please wait..." << endl; //Tell user that the system is writing file
    out.open("output.dat");
    system("clear");
    scanner = head->next;
    out << left << setw(10) << "Serial"          << '\t' << left << setw(20) << "Name"          << '\t' << left << setw(20) << "Gender"          << '\t' << left << setw(5) << "Age"          << '\t' << left << setw(10) << "Class number"      << '\t' << left << setw(20) << "Major name"         << '\t' << left << setw(20) << "Department name"         << endl;
    while (scanner->next != NULL) {
        out << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
        scanner = scanner->next;    //If this person match, output the person's information.
    }
    //last node
    out << left << setw(10) << scanner->serial << '\t' << left << setw(20) << scanner->name << '\t' << left << setw(20) << scanner->gender << '\t' << left << setw(5) << scanner->age << '\t' << left << setw(10) << scanner->classnum << '\t' << left << setw(20) << scanner->majorname << '\t' << left << setw(20) << scanner->departmentname << endl;
    out << "All information has shown." << endl;
    out.close();
    cout << "Information have been save to output.dat" << endl; //Tell user that the information have been output
    scanner = head->next; //reposition the scanner for next use
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
    for(int login=0;login!=1;) {
        char load_eg;
        cout << "Do you want to load example data? (y/n)" << endl;
        cin >> load_eg;
        if (load_eg == 'y') {
            p->load_eg();
            login = 1;
        } else if (load_eg == 'n') {
            p->input();
            login = 1;
        }
        cout << "Input incorrect, please input again." << endl;
    }

    //yyyyyyyyyyyyyyes home is here the most important menu in the whole program look at here right now
    for(int stop=0;stop!=1;) {
    system("clear");
    cout << "------------------------------------------------------------" << endl;
    cout << "Information system." << endl;
    string selection;
    string name, gender, departmentname, serial; //strings can't define in switch, so I define them here
    cout << "Input 1 to add more people's information." << endl;
    cout << "Input 2 to delete people's information." << endl;
    cout << "Input 3 to edit people's information." << endl;
    cout << "Input 4 to view people's information." << endl;
    cout << "Input 5 to calculate the number of people." << endl;
    cout << "Input 6 to output people's information to file." << endl;
    cout << "Input 114514 to exit. Your information would not be saved!" << endl;
    cin >> selection;
    /*if(selection!=1&&selection!=2&&selection!=3&&selection!=4&&selection!=5&&selection!=6&&selection!=114514){
            cout << "Input incorrect, please input again." << endl;
            goto input;
        }*/
        if (selection == "1") { //Input information
            p->input();
        } else if (selection == "2") {  //Delete by serial
            p->del();
        } else if (selection == "3") {  //Edit information
            p->edit();
        } else if (selection == "4") {  //Choose output category, output information of specific student
            cout << "Choose output format." << endl;
            cout
                    << "1 all people, 2 find specific serial, 3 find specific name, 4 view by gender, 5 view by class number"
                    << endl;

            for (int pass4 = 0; pass4 != 1;) {
                string format;
                cin >> format;
                if (format == "1") {
                    p->output_all();                              //output all
                    pass4 = 1;
                } else if (format == "2") {
                    cout << "Please input the serial you want to search for: ";
                    cin >> serial;
                    p->output_specific_serial(serial);   //output specific person by serial
                    pass4 = 1;
                } else if (format == "3") {
                    cout << "Please input the name you want to search for: ";
                    cin >> name;
                    p->output_specific_name(name);             //output specific person by name
                    pass4 = 1;
                } else if (format == "4") {
                    cout << "Please input the gender you want to search for: ";
                    cin >> gender;
                    p->output_by_gender(gender);        //view people by gender
                    pass4 = 1;
                } else if (format == "5") {
                    int classnum;
                    cout << "Please input the class number you want to search for: ";
                    cin >> classnum;
                    p->output_by_classnum(classnum);   //view people by class number
                    pass4 = 1;
                }  else{
                    cout << "Input invalid, please input again." << endl;
                }
            }
        } else if (selection == "5") {   //the same as case 4, output quantity of specific student
            cout << "Choose count format." << endl;
            cout << "1 by gender, 2 find class number, 3 by age, 4 by department name" << endl;

            for (int pass5 = 0; pass5 != 1;) {
                string who;
                cin >> who;
                if (who == "1") {
                    cout << "Please input the gender you want to search for: ";
                    cin >> gender;
                    p->count_by_gender(gender);
                    pass5 = 1;
                } else if (who == "2") {
                    int which_class;
                    cout << "Please input the class number you want to search for: ";
                    cin >> which_class;
                    p->count_by_classnum(which_class);
                    pass5 = 1;
                } else if (who == "3") {
                    int age;
                    cout << "Please input the age you want to search for: ";
                    cin >> age;
                    p->count_by_age(age);
                    pass5 = 1;
                } else if (who == "4") {
                    cout << "Please input the department name you want to search for: ";
                    cin >> departmentname;
                    p->count_by_departmentname(departmentname);
                    pass5 = 1;
                } else{
                    cout << "Input invalid, please input again." << endl;
                }
            }
        } else if (selection == "6") {   //output to file
            p->output_file();
        } else if (selection == "114514") {
            stop = 1;
        } else {
            cout << "Input invalid, please input again." << endl;
        }
    }

}