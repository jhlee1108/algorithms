#include <cstdio>
#include <vector>
#include <algorithm>

#define PII pair<int,int>

using namespace std;

vector<PII> v;

int main() {
    int n; scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int s, t; scanf("%d %d", &s, &t);
        v.push_back(make_pair(s, 1));
        v.push_back(make_pair(t, -1));
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int cnt = 0;
    for(int i=0; i<v.size(); i++) {
        if(v[i].second == 1) cnt++;
        else cnt --;
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);

    return 0;
}
