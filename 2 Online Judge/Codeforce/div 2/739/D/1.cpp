#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

long long k2[65];
int com(long long a, long long b) {
    int cnt =0;
    string s1,s2;
    long long k1 = a,k2= b;
    while (k1 > 0) {
        s1 += (k1%10) +'0';
        k1/=10;
    }
    while (k2 > 0) {
        s2 += (k2%10) +'0';
        k2/=10;
    }
    int vt1 = s1.size()-1;
    int vt2 = s2.size()-1;
    int sl1 = vt1+1;
    int sl2 = vt2+1;
    while (vt1 >= 0) {
        if (vt1 < 0 || vt2 < 0) break;
        if (s1[vt1] == s2[vt2]) {
            cnt++;
            vt1--;
            vt2--;
        } 
        else {
            vt2--;
        }
    }
    if (cnt == sl1) {
        return sl2 -cnt;
    }
    else {
        return abs(sl2 - cnt) + abs(sl1-cnt);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    long long val = 1;
    for (int i = 1; i <= 60; i++) {
        val *= 2;
        k2[i] = val;
    }
    k2[0] = 1;
    while (t--) {
        int res = 1e9;
        long long n;
        cin >> n;

        for (int i = 0; i <= 60; i++) {
            res = min(res, com(k2[i],n));         
        }
        cout << res << endl;
    }    
    return 0;
}
