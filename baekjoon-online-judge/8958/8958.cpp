#include <iostream>

using namespace std;

int main() {
    int t;

    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int sum = 0;
        int psum = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'O') {
                psum++;
                sum += psum;
            }
            else psum = 0;
        }

        cout << sum << '\n';
    }

    return 0;
}
