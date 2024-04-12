#include<bits/stdc++.h>
using namespace std;
 
int a[200005],b[200005];
 
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    multiset<int>s;
    int n,m,k;
    cin >> n >> m >> k;
 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
 
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    
   /* 
    for (auto i :s) cout << i << ' '; 
        cout << endl;
    for (int i = 1; i <= m; i++) cout <<b[i] << ' ';
        cout << endl;*/
 
    int res=0;
    for (int i = 1; i <= m; i++) {
        long long upper = b[i] + k;
        long long lower = b[i] - k;
        auto j = s.lower_bound(lower);
                
        if (j == s.end()) continue;
        if (*j > upper) continue; 
        //cout <<i << ' ' << *j <<endl;
        res++;
        s.erase(s.find(*j));
    }
    cout <<res;
    return 0;
}