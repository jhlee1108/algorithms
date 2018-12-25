#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string ans = "";
int k = 0;

void hanoi(string a, string b, string c, int n) {
    if(n <= 0)
        return;
    else {
        hanoi(a, c, b, n-1);
        ans += (a + " " + c + "\n");
        k++;
        hanoi(b, a, c, n-1);
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    hanoi("1", "2", "3", n);

    printf("%d\n", k);
    printf("%s", ans.c_str());

    return 0;
}
