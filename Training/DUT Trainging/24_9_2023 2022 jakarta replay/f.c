#include <stdio.h>

int main() {
    if(fopen("input.txt", "r")) {
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    }
    long long a,b;
    scanf("%lld %lld", &a, &b);
    long long s = a + b;
    printf("%lld", s);  // In ra kết quả làm tròn đến chữ số thập phân thứ hai
    return 0;
}