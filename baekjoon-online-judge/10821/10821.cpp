#include <iostream>

using namespace std;

int main() {
    int count = 0;
    string input;

    while(getline(cin, input, ','))
        count++;

    cout << count << endl;

    return 0;
}
