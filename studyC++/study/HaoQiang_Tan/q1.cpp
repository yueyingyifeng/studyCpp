/*
*          Author : yueyingyifeng
*      CreateDate : 2022-04-11 14:24
*     Description ：求最大公约数
*/
#include <iostream>
using namespace std;

int m1(int a,int b){
    int c{};

    while(a%b != 0){
        c = a % b;
        a = b;
        b = c;
    }

    return b;
}



int main(){
    int a = 3;
    int b = 6;
    cout << m1(a,b);
    return 0;
}