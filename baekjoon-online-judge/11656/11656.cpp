#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string input; cin >> input;
    vector<string> suffix_array;

    for(int i=0; i<input.size(); i++) {
        suffix_array.push_back(input.substr(i, input.size()));
    }

    sort(suffix_array.begin(), suffix_array.end());

    for(auto &x : suffix_array) {
        cout << x << endl;
    }
}
