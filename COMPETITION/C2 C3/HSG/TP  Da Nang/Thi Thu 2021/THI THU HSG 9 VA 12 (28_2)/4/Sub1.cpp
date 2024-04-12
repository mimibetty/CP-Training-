#include<bits/stdc++.h>
using namespace std;

long long Mod = 1000000007;
int a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long res =0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n -2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
                res += (a[i]%Mod * ((a[j]%Mod * a[k]%Mod - 1) + Mod)%Mod);
                res%= Mod;
            }
        }
    }
    cout << res;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

long long Mod = 1000000007;
int a[100005];

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    long long res =0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n -2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            int vt1 = j + 1;
            int vt2 = n;

            long long  tich = (a[i]%Mod * a[j]%Mod)%Mod;
            tich %= Mod;

            long long tong1 = ((vt2 - vt1 + 1)%Mod) * ((vt2 + vt1)/2)%Mod;
            tong1 %= Mod;
            res += ( tich * tong1)%Mod - ((a[i]%Mod) * (vt2 - vt1 + 1)%Mod)%Mod; 
            res%=Mod;
            //cout << i << ' '<< j << ' ';
            //cout << vt1 <<' ' <<vt2 << endl;
        }
    }
    cout << res;
    return 0;
}*/