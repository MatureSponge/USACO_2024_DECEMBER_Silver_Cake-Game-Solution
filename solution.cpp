#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        long long total_sum = 0;
        vector<int> cakes(N);
        for (int j = 0; j < N; j++){
            cin >> cakes[j];
            total_sum += cakes[j];
        }

        int start = N-(N/2-1), end = N-1;
        long long elsie_sum = 0;
        for (int j = start; j <= end; j++) elsie_sum += cakes[j];
        long long max_elsie = elsie_sum;

        for (int j = 0; j < N/2-1; j++) {
            end++; start++;

            elsie_sum += cakes[end % N];
            elsie_sum -= cakes[(start-1) % N];
            max_elsie = max(elsie_sum, max_elsie);
        }

        cout << total_sum-max_elsie << ' ' << max_elsie << '\n';
    }

    return 0;
}
