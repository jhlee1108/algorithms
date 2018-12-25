#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
        v.push_back(i);
    
    M--;
    int cursor = M % v.size();
    printf("<%d", v[cursor]);
    v.erase(v.begin() + cursor);
    while(!v.empty()) {
        cursor = (cursor + M) % v.size();
        printf(", %d", v[cursor]);
        v.erase(v.begin() + cursor);
    }
    printf(">\n");

    return 0;
}
