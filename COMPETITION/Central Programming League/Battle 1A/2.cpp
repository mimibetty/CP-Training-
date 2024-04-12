#include <bits/stdc++.h>

using namespace std;

int main ()
{
     if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    long n, k;
    cin >> n >> k;
    stack <int> S;
    for (long i = 1; i <= n; i++) {
        char a;
        cin >> a;
        int num = a - '0';
        if (S.empty() > 0) S.push(num);
        else {
            while (!S.empty() && num > S.top() && k>0) {
                S.pop();
                k--;
            }
            S.push(num);
        }
    }
    while (k > 0 && !S.empty())
    {
        S.pop();
        k--;
    }
    vector <int> small;
    while (!S.empty()) {
        int tmp = S.top();
        S.pop();
        small.push_back(tmp);
    }
    for (long i = small.size() - 1; i >= 0; i--) cout << small[i];
    return 0;
}