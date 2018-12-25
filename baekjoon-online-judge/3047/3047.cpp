#include <cstdio>

int main() {
    int a[3];
    char c;

    for(int i=0; i<3; i++)
        scanf("%d", &a[i]);

    for(int i=0; i<2; i++)
        for(int j=i+1; j<3; j++)
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    scanf("%c", &c);
    for(int i=0; i<3; i++) {
        scanf("%c", &c);
        printf("%d ", a[c-65]);
    }

    return 0;
}
