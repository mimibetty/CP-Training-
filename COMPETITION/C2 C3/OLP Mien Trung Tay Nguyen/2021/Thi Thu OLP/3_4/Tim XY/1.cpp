#include<bits/stdc++.h>
using namespace std;

bool ptts(long long x) {
    map<long long,long long> d;
    long long k = sqrt(x);
   
    for (int i = 2; i <= k; i++) {
        while (x % i == 0) {
            x /= i;
            d[i]++;
        }
    }
    if (x > 1) d[x]++;
    for (auto i : d) {
        if (i.second != 1) return 0;
    }
    return 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
        
    int t;
    cin >> t;

    for (int q = 1; q <= t; q++ ) {
        long long x;
        cin >> x;
        
        bool done1 = 0, done2 = 0;
        long long x1,x2;
        
        if (sqrt(x) <= 2) {
            x1 = 2;
            x2 = 3;
        }
        else {
            x2 = sqrt(x);
            x1 = sqrt(x) + 1;
        }

        while (done1 == 0) {
            if (ptts(x1) == 1) done1 = 1;
            else x1++;
        }

        while (done2 == 0 && x2 > 2) {
            if (ptts(x2) == 1) done2 = 1;
            else x2--;
        }

       //  cout << x1 << ' '<< x2 << endl;
        x1 *= x1;
        x2 *= x2;
        long long a = abs(x - x1);
        long long b = abs(x - x2);
        //cout << q << endl ;
       
        long long res = min(a,b);
        cout <<min(a,b);
        //cout << endl;
        cout << endl;
      //  cout << x1 - x;
    }
    return 0;
}/*
829514113
344497984
272677970
1774429717
311679945
1237628522
56108982
493533846
536279534
790708652*/