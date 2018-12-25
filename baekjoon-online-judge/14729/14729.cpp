#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int N;
priority_queue<double> q;
stack<double> s;

int main() {
    scanf("%d", &N);
    while(N--) {
        double score;
        scanf("%lf", &score);
        if(q.size() < 7) q.push(score);
        else if(q.top() > score) {
            q.pop();
            q.push(score);
        }
    }

    while(!q.empty()) {
        s.push(q.top());
        q.pop();
    }

    while(!s.empty()) {
        printf("%.3lf\n", s.top());
        s.pop();
    }

    return 0;
}
