#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/453/problem/B

using ll = long long;
const int MAX_N = 102;
const int MAX_VAL = 60;
const int MAX_MASK = (1 << 17);
const int INF = 1e9;

int a[MAX_N];
vector<int> factor[MAX_VAL + 1];
vector<int> factor2[MAX_VAL + 1];
const int prime[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
int pos[MAX_VAL + 1];

bool isBitSet(int a, int x) {
    return (a >> x) & 1;
}

bool allBitsSet(int a, const vector<int>& b) {
    for (int x : b) {
        if (isBitSet(a, x) == 0) {
            return false;
        }
    }
    return true;
}

int flipBits(int a, const vector<int>& b) {
    for (int pos : b) {
        a ^= (1 << pos);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(MAX_MASK, INF));
    vector<vector<int>> prevVal(n + 1, vector<int>(MAX_MASK, -1));

    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int val = 1; val <= MAX_VAL; val++) {
            for (int bit = 0; bit < MAX_MASK; bit++) {

                if (allBitsSet(bit, factor2[val]) == true) {
                    int preBit = flipBits(bit, factor2[val]);
                    if (dp[i][bit] > abs(val - a[i]) + dp[i-1][preBit]) {

                        dp[i][bit] = abs(val - a[i]) + dp[i-1][preBit];
                        prevVal[i][bit] = val;
                        
                    }
                }
            }
        }
    }

    int res = INF;
    int finalBit = -1;

    for (int bit = 0; bit < MAX_MASK; bit++) {
        if (res > dp[n][bit]) {
            res = dp[n][bit];
            finalBit = bit;
        }
    }

    // cout << "Minimum difference sum: " << res << endl;

    vector<int> selectedVals(n + 1);
    int currentBit = finalBit;
    for (int i = n; i >= 1; i--) {
        selectedVals[i] = prevVal[i][currentBit];
        if (selectedVals[i] != 1) {
            currentBit = flipBits(currentBit, factor2[selectedVals[i]]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << selectedVals[i] << " ";
    }
    cout << endl;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 1; i <= MAX_VAL; i++) {
        int tmp = i;
        for (int j = 2; j <= i; j++) {
            if (tmp % j == 0) {
                factor[i].push_back(j);
                while (tmp % j == 0) tmp /= j;
            }
        }
    }

    for (int i = 0; i < 17; i++) {
        pos[prime[i]] = i;
    }

    for (int i = 1; i <= MAX_VAL; i++) {
        for (auto j : factor[i]) {
            factor2[i].push_back(pos[j]);
        }
    }

    solve();


    //  for (int i = 1; i <= MAX_VAL; i ++) {
    //     cout << "bit  " << i << endl;
    //     for (int j = 0; j < factor[i].size(); j++) {
    //         cout <<"{ " <<  factor2[i][j] << ' ' << factor[i][j] << " } \n";
    //     }
    //     cout << endl;
    // }


    // int x = 103234; 
    // vector<int>f = {0,1,2};
    // bs = x;
    // cout << bs << endl;

    // int y = flipBits(x,f);
    // cout << y << endl;
    // bs = y;
    // cout << bs << endl;
    return 0;
}