#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
long long a[100005];
int vt[200005];

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++) {
        long long n, res = 0;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vt[a[i]] = i;
        }

        sort(a + 1, a + 1 + n);

        for (int i = 1; i <= n-1; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] * a[j] > 2 * n) break;
                else if (a[i] * a[j] == vt[a[i]] + vt[a[j]]) {
                    res++;
                }
            }
        }
        //cout <<endl;
        cout << res <<endl;
        for (int i = 1; i <= n; i++) {
            vt[a[i]] = 0;
            a[i] = 0;
        }
    }   
    return 0;
}