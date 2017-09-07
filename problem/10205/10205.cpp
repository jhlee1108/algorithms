#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;

    for(int k=1; k<=T; k++) {
        int h; cin >> h;
        string s; cin >> s;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'c') h++;
            else h--;
        }

        cout << "Data Set " << k << ":\n";
        cout << h << "\n\n";
    }

    return 0;
}
