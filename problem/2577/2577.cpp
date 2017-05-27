#include <cstdio>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    int d[10] = {0,};

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int m = a * b * c;
    string s = to_string(m);

    for(int i=0; i<s.size(); i++)
        d[s[i]-'0']++;

    for(int i=0; i<10; i++)
        printf("%d\n", d[i]);

    return 0;
}
