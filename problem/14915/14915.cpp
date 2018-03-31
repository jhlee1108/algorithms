#include <cstdio>
#include <stack>

using namespace std;

int m, n;
stack<int> s;

int main() {
    scanf("%d %d", &m, &n);
    
    if(m == 0) {
        puts("0");
        return 0;
    }

    while(m) {
        s.push(m % n);
        m /= n;
    }

    while(!s.empty()) {
        int x = s.top();
        char c;
        
        if(x >= 10) c = 'A' + (x - 10);
        else c = '0' + x;
        
        printf("%c", c);
        s.pop();
    }
    printf("\n");

    return 0;
}
