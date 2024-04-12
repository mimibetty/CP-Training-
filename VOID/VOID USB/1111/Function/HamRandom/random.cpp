#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    srand(time(NULL));

    // a random từ 0 tới RAND_MAX
    int a = rand();
    cout << a << " ";

    // b random từ x tới y
    // b = rand() % (y - x + 1) + 1;
    int b = rand() % 50 + 1; // [1, 50]
    cout << b;
    return 0;
}

