#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string empty = "";

    cin >> n;

    for(int i=0; i<n; i++) {
        cout.width(n-i);
        cout.fill('*');
        cout << empty << endl;
    }

    return 0;
}
