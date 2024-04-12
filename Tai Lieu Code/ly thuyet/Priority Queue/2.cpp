#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_
    stdio(0);
    cin.tie(NULL);
    priority_queue<int>pq;
// tuong duong
priority_queue<int, vector<int>, less<int> >pqMax;
// trai nguoc
priority_queue<int, vector<int>, greater<int> >pqMin;
         
    pqMin.push(2);
    pqMin.push(4);
    pqMin.push(8);
    for (auto i : pqMin) cout << i << ' ';
    return 0;
}

// 1e5 vo tu ,        1e6  nen priority q thay vi set
top()
pop()
push(a)
size()
empty()