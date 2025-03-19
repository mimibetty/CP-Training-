#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
ll res = 0;
const ll mod = 1e9 + 7;
vector<vector<ll>> valid_combinations;
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

void dequy(int i, int j) {
    if (i > n) {
        res = (res + 1) % mod;
        
        // Chuyển ma trận thành 3 bit
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
    
    // In ra các bộ 3 bit
    cout << "Các bộ 3 bit hợp lệ:" << endl;
    for(const auto& bits : valid_combinations) {
        cout << "bit1=" << bitset<5>(bits[0]) 
             << ", bit2=" << bitset<5>(bits[1])
             << ", bit3=" << bitset<5>(bits[2]) << endl;
    }
    
    cout << "Tổng số cách: " << res << endl;
    return 0;
}