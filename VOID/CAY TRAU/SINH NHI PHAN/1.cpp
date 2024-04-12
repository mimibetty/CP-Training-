#include <bits/stdc++.h>
using namespace std;

bitset<12>bs;

int main() {
     freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n ;
    cin >> n;
    string  cur;
    vector<string> ans;
    for (int bit  = 0; bit < (1 << n); bit++) {
        bs = bit;
        string cur;
        for (int i = 0; i < n; i++) {
            cur += bs[i] + '0';
        }
        ans.push_back(cur); 
    }

    sort(ans.begin(), ans.end());

    for (auto s: ans) {
        cout << s << "\n";
    }

    return 0;
}