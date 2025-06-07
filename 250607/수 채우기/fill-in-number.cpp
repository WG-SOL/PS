#include <iostream>
#include <climits>
using namespace std;

int n;

int main() {
    
    cin >> n;

    int answer = INT_MAX; 

    for (int five = 0; five <= n / 5; ++five) {
        int rest = n - five * 5;
        if (rest % 2 == 0) {
            int two = rest / 2;
            answer = min(answer, five + two);
        }
    }

    if (answer == INT_MAX) cout << -1;
    else cout << answer;

    return 0;
}