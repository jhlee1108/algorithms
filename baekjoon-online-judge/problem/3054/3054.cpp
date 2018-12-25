#include <iostream>

using namespace std;

string in, out;

int main() {
    cin >> in;

    for(int i=0; i<5; i++) {
        for(int j=1; j<=in.size(); j++) {
            char c = j % 3 == 0 ? '*' : '#';
            out = "....";
            if(i == 0 || i == 4) out[2] = c;
            else if(i == 1 || i == 3) out[1] = out[3] = c;
            else {
                if(j != 1 && (j-1) % 3 == 0) c = '*';
                out[0] = c;
                out[2] = in[j-1];
            }
            cout << out;
        }
        char end = '.';
        if(i == 2) end = in.size() % 3 == 0 ? '*' : '#';
        cout << end << '\n';
    }

    return 0;
}
