#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int count = 0;
    string input;
    string s;

    while(cin >> input)
        s += input;

    istringstream sin(s);

    while(getline(sin, input, ','))
        count += stoi(input);

    cout << count << endl;

    return 0;
}
