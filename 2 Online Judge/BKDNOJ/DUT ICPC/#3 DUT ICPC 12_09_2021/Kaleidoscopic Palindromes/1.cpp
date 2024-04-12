#include<bits/stdc++.h>
using namespace std;

// bool checkpalin(long long x) {
//     string a;
//     string b = to_string(x);
//     a = b;
//     reverse(a.begin(), a.end());

//     return (a==b);
// }

bool checkpalin(string x) {
    string a;
    a = x;
    reverse(a.begin(), a.end());

    return (a == x);
}


string convert(long long n, long long k) {
    
    string s;
    while (n > 0) {
        s += (char) (n%k + '0');
        n/= k;
    }

    reverse(s.begin(),s.end());
    return s;
}

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    long long a,b,k;
    cin >> a >> b >> k;
    long long cnt = 0;
    bool check = 0;
    
    if (k == 2 || k == 3) {
        for (long long i = a; i <= b; i++) {
            check = 1;
            for (int j = 2; j <= k; j++) {
                if (checkpalin(convert(i,j)) == 0) {
                    check = 0;
                    break;
                } 
            }
            if (check == 1) {
                cnt++;
                // cout << i <<endl;
            }
        }
        cout << cnt;
     }
     else {
         if (a == 0) cnt++;
         if (a <= 1 && b >= 1) cnt++;
         cout << cnt;
     }
    
    return 0;
}