#include <cstdio>

int table[4][4] = { {0, 2, 0, 1},
                    {2, 1, 3, 0},
                    {0, 3, 2, 1},
                    {1, 0, 1, 3}};
int dna[1000000];

int main() {
    int n; scanf("%d\n", &n);
    for(int i=0; i<n; i++) {
        char c; scanf("%c", &c);
        int x;
        switch(c) {
            case 'A':
                x = 0;
                break;
            case 'G':
                x = 1;
                break;
            case 'C':
                x = 2;
                break;
            case 'T':
                x = 3;
                break;
        }

        dna[i] = x;
    }

    for(int i=n-2; i>=0; i--)
        dna[i] = table[dna[i]][dna[i+1]];

    char ans;
    switch(dna[0]) {
        case 0:
            ans = 'A';
            break;
        case 1:
            ans = 'G';
            break;
        case 2:
            ans = 'C';
            break;
        case 3:
            ans = 'T';
            break;
    }

    printf("%c\n", ans);

    return 0;
}
