//             ＿＿
//          ／＞　　フ
//          |   -  - l
//         ／`  = x =ノ
//        /　　　 　  |
//       /　   ヽ　　 ﾉ
//       │　   |　|　|
//    ／￣|　　 |　|　|
//    | (￣ヽ＿_ヽ_)__)
//    ＼二つ​
//       猫猫护体，永无BUG
//此项目保存着在猫猫注视下我写过的代码，测试，学习，数据结构等。
//不用的文件main函数会被注释
//这个文件是测试的，以及写这些提示用的
#include <iostream>
using namespace std;

class MyClass {
public:
    void FunB() {
        cout << "call FunB" << endl;
    }
    void pFun2(void (MyClass::* nonstatic)()) {
        (this->*nonstatic)();
    }
};

// int main() {
//     MyClass* obj = new MyClass;
//     void (MyClass:: * pFunB)() = &MyClass::FunB;

//     (obj->*pFunB)();

//     obj->pFun2(&MyClass::FunB);//嗯，此时这个函数归哪个对象已经一清二楚了
// }