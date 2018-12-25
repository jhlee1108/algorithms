#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector<stack<int>> s(7);

int main() {
    int n, p; scanf("%d %d", &n, &p);
    int ans = 0;

    while(n--) {
        int a, b; scanf("%d %d", &a, &b);

        while(!s[a].empty() && s[a].top() > b) {
            s[a].pop();
            ans++;
        }

        if(!s[a].empty() && s[a].top() == b) continue;
        s[a].push(b);
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
