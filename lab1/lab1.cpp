#include <iostream>
using namespace std;
int main() {
    cout << "Type: Int " << endl;
    cout << "Size: " << sizeof(int) << endl;
    cout << "Limits: "<<"-2,147,483,648 to 2,147,483,647 "<< endl;
    cout << endl;
    cout << "Type: Unsigned Int "<< endl;
    cout << "Size: " << sizeof(unsigned int) << endl;
    cout << "Limits " << " 0 to 4,294,967,295 " << endl;

    int cnt_1 = 10, cnt_2 = 20;
    cout << cnt_1 - cnt_2 << endl;

    char ch_1 = '*', ch_2 = 1;
    cout << ch_1 + ch_2 << endl;

    bool b_1 = true, b_2 = false;
    cout << b_1 * b_2 << endl;

    float fl_1 = 10.5, fl_2 = 0.5;
    cout << fl_1 + fl_2 << endl;

}