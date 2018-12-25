#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, num[101], check[101];
vector<int> v;
int dfs(int s, int x) {
    if(num[x] == s && check[num[x]]) return 1;
    if(check[num[x]]) return 0;
    check[num[x]] = 1;
    int ret = dfs(s, num[x]);
    if(!ret) check[num[x]] = 0;
    else v.push_back(num[x]);
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &num[i]);
    
    for(int i=1; i<=N; i++) {
        if(!check[i]) {
            check[i] = 1;
            int ret = dfs(i, i);
            if(!ret) check[i] = 0;
            else v.push_back(i);
        }
    }

    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for(int i=0; i<v.size(); i++)
        printf("%d\n", v[i]);
    
    return 0;
}
