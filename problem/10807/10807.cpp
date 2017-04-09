#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    int input;
    vector<int> v;

    cin >> n;

    while(n--) {
        cin >> input;
        v.push_back(input);
    }

    cin >> input;
    cout << count(v.begin(), v.end(), input) << endl;

    return 0;
}
