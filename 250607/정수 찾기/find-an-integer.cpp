#include <iostream>
#include <unordered_set>
using namespace std;

int n;
int m;
int a[100000];
int b[100000];
unordered_set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        if(s.find(b[i]) != s.end()){
            cout <<1<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
    }

    // Please write your code here.

    return 0;
}
