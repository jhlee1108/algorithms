#include <cstdio>
#include <stack>
#include <algorithm>

#define ll long long

using namespace std;

int n;
ll T[100000];
stack<ll> s;

int main() {
    scanf("%d", &n);
    
    ll ans = 0;
    for(int i=0; i<n; i++) {
        scanf("%lld", &T[i]);
        while(!s.empty() && T[s.top()] > T[i]) {
            ll price = T[s.top()];
            s.pop();
            ll days = i;
            if(!s.empty()) days = i - s.top() - 1;
            ans = max(ans, days*price);
        }
        s.push(i);
    }

    while(!s.empty()) {
        ll price = T[s.top()];
        s.pop();
        ll days = n;
        if(!s.empty()) days = n - s.top() - 1;
        ans = max(ans, days*price);
    }
    
    printf("%lld\n", ans);

    return 0;
}
