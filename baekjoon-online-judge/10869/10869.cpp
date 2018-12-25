#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main() {
    int a, b;
    vector<function<int(int,int)>> v;

    cin >> a >> b;

    v.push_back([](int x, int y) {
        return x + y;
    });

    v.push_back([](int x, int y) {
        return x - y;
    });

    v.push_back([](int x, int y) {
        return x * y;
    });

    v.push_back([](int x, int y) {
        return x / y;
    });

    v.push_back([](int x, int y) {
        return x % y;
    });

    for(auto &f : v)
        cout << f(a, b) << '\n';

    return 0;
}
