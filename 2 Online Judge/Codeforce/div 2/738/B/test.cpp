#include<bits/stdc++.h>
using namespace std;

//int a[1000005];
const long long INF = 1e9 + 7;
const long long Mod = 1e9 + 7;
const int lim3 = 1e3, lim5 = 1e5;

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string s = "????R???";
    int n = s.size();

    for (int i = (n-1); i >= 0; i--) {
            int vt = i;
            while ((s[vt] == 'B' || s[vt] == 'R') && s[vt+1] == '?') {
                cout << vt << endl;
                if (s[vt] == 'B') {
                    s.erase(vt+1,1);
                    s.insert(vt+1,"R");
                }
                else {
                    s.erase(vt+1,1);
                    s.insert(vt+1,"B");
                } 
                vt++;
                //if (vt == n) break;
            }   
        }
    cout << s;  
    return 0;
}