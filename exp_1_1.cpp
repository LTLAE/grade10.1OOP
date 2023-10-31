#include <iostream>
using namespace std;

class score{
    int num;
    double Math,English,Programming;
public:
    score();
    void inscore();
    void showscore();
    // void debug();
    score *next;
};

score *p,*head,*scanner,*create;
/*
 * *p for using the class.
 * *head for creating the head of the nodes.
 * *scanner for scanning through every node.
 * *create for creating a new node.
 */

score::score(){
    num=0;
    Math=0;
    English=0;
    Programming=0;
}

void score::inscore() {
    int inputnum = 0;
    double inputMathScore, inputEnglishScore, inputProgrammingScore;
    while(inputnum!=-114514){
        cout << "Please input student's number input -1 to exit:";
        cin >> inputnum;
        if(inputnum==-1) break;//exit input
        cout << "Please input student's Math score:";
        cin >> inputMathScore;
        cout << "Please input student's English score:";
        cin >> inputEnglishScore;
        cout << "Please input student's Programming score:";
        cin >> inputProgrammingScore;
        create=new score;
        scanner->next=create;
        create->next = NULL;
        create->num=inputnum;
        create->Math=inputMathScore;
        create->English=inputEnglishScore;
        create->Programming=inputProgrammingScore;
        scanner=create;//move *scanner one node ahead, so the node just created could be linked
    }
}

void score::showscore() {
    scanner=head->next; //move *scanner to the second node
    cout << "Number" << '\t' << "Math score" << '\t' << "English score"<< '\t' << "Programming score" << '\t' << "Average score" << endl;
    while (scanner->next!=NULL) {
        cout << scanner->num << '\t' << scanner->Math << '\t' << scanner->English << '\t' << scanner->Programming << '\t' << (scanner->Math + scanner->English + scanner->Programming) / 3 << endl;
        scanner=scanner->next;
    }
    cout << scanner->num << '\t' << scanner->Math << '\t' << scanner->English << '\t' << scanner->Programming << '\t' << (scanner->Math + scanner->English + scanner->Programming) / 3 << endl;
    //last node
    cout << "All students' information has shown." << endl;
    scanner=head->next; //move *scanner to the second node
}

/*
void score::debug(){
    cout << scanner->num << '\t' << scanner->Math << '\t' << scanner->English << '\t' << scanner->Programming << '\t' << (scanner->Math + scanner->English + scanner->Programming) / 3 << endl;
}
*/

int main() {
    cout << "Student information system." << endl;
    cout << "Please input students' information" << endl;
    head=new score;
    scanner=head;
    p->inscore();//aka initialize

    home:
    cout << "------------------------------------------------------------" << endl;
    cout << "Student information system." << endl;
    input:
    int selection;
    cout << "Input 1 to add more students' information." << endl;
    cout << "Input 2 to view students' information." << endl;
    // cout << "(Debug) Input 3 to view specific node." << endl;
    cout << "Input 114514 to exit. Your information would not be saved!" << endl;
    cin >> selection;
    switch (selection) {
        case 1:
            p->inscore();
            goto home;
        case 2:
            p->showscore();
            goto home;
            /*
            case 3:
                cout << "Input the node number you want to access:";
                cin >> debug;
                scanner=head->next;
                for(int t=0;t!=debug;t++) scanner=scanner->next;
                p->debug();
                goto home;
                */
        case 114514:
            abort();
        default:
            cout << "Input not correct, please input again." << endl;
            goto input;
    }
}
