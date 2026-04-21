#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a,b;
        cin>>a>>b;
        vector<int>dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            if (a[i-1] != b[i-1]) {
                x = 1;
            } else {
                x = 0;
            }
            dp[i] = min(dp[i], dp[i-1] + x);
            if (i>=2) {
                int y = 0;
                if (a[i-2] != a[i-1]) {
                    y++;
                }
                if (b[i-2] != b[i-1]) {
                    y++;
                }
                dp[i] = min(dp[i], dp[i-2] + y);
            }
        }
        cout << dp[n]<<endl;
    }

    return 0;
}
