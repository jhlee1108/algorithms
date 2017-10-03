#include <cstdio>
#include <vector>

using namespace std;

int n, m, k;
vector<int> v;

int main() {
    while(1) {
        scanf("%d %d %d", &n, &k, &m);
        if(n == 0 && m == 0 && k == 0) break;

        v.clear();
        for(int i=0; i<n; i++)
            v.push_back(i);

        m--;
        while(v.size() > 1) {
            v.erase(v.begin() + m);
            m = (m + k - 1) % v.size();
        }

        printf("%d\n", v[0]+1);
    }

    return 0;
}
