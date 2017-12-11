#include <cstdio>

#define ll long long

ll N, M, ans;

int main() {
    scanf("%lld %lld", &N, &M);
    
    ans = N - M;
    if(ans < 0) ans = -ans;
    
    printf("%lld\n", ans);

    return 0;
}
