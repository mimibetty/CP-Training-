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


pii fr[505][505];
char a[505][505];
int hang[505];
int cot[505];
int bhang[505];
int bcot[505];

int n,m;

char res[505][505];
struct dat{
    pii x;
    pii y;
};
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != '.') hang[i]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j][i] != '.') cot[i]++;
        }
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        if (hang[i] % 2 != 0) {
            ok=0;
            break;
        }
    }
    if (ok == 0) {
        cout << -1 << endl;
        for (int i = 1; i <=n; i++) hang[i] = 0;
        for (int i = 1; i <=m; i++) cot[i] = 0;
        return;
    }
    for (int i = 1; i <= m; i++) {
        if (cot[i] % 2 != 0) {
            ok=0;
            break;
        }
    }
    if (ok == 0) {
        cout << -1 << endl;
        for (int i = 1; i <=n; i++) hang[i] = 0;
        for (int i = 1; i <=m; i++) cot[i] = 0;
        return;
    }
   

    vector<dat>vt;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'L') {
                dat zz;
                zz.x =  {i,j};
                zz.y = {i,j+1};
                vt.pb(zz);
                fr[i][j] = zz.y;
                fr[i][j+1] = zz.x;
            }
            if (a[i][j] == 'U') {
                dat zz;
                zz.x =  {i,j};
                zz.y = {i+1,j};
                vt.pb(zz);
                fr[i][j] = zz.y;
                fr[i+1][j] = zz.x;
             }
        }
    } 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'L' || a[i][j] =='U') {
                pii vt1 = {i, j};
                pii vt2 = fr[i][j];
                if (bhang[vt1.fi]*2 < hang[vt1.fi] && bcot[vt1.fi]*2 < cot[vt1.fi]) {
                }
                else {
                    swap(vt1,vt2);
                }       
           
                cout << vt1.fi << ' '<<vt1.se << ' ' << bhang[vt1.fi] << ' ' << bcot[vt1.se] << endl;
                cout << vt2.fi << ' '<<vt2.se << ' ' << bhang[vt2.fi] << ' ' << bcot[vt2.se] << endl;      
                
                bhang[vt1.fi]++;
                bcot[vt1.se]++;
                res[vt1.fi][vt1.se] = 'B';
                res[vt2.fi][vt2.se] = 'W';
           
                cout << vt1.fi << ' '<<vt1.se << ' ' << bhang[vt1.fi] << ' ' << bcot[vt1.se]
                 <<"  "<< hang[vt1.fi] << ' ' << cot[vt1.se] << endl;
                cout << vt2.fi << ' '<<vt2.se << ' ' << bhang[vt2.fi] << ' ' << bcot[vt2.se]
                <<"  "<< hang[vt2.fi] << ' ' << cot[vt2.se] << endl;
                EL;
            }
            
        }
    }
    // for (auto i : vt) {
    //     cout << i.x.fi << ' ' << i.x.se << " " << i.y.fi << ' ' << i.y.se << endl;
    //     pii vt1 = {i.x.fi, i.x.se};
    //     pii vt2 = {i.y.fi, i.y.se};
    //     if (bhang[vt1.fi]*2 < hang[vt1.fi] && bcot[vt1.fi]*2 < cot[vt1.fi]) {
    //         bhang[vt1.fi]++;
    //         bcot[vt1.fi]++;
    //         res[vt1.fi][vt1.se] = 'B';
    //         res[vt2.fi][vt2.se] = 'W';
    //     }
    //     else {
    //         bhang[vt2.fi]++;
    //         bcot[vt2.fi]++;
    //         res[vt2.fi][vt2.se] = 'B';
    //         res[vt1.fi][vt1.se] = 'W';   
    //     }
    // }
    //  for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         if (res[i][j] == 'B') {
    //             if (bhang[i]*2 > hang[i] || bcot[j]*2 > cot[j]) {

    //             }
    //         }
    //         else cout << ".";
    //     }
    //     EL;
    // }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (res[i][j] == 'B' || res[i][j] == 'W') {
                cout << res[i][j];
            }
            else cout << ".";
        }
        EL;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << hang[i] << ' ' << bhang[i] << endl;
    // }

    // EL;
    // EL;
    // for (int i = 1; i <= m; i++) {
    //     cout << cot[i] << ' ' << bcot[i] << endl;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //     if (a[i][j] !='.') {
    //         cout << i << ' ' << j << ' ' << fr[i][j].fi << ' ' << fr[i][j].se << endl;
    //     }
    // }
    for (int i = 1; i <=n; i++) hang[i] = bhang[i] =  0;
    for (int i = 1; i <=m; i++) cot[i] = bcot[i] =  0;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--)   
    solve();
    
    return 0;
}