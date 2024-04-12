#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
int a[10005];

int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        map<int,int>cnt;
        int val =-1;
        int cs = 0;
        cin >> n;
        string s;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            cin >> a[i];
            cnt[a[i]]++;
        }

        for (int i = 1; i <= n; i++) {
            if (cnt[a[i]] > val) {
                cs = a[i];
                val = cnt[a[i]];  
            } 
            else if (cnt[a[i]] == val) cs = min(a[i], cs);  
        }
        cout << cs << endl;
        cnt.clear();
    }
    return 0;
}