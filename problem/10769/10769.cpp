#include <cstdio>

int happy_cnt, sad_cnt;

int main() {
    char c;
    int index = 0;
    while(scanf("%c", &c) == 1) {
        if(index == 0 && c == ':') index++;
        else if(index == 1 && c == '-') index++;
        else if(index == 2 && c == ')') {
            happy_cnt++;
            index = 0;
        }
        else if(index == 2 && c == '(') {
            sad_cnt++;
            index = 0;
        }
        else index = 0;
    }

    if(happy_cnt == 0 && sad_cnt == 0) puts("none");
    else if(happy_cnt == sad_cnt) puts("unsure");
    else if(happy_cnt > sad_cnt) puts("happy");
    else puts("sad");

    return 0;
}
