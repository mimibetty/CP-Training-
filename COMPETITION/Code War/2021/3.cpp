#include <bits/stdc++.h>
using namespace std;
  
// Function to Count minimum swap
int countSwap(string s)
{
    // calculate length of string as n
    int n = s.length();
  
    // counter to count minimum swap
    int count = 0;
  
    // A loop which run till mid of
    // string
    for (int i = 0; i < n / 2; i++) {
        // Left pointer
        int left = i;
  
        // Right pointer
        int right = n - left - 1;
  
        // A loop which run from right
        // pointer towards left pointer
        while (left < right) {
            // if both char same then
            // break the loop.
            // If not, then we have to
            // move right pointer to one
            // position left
            if (s[left] == s[right]) {
                break;
            }
            else {
                right--;
            }
        }
  
        // If both pointers are at same
        // position, it denotes that we
        // don't have sufficient characters
        // to make palindrome string
        if (left == right) {
            return -1;
        }
  
        // else swap and increase the count
        for (int j = right; j < n - left - 1; j++) {
            swap(s[j], s[j + 1]);
            count++;
        }
    }
  
    return count;
}
  
// Driver code
int main()
{
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
  
    int ans1 = countSwap(s);
  
    reverse(s.begin(), s.end());
    int ans2 = countSwap(s);
  
    cout << max(ans1, ans2);
  
    return 0;
}