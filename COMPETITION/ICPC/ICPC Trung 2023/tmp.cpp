#include <iostream>
// #include <cstdio>


// using namespace std;
long long a,b,c,k;
long long lcmab,lcmac,lcmbc,lcmabc;
   
long long gcd__(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd__(b, a % b);
}
long long lcm(long long x, long long y) {
    long long z = gcd__(x,y);
    long long res = x * y /z;
    return res;
}

long long tinh(long long n){
    return n/a+n/b+n/c-n/(lcmab)-n/(lcmbc)-n/(lcmac) +n/lcmabc;
}
int main()
{
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }
    // ios_base::sync_with_stdio(0); 
    // cin.tie(0); 
    // cout.tie(0);
    
    int t;
    // cin>>t;
    scanf("%d", &t);

    while (t--){
        scanf("%lld%lld%lld%lld", &a, &b, &c, &k);

        // cin>>a>>b>>c>>k;
        lcmab = lcm(a,b);
        lcmac = lcm(a,c);
        lcmbc = lcm(b,c);
        lcmabc = lcm(lcmab, c);
        a,b,c <= 10^9
        lcm =? maxlcm = 10^9 * 10^9 * 10^9 = 10*27  long long 10^18 unsigned long long = 2*10^18
        long long l=0;
        long long r=1e18;
        while (l<r){
            long long mid=(l+r)/2;
            if (tinh(mid)>=k){
                r=mid;
            }else{
                l=mid+1;
            }
        }
            printf("%lld\n", l);

        // cout<<l<<endl;
    }
}
