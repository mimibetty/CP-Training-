#include <bits/stdc++.h>
using namespace std;

int cnt[15];
int cntMin[15];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string a, b;
    cin >> a >> b;

    int minDi = b[0] - '0';
    for (int i = 0; i < a.size(); i++) {
        cnt[a[i] - '0']++;
        cntMin[a[i] - '0']++;
        if (a[i] - '0' > 0) minDi = min(minDi, a[i] - '0');
    }

    string maxVal;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 9; j > b[i] - '0'; j--) {
            for (int k = 1; k <= cnt[j]; k++) {
                maxVal += j + '0';
            }
            cnt[j] = 0;
        }
        maxVal += b[i];
    }

    for (int i = 9; i >= 0; i--) {
        for (int j = 1; j <= cnt[i]; j++) {
            maxVal += i + '0';
        }
    }

    string minVal;
    minVal += minDi + '0';
    if (cntMin[minDi] > 0) cntMin[minDi]--;

    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j <= b[i] - '0'; j++) {
            for (int k = 1; k <= cntMin[j]; k++) {
                minVal += j + '0';
            }
            cntMin[j] = 0;
        }
        minVal += b[i];
    }

    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j <= cntMin[i]; j++) {
            minVal += i + '0';
        }
    }

    cout << minVal << "\n" << maxVal;
    return 0;
}