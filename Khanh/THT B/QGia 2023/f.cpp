#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> IndexTree;

 
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
     
    IndexTree s;
    for (int i = 0; i <= 20; i+=2) s.insert(i);
    s[i] ?  =>>>> vip pro order tree *s.find_by_order(i), S[I]
    for (int i = 0; i <= 5; i++) cout << *s.find_by_order(i) << endl;
    cout << s.order_of_key(2) ;//== lower_bound(x)-s.begin();
    
    1 2   4  5 x 7         6 + 5 =  11%S.SIZE()  11 =  1  + S.SIZE() * N + VT(RES) => vt , cout << s.find_by_order(vt) , s.erase(s.find(s[vt])) => vtmnew cho ddeens khi s.size() == 0
// s={2,5,6,10}
// *s.find_by_order(2)=6;
// s.order_of_key(x) == lower_bound(x)-s.begin();
    return 0;
}


DP[3][MASK] = 1 || 0