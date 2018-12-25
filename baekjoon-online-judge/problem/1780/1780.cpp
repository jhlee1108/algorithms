#include <cstdio>
#include <vector>

using namespace std;

int m[2200][2200] = {0,};
int ans[5] = {0,};

int cut(int i, int j, int len) {
    if(len <= 1) {
        ans[m[i][j]+1]++;
        return m[i][j];
    }

    else {
        int new_len = len/3;
        vector<int> v;
        bool merge = true;

        for(int a=0; a<3; a++)
            for(int b=0; b<3; b++)
                v.push_back(cut(i+a*new_len, j+b*new_len, new_len));

        for(int a=1; a<v.size(); a++) {
            if(v[a-1] != v[a]) {
                merge = false;
                break;
            }
        }

        if(merge) {
            ans[v[0]+1] -= 8;
            return v[0];
        }

        else
            return 2;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d", &m[i][j]);

    cut(1, 1, n);

    printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);

    return 0;
}
