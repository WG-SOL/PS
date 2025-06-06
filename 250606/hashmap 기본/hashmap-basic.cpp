#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n;
string cmd[100000];
int k[100000];
int v[100000];

int main() {
    cin >> n;

    unordered_map<int,int> m;

    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        cin >> k[i];
        if (cmd[i] == "add") {
            cin >> v[i];
            m[k[i]] = v[i];
        }
        else if(cmd[i] == "remove"){
            m.erase(k[i]);
        }
        else if(cmd[i] == "find"){
            if(m.find(k[i]) != m.end()){
                cout << m.find(k[i])->second << "\n";
            }
            else{
                cout << "None\n";
            }
        }

    }

    // Please write your code here.

    return 0;
}
