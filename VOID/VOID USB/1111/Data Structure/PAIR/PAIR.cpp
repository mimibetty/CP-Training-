#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> II;

II a[5005];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first.first >> a[i].first.second;
    }
    
    sort(a + 1, a + n + 1);
    
    return 0;
}
