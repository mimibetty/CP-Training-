#include <bits/stdc++.h>

using namespace std;

set <long long> s;
// các số sắp xếp theo thứ tự tăng dần
// các số chỉ xuất hiện 1 lần

int main() {
    tim phan tu >= x trong set
    auto it = s.lower_bound(x);
    if (it == s.end()) cout << "Ko ton tai"; 
    else cout << *it;

    auto it = s.find(x); > tim vi tri x
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(9);
    s.insert(2);
    for (auto i: s) {
        cout << i << " ";
    }
    int a = s.count(x) ; 
    // a == 1 > x tồn tại trong set
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
    
    // check xem x co thuoc set ko?
    Auto it = s.find(x)
    If it != s.end > tồn tại x trong set;


    Multiset lưu được nhiều giá trị giống nhau 
    multiset<int> s;
s.insert(5);
s.insert(5);
s.insert(5);
cout << s.count(5) << "\n"; // 3

    s.erase(5);
cout << s.count(5) << "\n";   Xóa hết phần tử 5 trong set

    s.erase(s.find(5));
cout << s.count(5) << "\n";  Xóa phần tử 5 đầu tiên 

Nếu set time limit thì xài unordered_multiset;
    return 0;
}
