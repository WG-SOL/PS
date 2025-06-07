#include <iostream>
#include <algorithm>
using namespace std;

int A[100001], B[100001]; // 1~2N까지 커버
int N;

int main() {
    cin >> N;
    int temp;

    // B[temp] = 1 마킹
    for (int i = 0; i < N; i++) {
        cin >> temp;
        B[temp] = 1;
    }

    // A[k] = 1 if k not in B
    int idx = 0;
    for (int k = 1; k <= 2 * N; k++) {
        if (B[k] != 1) {
            A[idx++] = k;
        }
    }

    // B 배열 다시 채움 (입력 순서를 저장한 건 아니니까 다시 구성)
    idx = 0;
    for (int k = 1; k <= 2 * N; k++) {
        if (B[k] == 1) {
            B[idx++] = k;
        }
    }

    // 정렬
    sort(A, A + N);
    sort(B, B + N);

    // A[i] > B[i] 카운트
    int answer = 0, b_idx = 0;
    for (int a_idx = 0; a_idx < N; a_idx++) {
        if (b_idx < N && A[a_idx] > B[b_idx]) {
            answer++;
            b_idx++;
        }
    }

    cout << answer;
    return 0;
}
