#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,cntn= 0,cntnn=0,res = 0 ;
    cin>>n;
    string s;
    cin>>s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            cntn++;
        }
    }
    for (int i =0; i< n; i++) {
        if (s[i] == 'N') {
            cntnn++;
        }
        if (s[i] == 'L') {
            res+= (cntn - cntnn);
        }
    }
    cout<<res;
    return 0;

}


