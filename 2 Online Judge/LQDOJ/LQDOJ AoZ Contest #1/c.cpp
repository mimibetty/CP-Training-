#include <bits/stdc++.h>
using namespace std;

int main(){
        if(fopen("input.txt", "r")) {
            freopen("input.txt","r",stdin);
            // freopen("output.txt","w",stdout);
        }

        ios::sync_with_stdio(0);
        cin.tie(NULL);

    int N;
    cin >> N;
    vector<long long> a(N);
    for(auto &x: a) cin >> x;
    int count =0;
    int left =0, right = a.size()-1;
    while(left < right){
        if(a[left] == a[right]){
            left++;
            right--;
        }
        else if(a[left] < a[right]){
            // Merge left side: a[left] + a[left+1]
            a[left+1] +=a[left];
            a.erase(a.begin()+left);
            count++;
            right--; // since array size reduced by1
        }
        else{
            // a[left] > a[right]:
            // Merge right side: a[right -1] + a[right]
            a[right -1] +=a[right];
            a.erase(a.begin()+right);
            count++;
            right--; // since array size reduced by1
        }
    }
    cout << count;
}
