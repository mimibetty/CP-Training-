/*
link submit: 
Note:
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define MS(s, n) memset(s, n, sizeof(s))
#define All(v) (v).begin(),(v).end()
 
#define cntBit __builtin_popcount 
#define fi first 
#define se second
#define pb push_back
#define precision(x) cout << setprecision(x) << fixed;
#define EL cout << endl;

const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const long double PI = acos(-1);
 
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count()); 
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r); return rnd(gen);
}


int n;
long long prize[4];
void solve() {
    cin >> n;
    int limm = 7;
    string s;
    long long res = 0;
    map<string,long long>f2,f3; 
    for (int i = 1; i <= n; i++) {
        cin >> s;
        string z;
        z += s[4];
        z += s[5];
        f3[z]++;
        
        string ff;
        ff += s[2];
        ff += s[3];
        ff += z;
        f2[ff]++; 
    }   
    vector<pair<long long,string>> tmp;
    vector<pair<long long,string>> ff;
    
    for (auto i : f3) {
        // cout <<(i.se) <<' ' << i.fi << endl;
        tmp.pb({i.se, i.fi});
    }
    sort(All(tmp));
    reverse(All(tmp));
    
    int lenn = tmp.size();
    for (int i = 0; i < min(limm, lenn); i++) {
        ff.pb({tmp[i].fi , tmp[i].se});
    }
    for (int i = 0; i <= 99; i++) {
        if (ff.size() >= limm) break;
        
        string m = to_string(i);
        if (f3[m] == 0) {
            ff.pb({0,m});
        }
    }


    prize[1] = 300000;
    prize[2] = 4000;
    prize[3] = 500;
    for (int i = 0; i <= 9999; i++) {
        for (int j1 = 0; j1 < limm; j1++) {
            for (int j2 = j1 + 1; j2 < limm; j2++) {
                for (int j3 = j2 + 1;  j3 < limm; j3++) {
                    string z2 = to_string(i);
                    string z31 = ff[j1].se;
                    string z32 = ff[j2].se;
                    string z33 = ff[j3].se;
                    
                    while(z2.size() < 4) {
                        z2 = '0' + z2;
                    }
                    while(z31.size() < 2) {
                        z31 = '0' + z31;
                    }
                    while(z32.size() < 2) {
                        z32 = '0' + z32;
                    }
                    while(z33.size() < 2) {
                        z33 = '0' + z33;
                    }

                    string mm;
                    mm += z2[2];
                    mm += z2[3];
                    if (mm == z33 || mm == z32 || mm == z31) continue;

                    long long q = prize[1] + prize[2] * f2[z2] + prize[3]*(ff[j1].fi + ff[j2].fi + ff[j3].fi); 
                    long long cnt = 1 + f3[mm] + ff[j1].fi + ff[j2].fi + ff[j3].fi;
                    long long nn = 0;
                    if (cnt <= n) {
                      res = max(res, q);
                      nn = max(nn, q);  
                    
                    } 
                    if (cnt - 1 <= n) {
                        res = max(res, q - prize[1]);
                        nn = max(nn, q - prize[1]);
                            
                    }
                    if (cnt - f3[mm] <= n) {
                        res = max(res, q - prize[2]*f2[z2]);
                        nn = max(nn, q - prize[2]*f2[z2]);
                        
                    }

                    if (cnt - ff[j1].fi <= n) {
                        res = max(res, q - prize[3]*ff[j1].fi);
                        nn = max(nn, q - prize[3]*ff[j1].fi);
                     
                    }
                    if (cnt - ff[j2].fi <= n) {
                        res = max(res, q - prize[3]*ff[j2].fi);
                        nn = max(nn, q - prize[3]*ff[j2].fi);
                    // if (nn == 308500) {
                    //                         cout << q << ' ' << cnt <<endl;

                    //     cout << "dayy" << endl;
                    //     cout <<z2 << ' ' << ff[j1].se << ' ' << ff[j2].se << ' ' << ff[j3].se;
                    //     EL;
                    //     cout <<f2[z2] << ' ' << ff[j1].fi << ' ' << ff[j2].fi << ' ' << ff[j3].fi;
                    //     EL;
                    //     EL;
                    //     }    
                    }
                    if (cnt - ff[j3].fi <= n) {
                        res = max(res, q - prize[3]*ff[j3].fi);
                        nn = max(nn, q - prize[3]*ff[j3].fi);
                        
                    }

                }
            }
        }       
    }
        cout << res <<endl;

    //  for (int i = 0; i <= 9999; i++) {
    //     for (int j1 = 0; j1 < limm; j1++) {
    //         for (int j2 = j1 + 1; j2 < limm; j2++) {
    //             for (int j3 = j2 + 1;  j3 < limm; j3++) {
    //                 string z2 = to_string(i);
    //                 string z31 = ff[j1].se;
    //                 string z32 = ff[j2].se;
    //                 string z33 = ff[j3].se;

    //                 while(z2.size() < 4) {
    //                     z2 = '0' + z2;
    //                 }
    //                 while(z31.size() < 2) {
    //                     z31 = '0' + z31;
    //                 }
    //                 while(z32.size() < 2) {
    //                     z32 = '0' + z32;
    //                 }
    //                 while(z33.size() < 2) {
    //                     z33 = '0' + z33;
    //                 }
    //                 string mm;
    //                 mm += z2[2];
    //                 mm += z2[3];
    //                 if (mm == z33 || mm == z32 || mm == z31) continue;

    //                 long long zzz = 0;
    //                 if (f3[mm] + ff[j1].fi + ff[j2].fi + ff[j3].fi == n) {
    //                     if (f2[z2] == n) {
    //                         zzz = max({zzz, f2[z2] * prize[2], prize[1] + prize[3]*(ff[j1].fi + ff[j2].fi +ff[j3].fi) });
    //                         if (zzz == res) {
    //                             cout << z2 << ' ' <<z31 << ' ' << z32 << ' ' << z33 << endl;
    //                         }
    //                         continue;
    //                     }
    //                     if (ff[j1].fi == n) {
    //                         zzz = max({zzz, ff[j1].fi * prize[3], prize[1] + f2[z2]*prize[2] + prize[3]*(ff[j2].fi + ff[j3].fi) });
    //                         if (zzz == res) {
    //                             cout << z2 << ' ' <<z31 << ' ' << z32 << ' ' << z33 << endl;
    //                         }
    //                         continue;
    //                     }
    //                     if (ff[j2].fi == n) {
    //                         zzz = max({zzz, ff[j2].fi * prize[3], prize[1] + f2[z2]*prize[2] + prize[3]*(ff[j1].fi + ff[j3].fi) });
    //                         if (zzz == res) {
    //                             cout << z2 << ' ' <<z31 << ' ' << z32 << ' ' << z33 << endl;
    //                         }
    //                         continue;
    //                     }
    //                     if (ff[j3].fi == n) {
    //                         zzz = max({zzz, ff[j3].fi * prize[3], prize[1] + f2[z2]*prize[2] + prize[3]*(ff[j1].fi + ff[j2].fi) });
    //                         if (zzz == res) {
    //                             cout << z2 << ' ' <<z31 << ' ' << z32 << ' ' << z33 << endl;
    //                         }
    //                         continue;
    //                     }

    //                     vector<pair    
    //                     zzz = max({zzz,f2[z2] *prize[2] + prize[3]*(ff[j1].fi + ff[j2].fi + ff[j3].fi),
    //                         prize[1] + prize[3]*(ff[j1].fi + ff[j2].fi + ff[j3].fi),
    //                         prize[1] + f2[z2] *prize[2] + prize[3]*(ff[j1].fi + ff[j2].fi),
    //                         prize[1] + f2[z2] *prize[2] + prize[3]*(ff[j1].fi + ff[j3].fi),
    //                         prize[1] + f2[z2] *prize[2] + prize[3]*(ff[j2].fi + ff[j3].fi)
    //                         });
    //                     if (zzz == res) {
    //                         cout << z2 << ' ' <<z31 << ' ' << z32 << ' ' << z33 << endl;
    //                         cout <<f2[z2] << ' ' << f3[mm] << "    " << f3[z31] << ' ' << f3[z32] << ' ' <<f3[z33] << endl;
    //                     }

    //                 }
    //                 else {
    //                     zzz = max(zzz, prize[1] + prize[2] * f2[z2] + prize[3] * (ff[j2].fi + ff[j3].fi + ff[j1].fi));
    //                     // if (zzz == res) {
    //                     //     cout << z2 << ' ' <<z31 << ' ' << z32 << ' ' << z33 << endl;
    //                     //     cout <<f2[z2] << ' ' << f3[z31] << ' ' << f3[z32] << ' ' << f3[z33] << endl;
    //                     //     cout <<"Day" << endl;
    //                     // }

    //                 }
    //             }
    //         }
    //     }       
    // }
   
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    t = 1;
    while (t--)    
    solve();
    
    return 0;
}
