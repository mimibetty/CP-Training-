#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<string, int> myPair1 = make_pair("Testing", 123);
    cout << myPair1.first << " " << myPair1.second << endl;
    myPair1.first = "It is possible to edit pairs after declaring them";
    cout << myPair1.first << " " << myPair1.second << endl;
    pair<string, string> myPair2 = {"Testing", "curly braces"};
    cout << myPair2.first << " " << myPair2.second << endl;
}
