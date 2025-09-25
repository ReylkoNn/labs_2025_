#include <iostream>
using namespace std;
int main() {
    int base_1,base_2,height;
    cout << "Enter base_one,base_two and height" << endl;
    cin >> base_1 >> base_2 >> height;
    if (0<base_1 ) {
        if (base_2 < 100) {
            if (0<height && height < 100) {
                int half_sum_base = (base_1 + base_2)/ 2;
                int S = half_sum_base * height;
                cout << "The area of your trapezoid: " << S << endl;
            } else {
                cout << "incorrect size(height)" << endl;
            }
        }else {
            cout << "incorrect size(base_two)" << endl;
        }
    }else {
        cout << "incorrect size(base_one)" << endl;
    }


}