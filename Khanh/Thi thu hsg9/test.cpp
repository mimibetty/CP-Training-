#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// Function to count pairs (x, y) such that a[x] + a[y] <= candidate
long long countPairs(const vector<int>& a, long long candidate) {
    long long count = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        // Use two-pointer technique
        int j = upper_bound(a.begin() + i + 1, a.end(), candidate - a[i]) - a.begin();
        count += (j - i - 1);
    }
    return count;
}

// Function to count triplets (x, y, z) such that a[x] + a[y] + a[z] <= candidate
long long countTriplets(const vector<int>& a, long long candidate) {
    long long count = 0;
    int n = a.size();
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            // Use binary search for the third element
            int k = upper_bound(a.begin() + j + 1, a.end(), candidate - a[i] - a[j]) - a.begin();
            count += (k - j - 1);
        }
    }
    return count;
}

int main() {
    // File input and output
    ifstream fin("KSET.INP");
    ofstream fout("KSET.OUT");

    int n, t, k;
    fin >> n >> t >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }

    // Sort the array
    sort(a.begin(), a.end());

    // Binary search for the k-th smallest sum
    long long left = a[0] + a[1]; // Smallest possible sum
    long long right = t == 2 ? a[n - 1] + a[n - 2] : a[n - 1] + a[n - 2] + a[n - 3]; // Largest possible sum
    long long result = -1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long count = (t == 2) ? countPairs(a, mid) : countTriplets(a, mid);

        if (count >= k) {
            result = mid;
            right = mid - 1; // Try for smaller sums
        } else {
            left = mid + 1; // Try for larger sums
        }
    }

    // Output the result
    fout << result << endl;

    return 0;
}

dp[n][0/1/2] tổng lớn nhất khi tính đến vị trí n 

ai ko đóng góp vào res 
ai đóng góp vào result giá trị ai 
ai đóng góp vào result giá trị ai * x

for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i-1][0] + a[i], 0, a[i]);
    dp[i][1] = max(dp[i-1][0] + a[i]*x,dp[i-1][1] + a[i]*x, 0, a[i] * x);
    dp[i][2] = max(dp[i-1][1] + a[i],dp[i-1][2] + a[i], 0, a[i]);
}