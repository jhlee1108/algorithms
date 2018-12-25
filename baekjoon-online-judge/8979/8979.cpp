#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct country {
    int num, rank, gold, silver, bronze;
    country(int n, int g, int s, int b) {
        num = n; gold = g; silver = s; bronze = b;
    }

    bool operator<(const country &x) const {
        return gold != x.gold ? gold > x.gold : (silver != x.silver ? silver > x.silver : bronze > x.bronze);
    
    }

    bool operator==(const country &x) const {
        return gold == x.gold && silver == x.silver && bronze == x.bronze;
    }
};

int N, K;
vector<country> v;

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) {
        int n, g, s, b;
        scanf("%d %d %d %d", &n, &g, &s, &b);
        v.push_back(country(n, g, s, b));
    }

    sort(v.begin(), v.end());

    v[0].rank = 0;
    for(int i=1; i<N; i++) {
        if(v[i-1] == v[i]) v[i].rank = v[i-1].rank;
        else v[i].rank = i;
    }
   
    for(int i=0; i<N; i++)
        if(v[i].num == K) {
            printf("%d\n", v[i].rank+1);
            break;
        }

    return 0;
}
