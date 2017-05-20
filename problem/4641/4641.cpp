#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int x;
    int ans;

    while(1) {
        scanf("%d", &x);
        if(x == -1) break;

        while(1) {
            if(x == 0) break;
            v.push_back(x);
            scanf("%d", &x);
        }

        ans = 0;
        for(int i=0; i<v.size(); i++) {
            int y = v[i];
            for(int j=0; j<v.size(); j++)
                if(2*y == v[j]) ans++;
        }

        printf("%d\n", ans);
        v.clear();
    }
}
