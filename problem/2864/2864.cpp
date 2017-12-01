#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A, B;

int main() {
    cin >> A >> B;

    replace(A.begin(), A.end(), '6', '5');
    replace(B.begin(), B.end(), '6', '5');
    cout << stoi(A) + stoi(B) << ' ';

    replace(A.begin(), A.end(), '5', '6');
    replace(B.begin(), B.end(), '5', '6');
    cout << stoi(A) + stoi(B) << '\n';

    return 0;
}
