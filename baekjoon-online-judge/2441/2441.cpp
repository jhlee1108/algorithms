#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string empty = "";

    cin >> n;

    for(int i=0; i<n; i++) {
        cout.width(n);
        cout.fill('*');
        cout << left << empty << endl;
        empty += " ";
    }
    
    return 0;
}
