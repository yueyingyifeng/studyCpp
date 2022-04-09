/*
*          Author : yueyingyifeng
*      CreateDate : 2022-04-06 17:19
*     Description ：
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<long> Fb(int length){
    vector<long> f(3,1);
    for(int n{};n<length;n++){
        f.push_back(f[n]+f[n+1]+f[n+2]);
    }
    return f;
}

int result(int index){
    cout << ":" << Fb(index).back() << endl;
    int n{Fb(index)[index]};
    int r{};
    while(n  > 0){
        n %= 3;
        r++;
    }
    return  r;
}

//int main(){
//    for(int n: Fb(100)){
//        cout << n << " ";
//    }
//    cout << endl << Fb(7)[6] % 3;
//    return 0;
//}