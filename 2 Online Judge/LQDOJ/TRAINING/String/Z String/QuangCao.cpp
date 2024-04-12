#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
vector<int> zAlgo(string s) {
    int n = s.length();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i <= n - 1; i++) {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }
    z[0] = n;
    return z;
}


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int o = 1; o<= t; o++) {
        vector<pair<int,int>>cs1,cs2;
        
        int k;
        bool done = 0;
        cin >> k;

        string a,b,s;
        cin >> s >> a >> b;
        
        int ns = s.size();
        int na = a.size();
        int nb = b.size();
        int dk1 = max(na,nb);
        int dk2 = na + nb + k;

        
        string sa = a + "$" + s;
        string sb = b + "$" + s;
        vector<int>z;

        z = zAlgo(sa);
        for (int i = na + 1; i < sa.size(); i++) {
            if (z[i] == na ) {
                cs1.push_back({i - na, i - 1});
            }
        }

        z.clear();

        z = zAlgo(sb);
        for (int i = nb + 1; i < sb.size(); i++) {
            if (z[i] == nb ) {
                cs2.push_back({i - nb, i - 1});
            }
        }

       /*for ( auto i : cs1) cout << i <<' ';
       for ( auto i : cs2) cout << i <<' ';*/
    
        for (auto i : cs1) {
            for (auto j : cs2) { 
                if (j.second >= i.second) {
                        if (j.second  - i.first + 1 >= dk1 
                        && j.second - i.first + 1 <= dk2 ) {
                            done = 1;
                            break;
                    }    
                }
                
            }
        }
       /* for (auto i : cs1 ) cout << i.first << i.second;
        cout << endl;
        for (auto i : cs2 ) cout << i.first << i.second;
        cout << endl;
*/
        if ( done == 1) cout << "YES";
        else cout << "NO";
        cout << '\n';
        cs1.clear();
        cs2.clear();
    }   
	return 0;
}