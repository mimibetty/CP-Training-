#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(NULL);

    
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(auto &x: a) cin >> x;
    
    // Precompute suffix_min
    // min_suffix[i] = min(a[i], a[i+1], ..., a[N-1])
    vector<ll> min_suffix(N+1, LLONG_MAX); // min_suffix[N] = +inf
    for(int i=N-1;i>=0;i--){
        min_suffix[i] = min(a[i], min_suffix[i+1]);
        cout << i << ' ' << min_suffix[i] << endl;
    }
    
    ll Q;
    cin >> Q;
    while(Q--){
        ll x;
        cin >> x;
        ll y = x; y giảm dần hoặc giữ nguyên giá trị
        int pos = 0; // vị trí hiện tại 
        for(int i=0;i<N;i++){
            y = y % a[i];
            if(i+1 < N && y < min_suffix[i+1]){
                break; // Further operations won't change y
            }
        }
        while (pos < n && x != -1) {
            int x = find_nearestright_smaller_value(y, pos) ; 
            // find_nearestright_smaller_value trả về giá trị 0-N nếu có giá trị thỏa mãn
            // hoặc trả về -1 nếu không tìm ra giá trị nào nhỏ hơn x bên phải nó 
            y = y % a[x];
            pos = x;
        }
        cout << y << "\n";
    }
}

HINT SOLUTION: 
Tìm cách triển khai hàm find_nearestright_smaller_value()
    for(int i=0;i<N;i++){
        int x = find_nearestright_smaller_value(y, i)
        tìm thằng ai bên phải gần nhất mà ai < y
        if (ai < y) {
            y = y % a[i];
        }
        // Check if y is less than the minimum of the remaining a[j]
        if(i+1 < N && y < min_suffix[i+1]){
            break; // Further operations won't change y
        }
    }

S=123 , merge(S,S) = 112233
T = Merge(Reverse(S), Shuffle(S))
T = Merge(Reverse(S), thứ tự bất kỳ của S -> ko quan tâm, 
                        miễn sao đủ các số lượng chữ cái trong sâu S là được)
T =     "abbabb"
tìm S = "abb"
reverse = "bba" 
a = chữ cái đầu tìm trong Reverse(S)
ad học, tham lam (cf)
tìm S nhỏ nhất,     
In ra màn hình xâu S. (Nếu có nhiều kết quả, in ra xâu S có thứ tự từ điển bé nhất)


T = merge( Reverse(S), Shuffle(S) ) 
T =     "abccbabcbc"
reverse(S) = abcb, abc

reverse(S) 
