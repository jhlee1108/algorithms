#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string input; cin >> input;
    int a[3] = {1, 0, 0};

    for(int i=0; i<input.size(); i++) {
        if(input[i] == 'A') swap(a[0], a[1]);
        else if(input[i] == 'B') swap(a[1], a[2]);
        else swap(a[0], a[2]);
    }

    for(int i=0; i<3; i++)
        if(a[i] == 1) cout << i+1 << '\n';

    return 0;
}
