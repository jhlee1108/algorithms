#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int ans = -10000;
    vector<int> v;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    do {
        int sum=0;
        for(int i=1; i<n; i++)
            sum += (abs(v[i-1] - v[i]));
        ans = max(ans, sum);
    } while(next_permutation(v.begin(), v.end()));

    printf("%d", ans);

    return 0;
}
