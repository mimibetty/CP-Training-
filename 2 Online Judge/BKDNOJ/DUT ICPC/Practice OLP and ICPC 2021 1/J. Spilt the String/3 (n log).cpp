#include<bits/stdc++.h>
using namespace std;

int trace[100005]; // trace[i] là ước NT nhỏ nhất của i

// faster
void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (trace[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (trace[j] == 0) {
                    trace[j] = i;
                }
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (trace[i] == 0) {
            trace[i] = i;
        }
    }
}

bool check(string &s,int sl , int n) {
    for (int j = sl-1; j < n; j+= (sl+1)) {
        // cout << "VT" << ' ' << j << endl;
        // cout << s[j] << ' ' << s[j+1] << endl;
        if (s[j] >= 'a' && s[j] <= 'z') {
                if (s[j+1] ==  '#') return 1;
                if (s[j+1] == ' ')  {

                }
                if (s[j+1] >= 'a' && s[j+1] <= 'z') return 0;
        }
        else return 0;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    sieve(1e5);
    cin.ignore();

    //size + 1 = x (len+1)
    // x la uoc size + 1 
    // x thoa thi x/2 , x/3 thoa
    while (t--) {
        string s;
        getline (cin, s);

        vector<int>x;
        vector<int>len;
        int n = s.size();
        
        for (int i = 2; i <= sqrt(n+1); i++) {
            if ((n+1) % i == 0) {
                if (trace[(n+1)/i] == (n+1)/i) x.push_back((n+1)/i);
                if (trace[i] == i) x.push_back(i);
            } 
        }

        for (auto i : x) {
            len.push_back((n+1)/i);
        }

        bool ok = 0;
        s+= '#';

        for (auto i : len) {
            int sl = i-1;
            if (check(s,sl,n) == 1) {
                ok = 1;
                break;
            }
        }

        if (ok == 1) cout <<"YES";
        else cout << "NO";
        cout << endl;
        x.clear();
        len.clear();
    }
    return 0;
}