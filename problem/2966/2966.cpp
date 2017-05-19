#include <iostream>

#define MAX(A,B) (A > B ? A : B)

using namespace std;

int main() {
    char a[] = {'A', 'B', 'C'};
    char b[] = {'B', 'A', 'B', 'C'};
    char g[] = {'C', 'C', 'A', 'A', 'B', 'B'};
    int n;
    int c[3] = {0,};
    string s;

    cin >> n >> s;

    for(int i=0; i<n; i++) {
        if(a[i%3] == s[i]) c[0]++;
        if(b[i%4] == s[i]) c[1]++;
        if(g[i%6] == s[i]) c[2]++;
    }

    int max = MAX(c[0], MAX(c[1], c[2]));

    cout << max << '\n';
    if(c[0] == max) cout << "Adrian" << '\n';
    if(c[1] == max) cout << "Bruno" << '\n';
    if(c[2] == max) cout << "Goran" << '\n';

    return 0;
}
