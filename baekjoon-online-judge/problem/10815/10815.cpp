#include <cstdio>
#include <set>

using namespace std;

int main() {
    int n, m, input;
    set<int> s;

    scanf("%d", &n);

    while(n--) {
        scanf("%d", &input);
        s.insert(input);
    }

    scanf("%d", &m);

    while(m--) {
        scanf("%d", &input);
        printf("%d ", int(s.count(input)));
    }

    return 0;
}

