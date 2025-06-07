#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N;
int B[50000];
int A[50000];

unordered_set<int> s;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        s.insert(B[i]); // A Hash
    }

    int idx=0;
    for(int i=1; i<=2*N; i++){
        if(s.find(i) == s.end()){
            A[idx++] = i;
        }
    }

    sort(A,A+N);
    sort(B,B+N);

    int answer=0;
    int b_idx=0;

    for(int a_idx=0; a_idx<N; a_idx++){
        if(b_idx<N && A[a_idx]>B[b_idx]){
            answer++;
            b_idx++;
        }
    }

    cout << answer;

    // Please write your code here.

    return 0;
}
