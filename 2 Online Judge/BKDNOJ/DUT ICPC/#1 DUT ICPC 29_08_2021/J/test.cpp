#include<bits/stdc++.h>
using namespace std;

// ThankMin
//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s = "a";
    long long num = 0;
    long long k;
    cin >> k;

    while (num < k) {
        if (s[s.size()-1] == 'a') s+='z';
        else s+='a';
        num+=25;
    }
    long long plus = num - k;
    if (plus > 0) {
        if (plus % 2 == 0) {
            if (s.size() >= 3) s[1] -= (plus/2);
            else s[1] -= plus;
        }
        else {
            s[1] -= (plus/2);
            if (s[s.size()-1] == 'a') s[s.size()-1] = 'b';
            else s[s.size()-1] = 'y';   
        }
    } 
    cout << s;
    //cout << plus;
    return 0;
}