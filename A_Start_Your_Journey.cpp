#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d, e, f;
ll dp[10001] ;
ll fn(int n) {
    if(dp[n]!=-1)
        return dp[n];
    if (n == 0) return dp[0]=a;
    if (n == 1) return dp[1]=b;
    if (n == 2) return dp[2]=c;
    if (n == 3) return dp[3]=d;
    if (n == 4) return dp[4]=e;
    if (n == 5) return dp[5]=f;
    
    return dp[n]=(fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6))%10000007;
}
int main() {
    ll n, cases;
    scanf("%lld", &cases);
    for (ll caseno = 1; caseno <= cases; ++caseno) {
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", caseno, fn(n) % 10000007);
    }
    return 0;
}