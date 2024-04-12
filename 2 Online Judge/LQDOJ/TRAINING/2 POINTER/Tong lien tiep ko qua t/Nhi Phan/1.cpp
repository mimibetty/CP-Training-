#include<bits/stdc++.h>
using namespace std;


const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;
int a[100005];
int ps[100005];

int main() {
     freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;  
    long long k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }    

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int lower = i, upper = n;
        while (lower < upper) {
            int mid = (lower + upper) / 2;
            if (ps[mid] - ps[i-1] >= k) {
                upper = mid;
            }
            else {
                lower = mid + 1;
            }
        }
        cout << i << ' ' << lower << endl;
        if (ps[lower] - ps[i] <= k) res= max(res, lower - i + 1);
    }
    cout << res;
    return 0;
}