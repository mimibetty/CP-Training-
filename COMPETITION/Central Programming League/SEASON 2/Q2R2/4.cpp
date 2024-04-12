#include<iostream>
using namespace std;
 
void Func(int& x, int y = 200) {
    int z = x + y;
    x += z;
    if (y != 200) cout << z << x << y;
} 
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    enum Exam
    {
        Jan = 1, FEB, MAR,
        APR, MAY, JUN,
        JUL, AUG, SEP,
        OCT, NOV, DEC
    }
    for (int i = MAR; i <= NOV; ++i) cout << i;
    return 0;
}