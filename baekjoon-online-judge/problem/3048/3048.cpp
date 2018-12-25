#include <cstdio>

int N1, N2, T, ans[26], group[26];
char temp;

int main() {
    scanf("%d %d\n", &N1, &N2);
    int size = N1 + N2;

    for(int i=N1-1; i>=0; i--) {
        scanf("%c\n", &temp);
        ans[i] = temp - 'A';
        group[ans[i]] = 1;
    }
    for(int i=N1; i<size; i++) {
        scanf("%c\n", &temp);
        ans[i] = temp - 'A';
        group[ans[i]] = 2;
    }

    scanf("%d", &T);
    for(int t=1; t<=T; t++)
        for(int i=0; i<size-1; i++)
            if(group[ans[i]] == 1 && group[ans[i+1]] == 2) {
                temp = ans[i+1];
                ans[i+1] = ans[i];
                ans[i] = temp;
                i++;
            }

    for(int i=0; i<size; i++)
        printf("%c", ans[i] + 'A');
    printf("\n");

    return 0;
}
