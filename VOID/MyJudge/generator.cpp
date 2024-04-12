#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
// faster


int main() {
    ios::sync_with_stdio(0);

    for (int index = 1; index <= NUM_TESTS; index++) {
        ofstream inp(inputName(index).c_str());
        
        int n = rand(3,6);

        inp << n << endl;
        vector<int>a;
        vector<pair<int,int>>vt;
        for (int i = 1; i <= n; i++) {
            a.push_back(i);
            a.push_back(i);   
        }

        for (int i = 0; i < 2*n; i++) {
            int x = rand(0,9999);
            vt.push_back({x,i});
        }
        sort(vt.begin(), vt.end());
        for (auto i : vt) {
            inp << a[i.second] << ' ';
        }
       

    }
    return 0;
}