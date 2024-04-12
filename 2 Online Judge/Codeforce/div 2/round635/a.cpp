    #include<bits/stdc++.h>
    using namespace std;
    long long a[100005];
    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int t;
        cin >> t;
        for (int q = 1; q <= t; q++) {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            if (b == c) {
                for (int i = 1; i <= 3; i++) cout << b << ' ';
            }
            else cout << b << ' ' << c << ' ' << c;
            cout << endl;
        }
        return 0;
    }

