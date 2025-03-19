#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minPairingCost(vector<int>& a, int k) {
    int n = a.size();
    sort(a.begin(), a.end());

    int minCost = INT_MAX;
    // Thử từng phần tử để bỏ qua
    for (int skip = 0; skip < n; ++skip) {
        int currentCost = 0;
        for (int i = 0; i < n; i++) {
            if (i == skip) continue;  // bỏ qua phần tử này
            if (i == skip - 1 && i + 1 < n) continue;  // bỏ qua cặp này nếu phần tử trước đó là phần tử bị bỏ qua
            if (i + 1 < n) {
                currentCost += abs(a[i] - a[i + 1]) / k;
                ++i;  // Tăng i để bỏ qua phần tử đã ghép
            }
        }
        minCost = min(minCost, currentCost);
    }

    return minCost;
}

int main() {
    vector<int> a = {1, 4, 10, 22, 28};
    int k = 3;
    cout << "Minimum cost: " << minPairingCost(a, k) << endl;
    return 0;
}