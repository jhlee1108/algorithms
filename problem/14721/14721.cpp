#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define PII pair<int,int>
#define INF 100000000

using namespace std;

int N;
vector<PII> v;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int x, y; scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }

    double min_rss = INF;
    int ans_a, ans_b;
    for(int a=1; a<=100; a++) {
        for(int b=1; b<=100; b++) {
            double rss = 0;
            for(int i=0; i<N; i++) {
                rss += pow(double(v[i].second - (a*v[i].first + b)), 2);
            }
            if(min_rss > rss) {
                min_rss = rss; ans_a = a; ans_b = b;
            }
        }
    }

    printf("%d %d\n", ans_a, ans_b);

    return 0;
}
