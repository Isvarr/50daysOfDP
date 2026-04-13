#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int c : coins) {
            if (c <= i) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    if (dp[amount] > amount)
        return -1;
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5,10,25};
    int amount = 85;

    int ans = coinChange(coins, amount);
    cout << ans << endl;

    return 0;
}
