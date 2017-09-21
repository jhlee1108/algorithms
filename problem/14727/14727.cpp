#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N;
vector<int> hist;
stack<int> s;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int h; scanf("%d", &h);
        hist.push_back(h);
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        while(!s.empty() && hist[s.top()] > hist[i]) {
            int height = hist[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            ans = max(ans, height * width);
        }
        s.push(i);
    }

    while(!s.empty()) {
        int height = hist[s.top()];
        s.pop();
        int width = s.empty() ? N : N - s.top() - 1;
        ans = max(ans, height * width);
    }

    printf("%d\n", ans);

    return 0;
}
