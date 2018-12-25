#include <cstdio>
#include <deque>

using namespace std;

deque<int> dq;
int n, m, ans;

int main() {
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++)
        dq.push_back(i);

    for(int i=1; i<=m; i++) {
        int x; scanf("%d", &x);
        
        if(dq.front() == x)
            dq.pop_front();

        else {
            int k = 0;
            for(int j=0; j<dq.size(); j++) {
                if(dq.front() != x) {
                    int temp = dq.front();
                    dq.pop_front();
                    dq.push_back(temp);
                    k++;
                }

                else {
                    if(k > (dq.size()-1)/2)
                        ans += (dq.size() - k);
                    else
                        ans += k;
                    dq.pop_front();
                    break;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
