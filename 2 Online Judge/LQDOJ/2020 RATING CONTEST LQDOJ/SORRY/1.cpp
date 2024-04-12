#include<bits/stdc++.h>
using namespace std;

int a[1000005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long k = n/2;

    cout << (k/2) * (k-k/2);
    return 0;
}