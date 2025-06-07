#include <iostream>
#include <unordered_set>

using namespace std;

const int MAX_N = 100000;
int n;
int arr[MAX_N];
unordered_set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }

    int counter=0;
    for (int i = 0; i < n; i++) {
        if(s.find(arr[i]) != s.end()){
            counter++;
        }
    }

    cout << counter;

    // Please write your code here.

    return 0;
}
