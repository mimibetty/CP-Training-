#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fan_betong_cothep_flo20nam ios_base::sync_with_stdio(NULL);cin.tie();cout.tie();
#define endl "\n"

const ll N=40;
ll u[20],v[20],u1[21],v1[21];
bitset<20>bs;
// u là khối lượng,v là giá trị

vector<pair<ll,ll>>a;
vector<pair<ll,ll>>b;
vector<pair<ll , ll>>a1;
vector<pair<ll , ll>>a2;

void calculateSubsets(const vector<pair<ll, ll>>& vec, vector<pair<ll, ll>>& result) {
    int n = vec.size();
    int subsetCount = 1 << n; // 2^n

    for (int i = 0; i < subsetCount; i++) {
        ll tong = 0, sum = 0;
        for (int bit = 0; bit < n; bit++) {
            if (i & (1 << bit)) { // Kiểm tra bit thứ `bit` của `i`
                tong += vec[bit].first;
                sum += vec[bit].second;
            }
        }
        result.push_back({tong, sum});
    }
}
int main(){
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    
        ios::sync_with_stdio(0);
        cin.tie(NULL);
    
    fan_betong_cothep_flo20nam
    
    ll n,m;
    cin>>n>>m;
    for (int i=1;i<=n/2;i++) {
     ll x,y;
     cin >> x >> y;
     a.push_back({x,y});    
    }
    for (int i=n/2+1;i<=n;i++){
        ll x , y;
        cin >> x >> y;
        b.push_back({x,y});
    }
    
    calculateSubsets(a, a1);
    calculateSubsets(b, a2);
    pair<long long, long long>MaxVal;

    // cout << "begin a1  " << endl;
    // for (auto i : a1) {
    //     cout << i.first << ' ' << i.second << endl;
    // }
    //     cout << "end a1  " << endl;

    // cout << "begin a2  " << endl;
    // for (auto i : a2) {
    //     cout << i.first << ' ' << i.second << endl;
    // }
    //     cout << "end a2  " << endl;

    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());

    vector<long long>prefixMax(a2.size());
    prefixMax[0] = a2[0].second;
    for (int i = 1; i < a2.size(); i++) {
        prefixMax[i] = max(prefixMax[i-1], a2[i].second);
        // cout << i <<  ' ' << prefixMax[i] << endl;
    }



    for (int i = 0; i < a1.size(); i++) {
        // cout << "STT "   << i << ' ' << a1[i].first << ' ' << a1[i].second << endl; 
        long long kg = a1[i].first;
        long long val = a1[i].second;
      
        int l = 0;
        int r = a2.size() - 1;



        // Chặt nhị phân để tìm vị trí hợp lệ
        while (l < r) {
            // cout << l << ' ' << r << endl;
            int mid = (l + r + 1) / 2;
            if (kg + a2[mid].first <= m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (l >= 0) {
            if (kg + a2[l].first <= m && MaxVal.first + MaxVal.second < val + prefixMax[l]) {
                MaxVal = {val, prefixMax[l]};
            }
            // cout <<"choose " << val << ' ' << prefixMax[l] << ' ' << MaxVal.first << ' ' << MaxVal.second << endl;
        }
        else {
            // cout << "NO found" << endl;;
        }
    } 
    cout << MaxVal.first << ' ' << MaxVal.second << endl;
}