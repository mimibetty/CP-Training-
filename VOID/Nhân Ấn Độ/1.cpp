
long long mul(long long a, long long b, long long p) {
    if (b == 0) return 0;
    long long c = mul(a, b / 2, p);
    if (b % 2 == 0) return (c + c) % p;  
    else return ((c + c) % p + a) % p;
}
