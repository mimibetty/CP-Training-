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

string Plus1(string s) {
    string res;

    return res ;
}

void solve() {
    long long n;
    string l, r;
    cin >> n >> l >> r;
    long long fl = l.size(), fr = r.size();
    // fl <= fx <= fr 
    // fx = n*i
    vector<int>ff;
    if (fl % n == 0) {
        ff.push_back(fl);
        if (fl + n <= fr) {
            ff.push_back(fl + n);
        }
    }
    else {
        long long tmp = (fl/n + 1) * n;
        if (tmp <= fr) ff.push_back(tmp); // tmp la len cua x nho nhat > fl va la boi cua n
    }

    for (auto i : ff) {
        // cout << i << endl;
        if (i > fl && i < fr) {
            for (int j = 1; j <= i; j++) {
                cout << 1;
            }
            return;
        }
        if (fl <= i && i <= fr) {
            if (fl != fr) {
                if (i == fl) {
                    string res1;
                    for (int j = 1; j <= fl; j++) {
                        res1 += '9';
                    }

                    if (res1 > l && res1 < r) {            
                        cout << res1;
                        return;             
                    }
                }
                else if (i == fr) {
                    string res2;
                    string z = "1";
                    for (int j = 1; j < n; j++) {
                        z += '0';
                    }
                    for (int j = 1; j <= fr/n; j++) {
                        res2 += z;
                    }

                    if (res2 > l && res2 < r) {
                        cout << res2;
                        return;
                    }
                }
            }
            else {

                string tmp ;
                for (int j = 0; j < n; j++) {
                    tmp += l[j];
                }
                string newtmp = Plus1(tmp);
                if(newtmp.size() == tmp.size()) {
                    // do at here
                    string res;
                    for (int j = 1; j <= fr/n; j++) {
                        res += newtmp;
                    }
                    if (res > l && res < r) {
                        cout << res <<endl;
                        return;
                    }
                }

            }
        }
    }
    cout << -1;
}

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string java = "Java" , va = "va";
    cout << (java == "Ja" +)
    // solve();
    return 0;
}

L R   7 644 
7 10
a1 * 2^x = a_k  (ak là giá trị cuối cùng trong mảng)
a1 * 2^x <= R    x là số k cần tìm, độ dài của mảng 
ak = a1 * 2^(x-1) * 3 <= R 
z = 2 | 3 
a1  a1 * z1   a2 *z2    a3*z3 .... ak = ak-1 *z(k-1)

TH1 tất cả đều * 2 
chọn a1 
và xét điều kiện ak = a1 * 2^(k-1) <= R , nếu thỏa mãn thì res++
a1_min = L
a1_max = ??? = f 
f là số lớn nhất sao cho ak_max = f * 2^(k-1) <= R 
a1 * 2^(k-1) <= R 
a1 <= R / 2^(k-1)

chặt nhị phân l = L, r = 1e14
mid = l + r / 2 = 0.5 * 1e14
a1 = 0.5 * 1e14 ak = 0.5 * 1e14 * 1e9 = 1e23 <= 10e18
2^30 = 1e9

F = a1_max 
res = F - l + 1




TH2    chọn k - 2 số 2 và 1 số 
a1  a1 * z1    a2 * z2   a3 * z3   ... ak = ak-1 * zk-1 
vẫn lệ thuộc vào việc mình chọn a1 
nếu ak thỏa mãn thì res += k-1 // các dãy sẽ khác nhau khi ta đặt zi = 3 tại mỗi vị trí i    
có k-1 cách đặt zi = 3 
điều kiện để dãy thỏa mãn:  ak = a1 * 2^(k-2) * 3 <= R

có bao nhiêu a1 thỏa mãn điều kiên??
chặt nhị phân tương tự TH1 
ak = a1 * 2^(k-1) * 3 <= R  
ak = F 
res += (F - l + 1) * (k-1)
