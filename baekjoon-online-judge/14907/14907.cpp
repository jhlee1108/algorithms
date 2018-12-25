#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

char curr, p;
int d, date[26], indegree[26], result[26];
vector<int> adj[26];
queue<int> q;

int main() {
    memset(indegree, -1, sizeof(indegree));
    while(scanf("%c %d", &curr, &d) == 2) {
        date[curr-'A'] = d;
        indegree[curr-'A'] = 0;
        while(scanf("%c", &p)) {
            if(p == ' ') continue;
            else if(p == '\n') break;
            else {
                adj[p-'A'].push_back(curr-'A');
                indegree[curr-'A']++;
            }
        }
    }
    
    for(int i=0; i<26; i++)
        if(indegree[i] == 0) q.push(i);

    int ans = 0;
    while(!q.empty()) {
        int n = q.front();
        q.pop();
        result[n] += date[n];
        ans = max(ans, result[n]);
        for(int x : adj[n]) {
            result[x] = max(result[x], result[n]);
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }

    printf("%d\n", ans);

    return 0;
}
