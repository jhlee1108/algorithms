#include <iostream>

using namespace std;

int main() {
    int n, x;

    cin >> n >> x;

    auto is_less = [&](int number) {
        return number < x;
    };

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        if(is_less(num))
            cout << num << ' ';
    }

    return 0;
}
