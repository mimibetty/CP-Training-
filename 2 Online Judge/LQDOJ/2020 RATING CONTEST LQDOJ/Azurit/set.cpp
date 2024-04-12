#include <bits/stdc++.h>

using namespace std;

set <long long> s;
// các số sắp xếp theo thứ tự tăng dần
// các số chỉ xuất hiện 1 lần

int main() {
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(9);
    s.insert(2);
    for (auto i: s) {
        cout << i << " ";
    }
    cout << endl;
    s.erase(4);
    s.insert(7);
    for (auto i: s) {
        cout << i << " ";
    }
    cout << endl;
    cout << s.size() << endl;
    cout << s.count(4) << endl;
    long long minVal = *s.begin(); // số nhỏ nhất
    cout << minVal << endl;
    long long maxVal = *(--s.end()); // số lớn nhất
    cout << maxVal << endl;
    cout << *(++s.begin()) << endl; // số nhỏ thứ 2
    cout << *(--(--s.end())) << endl; // số lớn thứ 2
    return 0;
}
