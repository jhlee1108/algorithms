#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y, z;
};

bool cmp_x(const Point &u, const Point &v) {
    if(u.x != v.x) return u.x < v.x;
    return u.y < v.y;
}

bool cmp_y(const Point &u, const Point &v) {
    return u.y < v.y;
}

int main() {
    vector<Point> v;
    int n;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        Point p;
        scanf("%d", &p.x);
        p.y = i;
        v.push_back(p);
    }

    sort(v.begin(), v.end(), cmp_x);

    for(int i=0; i<n; i++)
        v[i].z = i;

    sort(v.begin(), v.end(), cmp_y);

    for(int i=0; i<n; i++)
        printf("%d ", v[i].z);

    return 0;
}
