#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string input;

    cin >> input;

    for(char c='a'; c<='z'; c++)
        cout << count(input.begin(), input.end(), c) << ' ';

    return 0;
}
