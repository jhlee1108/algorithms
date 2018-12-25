#include <string>
#include <cstdio>
#include <map>

using namespace std;

int N, M;
char in[22];
string names[100001];
map<string, int> numbers;

int main() {
    scanf("%d %d\n", &N, &M);
    for(int i=1; i<=N; i++) {
        scanf("%s\n", in);
        names[i] = in;
        numbers.insert(make_pair(names[i], i));
    }

    while(M--) {
        scanf("%s", in);
        if(isdigit(in[0])) printf("%s\n", names[atoi(in)].c_str());
        else printf("%d\n", numbers[string(in)]);
    }

    return 0;
}
