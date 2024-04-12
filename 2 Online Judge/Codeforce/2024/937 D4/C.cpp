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
string convertTo12HourFormat(const string& time24) {
    int hour = stoi(time24.substr(0, 2));
    int minute = stoi(time24.substr(3, 2));
    string period = "AM";
    string hourStr;

    if (hour >= 12) {
        period = "PM";
        if (hour > 12) hour -= 12;
    }

    if (hour == 0) hour = 12;


    hourStr = (hour < 10) ? "0" + to_string(hour) : to_string(hour);

    string minuteStr = (minute < 10) ? "0" + to_string(minute) : to_string(minute);

    return hourStr + ":" + minuteStr + " " + period;
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

    string time24;
    while (t--) {
        cin >> time24; // Read the time in 24-hour format
        cout << convertTo12HourFormat(time24) << endl; // Output the 12-hour format
    }

    return 0;
}