#include <iostream>

using namespace std;

int n;
int price[100000];


int main() {
   
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> price[i];

    int max_value = 0;
    int min_value = price[0];
    for(int i = 0; i < n; i++) {
        int profit = price[i] - min_value;
        
        if(profit > max_value)
            max_value = profit;
        
        if(min_value > price[i])
            min_value = price[i];
    }

    cout << max_value;
    return 0;
}