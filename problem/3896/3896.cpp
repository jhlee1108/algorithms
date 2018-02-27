#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1299710

using namespace std;

int T, k;
vector<bool> is_prime(MAX_N, true);
vector<int> prime;

int main() {
    prime.push_back(2);
    for(int i=4; i<MAX_N; i+=2)
        is_prime[i] = false;
    for(int i=3; i<MAX_N; i++) {
        if(is_prime[i]) prime.push_back(i);
        for(long long j=1LL*i*i; j<MAX_N; j+=i*2)
            is_prime[(int)j] = false;
    }

    scanf("%d", &T);
    while(T--) {
        scanf("%d", &k);
        vector<int>::iterator it = lower_bound(prime.begin(), prime.end(), k);
        int ans;
        if(k == *it) ans = 0;
        else if(k > *it) ans = *(it+1) - *it;
        else ans = *it - *(it-1);
        printf("%d\n", ans);
    }

    return 0;
}
