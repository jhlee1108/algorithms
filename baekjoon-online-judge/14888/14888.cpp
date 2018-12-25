#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int N, number[11], op[4];
int ans_max = -1e9;
int ans_min = 1e9;
stack<int> s;

void go() {
    if(s.size() > 1) {
        for(int i=0; i<4; i++) {
            if(op[i]) {
                int x1 = s.top(); s.pop();
                int x2 = s.top(); s.pop();
                int result;
                if(i == 0) result = x1 + x2;
                else if(i == 1) result = x1 - x2;
                else if(i == 2) result = x1 * x2;
                else result = x1 / x2;
                s.push(result);
                op[i]--;
                go();
                op[i]++;
                s.pop();
                s.push(x2);
                s.push(x1);
            }
        }
    }
    else {
        ans_min = min(ans_min, s.top());
        ans_max = max(ans_max, s.top());
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &number[i]);
    for(int i=0; i<4; i++)
        scanf("%d", &op[i]);

    for(int i=N-1; i>=0; i--)
        s.push(number[i]);
    go();

    printf("%d\n%d\n", ans_max, ans_min);

    return 0;
}
