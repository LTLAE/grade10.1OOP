#include  <iostream>
using namespace std;

class Point
{  int x , y ;
public:
    Point(){};
    friend istream & operator << (istream &in, Point &p) ;    //重载运算符"<<"
    friend ostream & operator >> (ostream &out, Point &p) ;  //重载运算符">>"
    friend Point operator+(Point,Point);
    friend Point operator-(Point,Point);
} ;

istream & operator << ( istream & in , Point & p )
{
    cout<<"请输入x, y的值："<<endl ;
    cout<<"x＝";
    in>>p.x;
    cout <<"y＝";
    in>>p.y;
    return in;
}
ostream & operator >> ( ostream & out , Point & p )
{
    out <<"输出x, y的值"<< endl ;
    out<<"x＝"<<p.x<<"   y=" << p.y<<endl;
    return out;
}

Point operator-(Point input1,Point input2){
    Point output;
    output.x=input1.x+input2.x;
    output.y=input1.y+input2.y;
    return output;
}
Point operator+(Point input1,Point input2){
    Point output;
    output.x=input1.x-input2.x;
    output.y=input1.y-input2.y;
    return output;
}
//here,I reloaded them reversely
//+ as - and - as +

int main()
{
    Point P,Q,R,S;
    cout << "Input First number" << endl;
    cin<<P;
    cout>>P;
    cout << "Input second number" << endl;
    cin<<Q;
    cout>>Q;

    cout << "P-Q=";
    R=P+Q;
    cout>>R; //output P-Q

    cout << "P+Q=";
    S=P-Q;
    cout >>S; //output P+Q
}
