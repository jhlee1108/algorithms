#include <cstdio>
#include <vector>
#include <algorithm>

#define PII pair<int,int>

using namespace std;

vector<PII> v;

int main() {
    int n; scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end(), [](const PII &a, const PII &b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int ans = 1;
    int end_time = v[0].second;
    for(int i=1; i<v.size(); i++) {
        if(v[i].first >= end_time) {
            ans++;
            end_time = v[i].second;
        }
    }

    printf("%d\n", ans);

    return 0;
}
