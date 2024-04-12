#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long, long long> pll;
typedef double ld;
 
#define For(i, l, r) for (int i = l; i < r; i++)
#define REP(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;
#define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
#define SQ(a) a*a
 
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long long oo = 1e18 + 7;
const int lim3 = 1e3, lim5 = 1e5;
const int MOD = int(1e9)+7;
const double PI = acos(-1);
 
 
int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	

 	
 	int t;
 	cin >> t;
 	while (t--) {
 		string s;
 		cin >> s;
 		int n = s.size();

 		int cnt = 0;
 		
 		string ans,s2;
 		int j = 0;
 		while (j < s.size()) {
 			// cout <<  j << "   " << s <<"  "<< cnt << endl;
 			if (s[j] == '0' || s[j] == '1') {
 				ans += s[j]; 
 			} 
 			else {
 				cnt++;
				// s.erase(s.begin() + j, s.begin() + j + 1);
 			}
 			j++;
 		}
 		// cout << ans <<endl;
 		int i = 0;
 		while (i < ans.size()) {
 			// cout << "STR  " << s << ' ' <<i << ' '<< cnt<< endl;
 			if (i == 0) {
				if (ans[i] == '0') {
					s2 += ans[i];
					// continue;
				}
				else if (ans[i] == '1') {
					if (ans[i+1] == '0') {
						s2 += ans[i];

					}
					else {
						cnt++;
						// s.erase(s.begin() + i, s.begin() + i + 1);
					}
				}
			}
 	
 			else if (i == (ans.size()-1)) {
 				if (ans[i] == '0') {
 					s2 += ans[i];
				}
				else if (ans[i] == '1') {
					
					if (s2.empty() == 1) {
						cnt++;
					}
					else {
						if (s2[s2.size() - 1] == '0') {
							s2 += ans[i];
						}
						else {
							cnt++;
						}
					}
				}

 			}
 			else {
 				if (ans[i] == '0') {
 					s2 += ans[i];
				}
				else if (ans[i] == '1') {
					if (ans[i+1] == '0') {  //|| s[s2.size() - 1] == '0') {
						s2 += ans[i];

					}
					else {
						if (s2.empty() == 1) {
							cnt++;
	
						}
						else {
							if (s2[s2.size() - 1] == '0') {
								s2 += ans[i];
				
							}
							else {
								cnt++;
				
							}
						}
					}
					
				}
 			}
 			i++;
 		}
 		// cout <<"STT  " << t << ' '<< cnt <<  ' '<< s  << endl;
  		// cout << cnt << "   " <<s2 <<endl;
  		cout << cnt << endl;
  	}

    return 0;		
}