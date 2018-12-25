#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(const tuple<int,int,int> &u, const tuple<int,int,int> &v) {
    return get<2>(u) > get<2>(v);    
}

int main() {
    int n, a, b, c;
    int d[101] = {0,};
    vector<tuple<int,int,int>> v;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v.push_back(make_tuple(a,b,c));
    }

    sort(v.begin(), v.end(), cmp);
    
    int cnt=0;
    for(int i=0; i<n; i++) {
        if(d[get<0>(v[i])] < 2) {
            printf("%d %d\n", get<0>(v[i]), get<1>(v[i]));
            d[get<0>(v[i])] += 1;
            cnt++;
            if(cnt == 3)
                break;
        }
    }

    return 0;
}
