#include <iostream>

using namespace std;

string num;
char max_c, c;
int max_cnt, cnt;

int main() {
    for(int t=0; t<3; t++) {
        cin >> num;
        max_c = c = num[0];
        max_cnt = cnt = 1;
        for(int i=1; i<num.size(); i++) {
            if(num[i] == c) cnt++;
            else {
                if(cnt > max_cnt) {
                    max_cnt = cnt;
                    max_c = c;
                }
                cnt = 1;
            }
            c = num[i];
        }

        if(cnt > max_cnt) {
            max_cnt = cnt;
            max_c = c;
        }

        cout << max_cnt << '\n';
    }

    return 0;
}
