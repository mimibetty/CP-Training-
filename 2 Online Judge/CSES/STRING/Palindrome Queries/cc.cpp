#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<bool> snt(1000005);

void check(int n) {
    fill(snt.begin(), snt.end(), true);
    snt[0] = snt[1] = false;
    int limit = sqrt(n); // Precompute sqrt(n)
    for (int i = 2; i <= limit; i++) {
        if (snt[i]) {
            for (int j = i * i; j <= n; j += i) {
                snt[j] = false;
            }
        }
    }
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    }

    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));
    int res = 0;
    check(1000000);

    // Precompute prefix sums
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + (1 - snt[a[i][j]]);
        }
    }

    // Process each cell
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int low = res, high = min(i, j), best = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                int y = i - mid;
                int z = j - mid;
                if (y < 1 || z < 1) {
                    high = mid - 1;
                    continue;
                }
                int sum = ps[i][j] - ps[y - 1][j] - ps[i][z - 1] + ps[y - 1][z - 1];
                if (sum <= 1) {
                    best = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            res = max(res, best + 1);
        }
    }
    
    printf("%d", res * res);
    return 0;
}