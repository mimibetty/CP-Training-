#include<bits/stdc++.h>
using namespace std;


int a[100005];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int res = 0;
        int n;
        cin >> n;
        int even = 0, odd = 0; 
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) even++;
            else odd++;
        }
        vector<int>vt(n);
        vector<int>vt1(n);
        vector<int>vt2(n);
        vector<int>tar(n);

        
        if (abs(even-odd) >= 2) res = -1;
        else {
            int start = 0;
            for (int i = 1; i <= n; i+=2) tar.push_back(i);
             
            if (odd == even) {
        
                for (int i = 1; i <= n; i++) {
                    if (a[i] % 2 == 0) {
                        vt2.push_back(i);
                    }
                    else vt1.push_back(i);
                }
             }
             else {
                if (even > odd) {
                    for (int i = 1; i <= n; i++) {
                        if (a[i] % 2 == 0) vt.push_back(i);
                    }
                    
                }
                else {
                    for (int i = 1; i <= n; i++) {
                        if (a[i] % 2 != 0) vt.push_back(i);
                    }
                }
             }
        } 
        if (res != -1 && odd == even) {
            int res1= 0, res2 = 0;
            for (int i = 0 ; i < vt1.size(); i++) {
            res1 += abs(vt1[i] - tar[i]);
            }
            for (int i = 0 ; i < vt2.size(); i++) {
            res2 += abs(vt2[i] - tar[i]);
            }   
            res = min(res1,res2); 
        }
        else if (res != -1) {
            for (int i = 0 ; i < vt.size(); i++) {
             res += abs(vt[i] - tar[i]);
            }   
        }
        // for (int i = 0; i < vt.size(); i++) cout << vt[i] << ' ';
        // cout << endl;
        //     for (int i = 0; i < vt.size(); i++) cout << tar[i] << ' ';
        // cout << endl;

        cout << res <<  endl;
        vt.clear();
        tar.clear();
        vt1.clear();
        vt2.clear();
             
    }
    return 0;
}