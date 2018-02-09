#include <cstdio>
#include <queue>

using namespace std;

int N, card_size;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &card_size);
        pq.push(card_size);
    }

    int ans = 0;
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int cnt = a + b;
        ans += cnt;
        pq.push(cnt);
    }

    printf("%d\n", ans);

    return 0;
}
