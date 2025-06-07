#include <iostream>
#include <unordered_set>

using namespace std;

int n;
string command[100000];
int x[100000];
unordered_set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> command[i] >> x[i];
    }

    for(int i=0; i<n; i++){
        if(command[i]=="find"){
            if(s.find(x[i]) != s.end()){
                cout << "true\n";
            }
            else{
                cout << "false\n";
            }
        }
        else if(command[i] == "add"){
            s.insert(x[i]);
        }
        else{
            s.erase(x[i]);
        }

    }


    // Please write your code here.

    return 0;
}
