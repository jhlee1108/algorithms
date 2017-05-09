#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<pair<int,int>> v;
    vector<int> ans;
    int n, a, b;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a,b));
    }

    for(int i=0; i<n; i++) {
        int c = 1;
        for(int j=0; j<n; j++) {
            if(v[j].first > v[i].first && v[j].second > v[i].second)
                c++;
        }
        ans.push_back(c);
    }

    for(int i=0; i<n; i++)
        printf("%d ", ans[i]);

    return 0;
}
