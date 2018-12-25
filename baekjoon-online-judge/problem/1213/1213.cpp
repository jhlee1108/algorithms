#include <iostream>

using namespace std;

int main() {
    int a[26] = {0,};
    string s;

    getline(cin, s);

    for(int i=0; i<s.size(); i++)
        a[s[i]-65]++;

    int x = 0;
    int y = -1;
    for(int i=0; i<26; i++) {
        if(a[i] % 2 == 1) {
            x++;
            if(x > 1) break;
            y = i;
        }
    }

    if(x > 1) cout << "I'm Sorry Hansoo\n";

    else {
        for(int i=0; i<26; i++) {
            int k = a[i]/2;
            for(int j=0; j<k; j++) {
                if(a[i] != 0) {
                    cout << char(i+65);
                    a[i]--;
                }
            }
        }

        if(y != -1) {
            cout << char(y+65);
            a[y]--;
        }

        for(int i=25; i>=0; i--) {
            int k = a[i];
            for(int j=0; j<k; j++) {
                if(a[i] != 0) {
                    cout << char(i+65);
                    a[i]--;
                }
            }
        }
    }

    return 0;
}
