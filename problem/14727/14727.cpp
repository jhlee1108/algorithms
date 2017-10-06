#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

#define ll long long

using namespace std;

int N;
vector<ll> hist;
stack<ll> s;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        ll h; scanf("%lld", &h);
        hist.push_back(h);
    }

    ll ans = 0;
    for(int i=0; i<N; i++) {
        while(!s.empty() && hist[s.top()] > hist[i]) {
            ll height = hist[s.top()];
            s.pop();
            ll width = s.empty() ? i : i - s.top() - 1;
            ans = max(ans, height * width);
        }
        s.push(i);
    }

    while(!s.empty()) {
        ll height = hist[s.top()];
        s.pop();
        ll width = s.empty() ? N : N - s.top() - 1;
        ans = max(ans, height * width);
    }

    printf("%lld\n", ans);

    return 0;
}
