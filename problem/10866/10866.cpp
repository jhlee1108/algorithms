#include <iostream>

using namespace std;

class Deque {
    private:
        int length;
        int *arr;
    public:
        Deque() {
            length = 0;
            arr = new int[100001];
        }

        ~Deque() {
            delete []arr;
        }

        void push_front(int x);
        void push_back(int x);
        int pop_front();
        int pop_back();
        int size();
        int empty();
        int front();
        int back();
};

void Deque::push_front(int x) {
    copy(arr, arr+length, arr+1);
    arr[0] = x;
    length++;
}

void Deque::push_back(int x) {
    arr[length++] = x;
}

int Deque::pop_front() {
    if(length == 0)
        return -1;
    int result = arr[0];
    copy(arr+1, arr+length, arr);
    length--;
    return result;
}

int Deque::pop_back() {
    if(length == 0)
        return -1;     
    return arr[--length];
}

int Deque::size() {
    return length;
}

int Deque::empty() {
    if(length == 0)
        return 1;
    else
        return 0;
}

int Deque::front() {
    if(length == 0)
        return -1; 
    return arr[0];
}

int Deque::back() {
    if(length == 0)
        return -1;
    return arr[length-1];
}

int main() {
    Deque deque;
    string input;
    int n, x;

    cin >> n;

    while(n--) {
        cin >> input;

        if(input == "push_front") {
            cin >> x;
            deque.push_front(x);
        }
        else if(input == "push_back") {
            cin >> x;
            deque.push_back(x);
        }
        else if(input == "pop_front")
            cout << deque.pop_front() << endl;
        else if(input == "pop_back")
            cout << deque.pop_back() << endl;
        else if(input == "size")
            cout << deque.size() << endl;
        else if(input == "empty")
            cout << deque.empty() << endl;
        else if(input == "front")
            cout << deque.front() << endl;
        else
            cout << deque.back() << endl;
    }

    return 0;
}
