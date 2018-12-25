#include <iostream>

using namespace std;

int T;
string in1, in2;

int main() {
    cin >> T;

    while(T--) {
        cin >> in1 >> in2;

        cout << "Distances:";
        for(int i=0; i<in1.size(); i++) {
            int c1 = in1[i];
            int c2 = in2[i];
            cout << " " << (c2 - c1 >= 0 ? c2 - c1 : c2 - c1 + 26);
        }
        cout << '\n';
    }

    return 0;
}
