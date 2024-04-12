chưa fix
#include<bits/stdc++.h>
using namespace std;
struct cuoc {
	long long tien, cua;
};
struct tien {
	long long nguoi, tien;
};

bool cmp(tien truoc, tien sau) {
	if (truoc.tien == sau.tien) return truoc.nguoi > sau.nguoi;
	return truoc.tien > sau.tien;
}

cuoc a[105];
tien b[105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long cua1,cua2,cua3,res=0,res1=0,res2=0,res3=0;
    cin>>cua1>>cua2>>cua3;
    long long k = cua1 + cua2 + cua3;
    for (int i = 1; i<= k ; i++) {
         cin>>a[i].cua>>a[i].tien;
         b[a[i].cua].nguoi++;
         b[a[i].cua].tien+=a[i].tien;
    }
    sort(b+1,b+1+k,cmp);
    for (int i = 1; i<= 6; i++) {
        cout<<i<<' '<<b[i].tien<<endl;
    }
//    if ((b[1].tien)/2 >= b[2].tien ) {
//        res = b[1].tien*3;
//        for (int i = 2; i<= 6; i++) res-=b[i].tien;
//    }
//    else if ((b[1].tien)/2 <= b[2].tien && (b[1].tien)/2 <= b[3].tien ) {
//        res= b[1].tien + b[2].tien + b[3].tien;
//        for (int i = 4; i<= 6; i++) res-=b[i].tien;
//    }
//    else if ((b[1].tien)/2 <= b[2].tien && (b[1].tien)/2 > b[3].tien ) {
//        res= 2*b[1].tien + b[2].tien;
//        for (int i = 3; i<= 6; i++) res-=b[i].tien;
////    }
//    for (int i = 2; i<= 6; i++) res1+=b[i].tien;
//    for (int i = 4; i<= 6; i++) res2+=b[i].tien;
//    for (int i = 3; i<= 6; i++) res3+=b[i].tien;
//    res=max(b[1].tien*3-res1,max(b[1].tien + b[2].tien + b[3].tien - res2,2*b[1].tien + b[2].tien-res3));
//    cout<<res;
    return 0;
}


