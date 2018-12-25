#include <cstdio>

int n[11111];

void D(int x) {
    int a = x/10000;
    int b = (x%10000)/1000;
    int c = (x%1000)/100;
    int d = (x%100)/10;
    int e = x%10;

    int y = x+a+b+c+d+e;
    n[y]++;
}

int main() {
    for(int i=1; i<=10000; i++)
        D(i);

    for(int i=1; i<=10000; i++)
        if(n[i] == 0) printf("%d\n", i);

    return 0;
}
