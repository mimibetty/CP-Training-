#include <bits/stdc++.h>
using namespace std;

bitset<20>bs;
long long a[100005];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,k ;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<string> ans;
    long long res = 0;
    for (int bit  = 0; bit < (1 << n); bit++) {
        bs = bit;
        // cout << bs << endl;
        vector <long long>ar;

        for (int i = 0; i < n; i++) {
            if (bs[i] == 1) ar.push_back(a[i+1]);
        }
        bool check = 1;
        for (int i = 0; i < (ar.size()-1); i++) {
            bool done = 1;
            for (int j = i+1; j < ar.size(); j++) {
                if ((ar[i] + ar[j])%k == 0) {
                    done = 0;
                    check = 0;
                    break;
                } 
            }
            if (done == 0) break;
        }

        long long x = ar.size();
        if (check == 1) {
            res = max(res, x);
            // for (auto j : ar) cout << j << ' ' ;
            // cout << endl;  
        } 
        ar.clear();
        // ans.push_back(cur); 
    }
    cout << res;
    return 0;
}