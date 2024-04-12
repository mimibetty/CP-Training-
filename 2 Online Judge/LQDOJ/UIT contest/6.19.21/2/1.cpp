#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long k;
    cin >> k;

    long long can = sqrt(k);
    long long bonus = sqrt(k + can);
    cout << k + can +  (bonus - can);
    return 0;
}