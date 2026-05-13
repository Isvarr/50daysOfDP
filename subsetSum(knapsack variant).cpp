#include <bits/stdc++.h>
using namespace std;

bool subsetsum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false;
    }
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
    return dp[n][sum];
}

int main() {

    vector<int> arr = {3, 34, 4, 12, 5, 2};

    int target = 9;

    if (subsetsum(arr, target))
        cout << "Subset Exists";
    else
        cout << "Subset Does Not Exist";

    return 0;
}
