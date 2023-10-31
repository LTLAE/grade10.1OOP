#include <iostream>
using namespace std;

template <typename array>
class A{
    array arr[5];
public:
    inline void change_arr(int pos /*position*/,array input){arr[pos]=input;}
    inline void get_arr(){
        for(int pos=0 /*position*/;pos<5;pos++) {cout << arr[pos] << '\t';}
        cout << endl;
    }
    inline void sum_arr(){cout << "Sum of the array is " << arr[0]+arr[1]+arr[2]+arr[3]+arr[4] << endl;}
    inline void avg_arr(){cout << "Average of the array is " << (arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5 << endl;}
    //in this case, array is short. So I didn't use recursive way to sum them.
};

int main() {
    A<int> int_obj;
    A<double> double_obj;
    A<char> char_obj;
    //input some data
    int_obj.change_arr(0,11);
    int_obj.change_arr(1,4);
    int_obj.change_arr(2,5);
    int_obj.change_arr(3,14);
    int_obj.change_arr(4,19);
    //out put the data
    int_obj.get_arr();
    int_obj.sum_arr();
    int_obj.avg_arr();

    double_obj.change_arr(0,11.4);
    double_obj.change_arr(1,51.4);
    double_obj.change_arr(2,1.9);
    double_obj.change_arr(3,1.9);
    double_obj.change_arr(4,8.10);

    double_obj.get_arr();
    double_obj.sum_arr();
    double_obj.avg_arr();

    char_obj.change_arr(0,'y');
    char_obj.change_arr(1,'j');
    char_obj.change_arr(2,'s');
    char_obj.change_arr(3,'p');
    char_obj.change_arr(4,'i');

    char_obj.get_arr();
    char_obj.sum_arr();
    char_obj.avg_arr();

}
