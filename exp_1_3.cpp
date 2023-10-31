#include <iostream>
using namespace std;

class imaginary{
    double x,y;
public:
    friend imaginary add(imaginary,imaginary);
    friend imaginary sub(imaginary,imaginary);
    friend imaginary mul(imaginary,imaginary);
    friend imaginary div(imaginary,imaginary);
    void input(double,double);
    static void show(char,imaginary,imaginary);
    /*void debug() const{
        cout << x << '\t' << y << endl;
    }       */
};

imaginary add(imaginary a, imaginary b){
    imaginary result{};
    result.x= a.x + b.x;
    result.y= a.y + b.y;
    return result;
}

imaginary sub(imaginary a, imaginary b){
    imaginary result{};
    result.x= a.x - b.x;
    result.y= a.y - b.y;
    return result;
}

imaginary mul(imaginary a, imaginary b){
    imaginary result{};
    result.x= a.x * b.x - a.y * b.y;
    result.y= a.x * b.y - a.y * b.x;
    return result;
}

imaginary div(imaginary a, imaginary b){
    imaginary result{};
    result.x= (a.x * b.x + a.y * b.y) / (b.x * b.x + b.x * b.y);
    result.y= (a.y * b.x - a.x * b.y) / (b.x * b.x + b.y * b.y);
    return result;
}

void imaginary::input(double inputr, double inputi) {
    x=inputr;
    y=inputi;
}

void imaginary::show(char cal, imaginary num1, imaginary num2) {
    imaginary result{};
    cout << "Your result is ";
    if (cal=='+'){
        result = add(num1,num2);
        cout << result.x << "+" << result.y << "i" << endl;
    }
    if (cal=='-'){
        result = sub(num1,num2);
        cout << result.x << "+" << result.y << "i" << endl;
    }
    if (cal=='*'){
        result = mul(num1,num2);
        cout << result.x << "+" << result.y << "i" << endl;
    }
    if (cal=='/'){
        result = div(num1,num2);
        cout << result.x << "+" << result.y << "i" << endl;
    }
}

int main() {
    imaginary a{},b{}, *p;
    char cal;
    double bridger, bridgei; //pass input to friend input function
    cout << "Input first complex number. Separate real and imag part with space." << endl;
    cin >> bridger >> bridgei;
    a.input(bridger, bridgei);
    cout << "Your first number is " << bridger << "+" << bridgei << "i" << endl;
    cal:
    cout << "Input + - * or /" << endl;
    cin >> cal;
    if (cal != '+'){
        if (cal != '-') {
            if (cal != '*') {
                if (cal != '/') {
                    cout << "Check your input! ";
                    goto cal;
                }
            }
        }
    }
    cout << "Input second complex number. Separate real and imag part with space." << endl;
    cin >> bridger >> bridgei;
    b.input(bridger, bridgei);
    cout << "Your second number is " << bridger << "+" << bridgei << "i" << endl;


    // p->debug();
    p->show(cal,a,b);

}
