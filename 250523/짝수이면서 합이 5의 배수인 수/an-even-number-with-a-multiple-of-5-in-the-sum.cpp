#include <iostream>
#include <string>

using namespace std;



string find(string temp){
    int n = (temp[0]-'0')+(temp[1]-'0');
    if(stoi(temp) %2 ==0 && n % 5==0){    
            return "Yes";
        }
    
    else return "No";
}



int main() {
    string s;
    cin >> s;

    cout << find(s);

    return 0;
}