#include <iostream>
using namespace std;

template <typename T>
T max(T input1,T input2,T input3) {
    return input1 >= input2 ? input1 >= input3? input1:input3 :input2>=input3 ? input2:input3;
    //This is how it works. If you don't like the code above, use this.
    /*if (input1 >= input2) {
        if (input1 >= input3) return input1;
        else return input3;
    }else{
        if (input2 >= input3) return input2;
        else return input3;
    }*/
}
int main() {
    cout << "max(114,514,1919)=" << max(114,514,1919) << endl;
    cout << "max(114.514,19.19,8.10)=" << max(114.514,19.19,8.10) << endl;
    cout << "max('ya','ju','senpai')=" << max("ya","ju","senpai") << endl;
}
