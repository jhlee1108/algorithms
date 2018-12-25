#include <iostream>

using namespace std;

int main() {
    string a, b;

    cin >> a >> b;

    for(int i=2; i>=0; i--) {
        if(a[i] > b[i]) {
            for(int j=2; j>=0; j--)
                cout << a[j];
            cout << '\n';
            break;
        }
        else if(a[i] < b[i]) {
            for(int j=2; j>=0; j--)
                cout << b[j];
            cout << '\n';
            break;
        }       
    }

    return 0;
}
