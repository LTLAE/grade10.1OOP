#include <iostream>
using namespace std;

class matrix{
    double mat[10]; //For the matrix is quite small, use 1-dimension array is enough
    //use two-dimension array would cause many trouble in IO that can be avoided
public:
    friend matrix operator+ (matrix,matrix);
    friend istream & operator >> (istream &ip,matrix &input);
    friend ostream & operator << (ostream &op,const matrix &output);
};

matrix operator+(matrix input1,matrix input2){
    matrix output;
    for(int t=1;t<10;t++){
        output.mat[t]=input1.mat[t]+input2.mat[t];
    }
    return output;
}   //simply reload +
istream & operator >> (istream &ip,matrix &input){
    cout << "Input numbers of first row, separate with space." << endl;
    ip >> input.mat[1] >> input.mat[2] >> input.mat[3];
    cout << "Input numbers of second row, separate with space." << endl;
    ip >> input.mat[4] >> input.mat[5] >> input.mat[6];
    cout << "Input numbers of third row, separate with space." << endl;
    ip >> input.mat[7] >> input.mat[8] >> input.mat[9];
    return ip;
}   //I don't want to use for() for input because in such small matrix, using a number of for() circle is complicated
ostream & operator << (ostream &op,const matrix &output){
    cout << "Your result is" << endl;
    op << output.mat[1] << '\t' << output.mat[2] << '\t' << output.mat[3] << endl;
    op << output.mat[4] << '\t' << output.mat[5] << '\t' << output.mat[6] << endl;
    op << output.mat[7] << '\t' << output.mat[8] << '\t' << output.mat[9] << endl;
    return op;
}   //also directly output, more simple and clear


int main() {
    matrix m1,m2;
    cout << "Input first matrix:" << endl;
    cin >> m1;
    cout << "Input second matrix:" << endl;
    cin >> m2;
    cout << m1+m2 << endl;
}
