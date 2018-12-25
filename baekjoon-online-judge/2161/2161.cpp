#include <cstdio>
#include <queue>

using namespace std;

int N;
deque<int> dq;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        dq.push_back(i);

    while(!dq.empty()) {
        printf("%d ", dq.front());
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }

    return 0;
}
