#include <cstdio>
#include <vector>

using namespace std;

#define ll long long
#define INF 1e9

struct line {
    int x1, y1, x2, y2;
    line(int x1, int y1, int x2, int y2):x1(x1), y1(y1), x2(x2), y2(y2) {
        sort_point();
    }

    void sort_point() {
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
    }
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
vector<line> v;
int L, N, cur_d, cur_x, cur_y;

int main() {
    scanf("%d %d", &L, &N);

    v.push_back(line(-L, L+1, L, L+1));
    v.push_back(line(L+1, L, L+1, -L));
    v.push_back(line(-L, -L-1, L, -L-1));
    v.push_back(line(-L-1, L, -L-1, -L));

    ll ans = 0;
    for(int i=0; i<=N; i++) {
        int t, nx, ny; char dir;
        if(i != N) scanf("%d %c\n", &t, &dir);
        else t = L*3;

        nx = cur_x + dx[cur_d]*t;
        ny = cur_y + dy[cur_d]*t;

        int min_dist = INF;
        if(cur_d == 0) {
            for(int j=0; j<v.size(); j++)
                if((cur_x < v[j].x1 && v[j].x1 <= nx) && (v[j].y1 <= ny && ny <= v[j].y2))
                    min_dist = min(min_dist, v[j].x1 - cur_x);
        }
        else if(cur_d == 1) {
            for(int j=0; j<v.size(); j++) 
                if((v[j].y2 < cur_y && ny <= v[j].y2) && (v[j].x1 <= nx && nx <= v[j].x2))
                    min_dist = min(min_dist, cur_y - v[j].y2);
        }
        else if(cur_d == 2) {
            for(int j=0; j<v.size(); j++)
                if((v[j].x2 < cur_x && nx <= v[j].x2) && (v[j].y1 <= ny && ny <= v[j].y2))
                    min_dist = min(min_dist, cur_x - v[j].x2);
        }
        else {
            for(int j=0; j<v.size(); j++)
                if((cur_y < v[j].y1 && v[j].y1 <= ny) && (v[j].x1 <= nx && nx <= v[j].x2))
                    min_dist = min(min_dist, v[j].y1 - cur_y);
        }

        if(min_dist != INF) {
            printf("%lld\n", ans + min_dist);
            return 0;
        }
        
        v.push_back(line(cur_x, cur_y, nx, ny));
        if(dir == 'R') cur_d = (cur_d + 1) % 4;
        else cur_d = (cur_d + 3) % 4;
        cur_x = nx;
        cur_y = ny;
        ans += t;
    }
}
