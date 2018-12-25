#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Person {
    int age, sign_up;
    string name;
};

bool cmp(const Person &a, const Person &b) {
    if(a.age < b.age)
        return true;
    else if(a.age == b.age)
        return a.sign_up < b.sign_up;
    return false;
}

int main() {
    int n;

    cin >> n;
    vector<Person> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i].age >> v[i].name;
        v[i].sign_up = i;
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<n; i++)
        cout << v[i].age << ' ' << v[i].name << '\n';

    return 0;
}
