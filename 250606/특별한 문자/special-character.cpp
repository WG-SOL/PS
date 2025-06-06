#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string str;

int main() {
    cin >> str;

    unordered_map<char,int> freq;
    for(char c : str){
        freq[c]++;
    }

    bool flag = false;

    for(char c : str){
        if(freq[c] ==1){
            cout << c;
            return 0;
        }
    }
     
    if(!flag) cout << "None";

    // Please write your code here.

    return 0;
}
