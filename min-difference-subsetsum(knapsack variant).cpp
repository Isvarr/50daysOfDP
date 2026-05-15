#include <bits/stdc++.h>
using namespace std;

int MinDiffSubsetSum(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;
    for (int x : arr) sum += x;
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            bool no = dp[i - 1][j];
            bool yes = false;
            if (arr[i - 1] <= j) {
                yes = dp[i - 1][j - arr[i - 1]];
            }

            dp[i][j] = yes || no;
        }
    }
    int mn = INT_MAX;
    for (int s1 = 0; s1 <= sum/2; s1++) {
        if (dp[n][s1]) {
            int s2 = sum - s1;
            mn = min(mn, abs(s2 - s1));
        }
    }
    return mn;
}
