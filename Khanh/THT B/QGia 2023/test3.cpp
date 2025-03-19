#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
ll res = 0;
const ll mod = 1e9 + 7;
vector<vector<ll>> valid_combinations;
vector<vector<ll>> pairings;

ll a[105][105];

bool check(int i, int j) {
    if (i >= 3 && a[i][j] == a[i-1][j] && a[i-1][j] == a[i-2][j]) return false;
    if (j >= 3 && a[i][j] == a[i][j-1] && a[i][j-1] == a[i][j-2]) return false;
    if (i >= 2 && j >= 2 && a[i][j] == a[i-1][j] && a[i-1][j] == a[i][j-1]) return false;
    if (i >= 2 && j >= 2 && a[i][j] == a[i-1][j] && a[i-1][j] == a[i-1][j-1]) return false;
    if (i >= 2 && j <= m - 1 && a[i][j] == a[i-1][j] && a[i-1][j] == a[i-1][j+1]) return false;
    if (i >= 2 && j >= 2 && a[i][j] == a[i-1][j-1] && a[i-1][j-1] == a[i][j-1]) return false;
    return true;
}

bool canPair(const vector<ll>& mask1, const vector<ll>& mask2) {
    return (mask1[1] == mask2[0]) && (mask1[2] == mask2[1]);
}

void findPairings() {
    int size = valid_combinations.size();
    pairings.resize(size);
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (canPair(valid_combinations[i], valid_combinations[j])) {
                pairings[i].push_back(j);
            }
        }
    }
}

void dequy(int i, int j) {
    if (i > n) {
        res = (res + 1) % mod;
        
        vector<ll> bits(3, 0);
        for(int col = 1; col <= m; col++) {
            ll bit_value = 0;
            for(int row = 1; row <= n; row++) {
                bit_value = (bit_value << 1) | a[row][col];
            }
            bits[col-1] = bit_value;
        }
        valid_combinations.push_back(bits);
        return;
    }
    
    if (j > m) {
        dequy(i + 1, 1);
        return;
    }
    
    a[i][j] = 1;
    if (check(i, j)) {
        dequy(i, j + 1);
    }
    
    a[i][j] = 0;
    if (check(i, j)) {
        dequy(i, j + 1);
    }
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    dequy(1, 1);
    
    cout << "Các bộ 3 bit hợp lệ:" << endl;
    for(const auto& bits : valid_combinations) {
        cout << "bit1=" << bitset<5>(bits[0]) 
             << ", bit2=" << bitset<5>(bits[1])
             << ", bit3=" << bitset<5>(bits[2]) << endl;
    }
    
    findPairings();
    
    cout << "\nCác cặp có thể ghép với nhau:" << endl;
    for (int i = 0; i < pairings.size(); ++i) {
        cout << "Mask " << i << " có thể ghép với: ";
        cout << pairings[i][0] << ' ' << pairings[i][1] << ' ' << pairings[i][2] << endl;
        for (int j : pairings[i]) {
            cout << j << " ";
            // cout << pairings[j][0] << ' ' << pairings[j][1] << ' ' << pairings[j][2] << endl;
        }
        cout << endl;
    }
    
    cout << "\nTổng số cách: " << res << endl;
    return 0;
}

// dp[3][mask] = 1
// for i 4 - > n 
//     for (mask = 0; i < valid_combinations.size(); i++) {
//         for (int mask2 : pairings[mask]) {
//             dp[i][mask] += dp[i-1][mask2]
//         }
//     }

// for j in mask 
//     sum += dp[n][j];

dp[i][18] = dp[i-1][1] 
dp[i][19] = dp[i-1][10] + dp[i-1][14]

r - l = x
