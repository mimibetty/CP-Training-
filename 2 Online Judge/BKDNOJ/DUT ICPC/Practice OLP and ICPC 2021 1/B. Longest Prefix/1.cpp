#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
int cnt[200];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        int res = 0;
        cin >> a;
        cin >> b;
        
        for (int i = 0; i < b.size(); i++) cnt[b[i]]++;

        for (int i = 0; i < a.size(); i++) {
            if (cnt[a[i]] > 0) {
                cnt[a[i]]--;
                res++;
            }
            else {
                break;
            }
        }
        cout << res << endl;
        
        for (char i = 'a'; i <= 'z'; i++) {
            cnt[i] = 0;
        }           
    }
    return 0;
}