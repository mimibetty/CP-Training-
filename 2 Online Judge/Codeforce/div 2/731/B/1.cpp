    #include<bits/stdc++.h>
    using namespace std;

    //int a[1000005];
    const long long INF = 1e9 + 7;
    const long long Mod = 1e9 + 7;
    const int lim3 = 1e3, lim5 = 1e5;

    bool check_str(string &goc,string &ans) {
        int sl1 = goc.size();
        int sl2 = ans.size();
        for (int i = 0; i <= sl1-sl2; i++) {
            for (int j = 0; j < sl2; j++) {
                if (j == (sl2-1) && goc[i+j] == ans[j]) return true;
                if (goc[i+j] != ans[j]) break;
            }
        }
        return false;
    }


    int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        
        int t;
        cin >> t;
        while (t--) {
            string s;
            cin >> s;

            bool check = 1;
            int vt = s.find('a');
            if (vt == -1) check = 0;
            char chu = 'a';
            string ans = "a";

            while (ans.size() <= s.size()) {
                if (ans.size() == s.size() && check_str(s,ans) == 1) {
                    check = 1;
                    break;
                }
                chu = chu + 1;
        
                string substr1 = ans + chu;
                string substr2 = chu + ans;
                if (check_str(s,substr1) == 1) ans = substr1;
                else if (check_str(s,substr2) == 1) ans = substr2;
                else {
                    check = 0;
                    break;
                }
            }
            if (check == 1) cout <<"YES";
            else cout << "NO";
            cout << endl;

        }
        return 0;
    }