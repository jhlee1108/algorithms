#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string star = "*";

    cin >> n;

    for(int i=0; i<n; i++) {
        cout << star << endl;
        star += "*";
    }

    return 0;
}

