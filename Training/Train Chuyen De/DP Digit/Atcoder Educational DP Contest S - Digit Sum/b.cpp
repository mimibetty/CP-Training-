#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef double ld;

 
vector<string>process_string(string s) {
    vector<string>a;
    string temp; 
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            a.push_back(temp);
            temp.clear();
        }
        else {
            temp += s[i];
        }
    }

    return a;
}
int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(NULL);
     
    string s;
    getline(cin, s);

    vector<string>input_process = process_string(s);
    // for (auto i : input_process) cout << i << endl;

    int start = input_process.size() - 1;
    for (int i = start; i >= 0; i--) cout << input_process[i] << ' ';
    return 0;
}