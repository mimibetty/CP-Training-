#include <bits/stdc++.h>
using namespace std;

bool P[10000005];
int a[1000005];
bitset <1000005> bs;
int main() {
        freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    P[1] = 1;
    for (long long i=2; i<=sqrt(1e7); i++)
    {
        if (P[i] == 0)
        {
            for (long long j = i * i; j <= 1e7; j = j + i) P[j] = 1;
        }
    }
    
    int z;
    cin >> z;

    while (z--) {
        string s;
        cin >> s;
        long long cnt = 0;
        for (int bit = 1; bit < (1 << s.size()); bit++) {
            bs = bit;
            vector <int> t;
            for (int i = 0; i < s.size(); i++) {
                if (bs[i] == 1) {
                    t.push_back(s[i] - '0');
                }
            }
            sort (t.begin(), t.end());
            do {
                long long sum = 0;
                for (auto i : t) {
                    sum = sum * 10 + i;
                }
                if (P[sum] == 0) cnt++;

            }
            while (next_permutation(t.begin(), t.end())) ;

        }
        cout << cnt << endl;
    }
    return 0;
}