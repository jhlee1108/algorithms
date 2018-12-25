#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main() {
    scanf("%d", &n);
    int m = 1e9;
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        v.push_back(x);
        m = min(m, x);
    }

    for(int i=1; i<=m; i++) {
        for(int j=0; j<v.size(); j++) {
            if(v[j] % i != 0) break;
            if(j == v.size()-1) printf("%d\n", i);
        }
    }

    return 0;
}
