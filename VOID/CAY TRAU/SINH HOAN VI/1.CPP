#include <bits/stdc++.h>
using namespace std;

int  a[15];
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    //  nhớ sort lại trước khi làm
    for  (int i = 1; i <= n; i++) a[i] = i;
    do {
        for (int  i = 1; i <= n; i++) cout << a[i];
        cout << endl;

    } while(next_permutation(a + 1, a + 1 + n) );

    // hoan vi string 
    string s = "ABCDEG";
    sort(s.begin(), s.end());

    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()) );

    return 0;
}