#include <cstdio>

using namespace std;

int main() {
    int n, m, input;
    int *s = new int[20000001];

    scanf("%d", &n);

    while(n--) {
        scanf("%d", &input);
        s[input + 10000000]++;
    }

    scanf("%d", &m);

    while(m--) {
        scanf("%d", &input);
        printf("%d ", s[input + 10000000]);
    }

    return 0;
}
