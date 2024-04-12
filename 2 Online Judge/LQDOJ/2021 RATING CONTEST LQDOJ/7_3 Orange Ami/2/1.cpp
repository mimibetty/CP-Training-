#include <bits/stdc++.h>
using namespace std;

long long pw(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long m = pw(x, n / 2);
    if (n % 2 == 0) {
        return m * m;
    }
    return m * m * x;
}
bitset<12>bs;
long long a[5005];
long long b[5005];

int main() {
     freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n ;
    cin >> n;
    int vt1 = 0, vt2= 0;
    long long sum =0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] * pw(n+1,i-1);
        sum += b[i];
    }

    long long res = sum;
    int res1 = 0, res2= 0;

    string  cur;
    vector<string> ans;
    for (int bit  = 0; bit < (1 << n); bit++) {
        int count = 0;
        bs = bit;
        string cur;
        for (int i = 0; i < n; i++) {
            cur += bs[i] + '0';
            if (cur[i] == '1') {
                count++;
            }
            if (cur[i] == '1' && count == 1) vt1 = i + 1;
            else if (cur[i] == '1' && count == 2) vt2 = i + 1;
        }
        ans.push_back(cur);
        if (count == 2) {
            long long tong = sum; 
            tong -= b[vt1];
            tong -=b[vt2];
            tong += a[vt1] * pw(n+1,n-vt2);
            tong += a[vt2] * pw(n+1,n-vt1);
            if (tong > res) {
                res = tong;
                res1 = vt1;
                res2 = vt2;
            }
            
        //    cout << tong << ' '<< vt1 << ' ' <<vt2<<  endl;
        } 
    }

    for (int i = 1; i <= n; i++) {
        if (i == res1) cout <<a[res2];
        else if (i == res2) cout << a[res1];
        else cout <<a[i];
        cout << ' ';
    }
    /*sort(ans.begin(), ans.end());

    for (auto s: ans) {
        cout << s << "\n";
    }*/
    //cout << res;
    return 0;
}