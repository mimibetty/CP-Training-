#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline int read()
{
    char ch=getchar();
    int x=0;bool s=1;
    while(ch<'0'||ch>'9'){if(ch=='-')s=0;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return s?x:-x;
}
int x[100007];
int a[100007];
int s[100007];
int main()
{
    //scan
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n,mid,p;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    cin >> mid;
    // n=read(),mid=read();
    unsigned long long ans=0;
    for(int i=1;i<=n;++i)
    {
        // int x=read();
        if(x[i]<mid)a[i]=-1;
        else if(x[i]>mid)a[i]=1;
        else p=i;
    }
    for(int i=1;i<=n;++i)
    s[i]=s[i-1]+a[i];
    //run
    for(int l=1;l<=n;l+=2)
    {
    int k=min(p,n-l+1);
    for(int i=max(1,p-l+1);i<=k;++i)
    {
        int j=i+l-1;
        if(s[j]-s[i-1]==0)ans++;
    }
    }
    cout<<ans<<endl;
    return 0;
}