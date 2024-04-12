#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int a,b;

bool check(int p, int q, int x) {
    int y = a + x - p;
    if (p - x < 0 || p - x > a) return 0;
    if (q - y < 0 || q - y > b) return 0;
    if (y < 0 || y > q) return 0;
    return 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while (t--) {
        cin >> a >> b;

        set<int>res;
        int p,q;    // p = a serve, q = b serve 
        
        if ((a + b) % 2 == 0) {
            p = (a+b)/2;  
            q = (a+b)/2; 
            
            for (int x = 0; x <= p; x++) {
                if(check(p, q, x) == 1) {
                    res.insert(a - p + 2*x);
                }
            }
        } 
        else {
            //th1
            p = (a+b)/2  + 1;
            q = (a+b)/2;

            for (int x = 0; x <= p; x++) {
                if (check(p, q, x) == 1) {
                    res.insert(a - p + 2*x);
                }    
            }

            p = (a+b)/2;
            q = (a+b)/2 + 1;

            for (int x = 0; x <= p; x++) {
                if (check(p, q, x) == 1) {
                    res.insert(a - p + 2*x);
                }    
            }
        }
        cout << res.size() << endl;
        for (auto i : res) cout << i << ' ';
        cout << endl;
        res.clear();
    } 
    return 0;
}