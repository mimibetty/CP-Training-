#include <bits/stdc++.h>
using namespace std;
long long base1=131,base2=71,mod=1e9+7;
long long f1[1000000],f2[1000000],h[1000000];
long long hash_1(string &s){
    long long res=0;
    for (auto x:s) res=(long long)(res*base1+x-'a'+1)%mod;
    return res;
}
long long hash_2(string &s){
    long long res=0;
    for (auto x:s) res=(long long)(res*base2+x-'a'+1)%mod;
    return res;
}
long long len_[1000000];
long long power1[1000000],power2[1000000];
long long get1(int l,int r){
    return (long long)(f1[r]-f1[l-1]*power1[r-l+1]+mod*mod)%mod;
}
long long get2(int l,int r){
    return (long long)(f2[r]-f2[l-1]*power2[r-l+1]+mod*mod)%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    power1[0]=1;
    power2[0]=1;
    long long n;
    cin>>n;


    vector<long long> len;
    set<long long> v1,v2;
    for (int i=1; i<=n; i++){
        string s;
        cin>>s;
        len_[s.size()]++;
        if (len_[s.size()]==1) len.push_back(s.size());
        long long val1=hash_1(s),val2=hash_2(s);

        // v1.push_back(val1);
        // v2.push_back(val2);
        v1.insert(val1);
        v2.insert(val2);
    }
    
    sort(len.begin(), len.end());
    // sort(v1.begin(), v1.end());
    // sort(v2.begin(), v2.end()); 

    string s;
    cin>>s;
    h[0]=1;
    

    for (int i=1; i<=s.size(); i++) {
        power1[i]=(long long)(power1[i-1]*base1)%mod;
        power2[i]=(long long)(power2[i-1]*base2)%mod;

        f1[i]=(long long)(f1[i-1]*base1+(s[i-1]-'a'+1))%mod;
        f2[i]=(long long)(f2[i-1]*base2+(s[i-1]-'a'+1))%mod;

        for (int j=0; j<len.size(); j++) {
            if (len[j]>i) break;
            if (h[i-len[j]]==0) continue;
            int l=i-len[j]+1;
            int r=i;
            long long val1=(long long)(f1[r]-f1[l-1]*power1[r-l+1]+mod*mod)%mod;
            // auto it1=lower_bound(v1.begin(),v1.end(),val1)-v1.begin();
            
            // if (it1<v1.size())
            // if (v1[it1]==val1) {
            //     long long val2=(long long)(f2[r]-f2[l-1]*power2[r-l+1]+mod*mod)%mod;
            //     auto it2=lower_bound(v2.begin(),v2.end(),val2)-v2.begin();
            //     if (it2<v2.size())
            //     if (v2[it2]==val2) h[i]=(long long)(h[i]+h[i-len[j]])%mod;
            // }
            auto it1=v1.count(val1);
            if (it1==1) {
                long long val2=(long long)(f2[r]-f2[l-1]*power2[r-l+1]+mod*mod)%mod;
                auto it2=v2.count(val2);
                if (it2==1) h[i]=(long long)(h[i]+h[i-len[j]])%mod;
            }
        }
    }
    cout<<h[s.size()];
}