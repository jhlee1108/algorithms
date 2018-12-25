#include <iostream>
#include <string>

using namespace std;

int main() {
    int count = 0;
    string input;

    while(getline(cin, input, ','))
        count += stoi(input);

    cout << count << endl;

    return 0;
}
