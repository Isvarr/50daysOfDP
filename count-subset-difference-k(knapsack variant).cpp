#include <bits/stdc++.h>
using namespace std;

int DiffSubsetSum(vector<int> &arr,int difference) {
    int n = arr.size();
    int sum = 0;
    for (int x : arr) sum += x;
    int required = (sum+difference)/2;
    if ((sum+difference)%2==1) return -1;
    vector<vector<int>> dp(n+1, vector<int>(required+1, 0));
    for (int i=0;i<=required;i++){
        dp[0][i]=0;
    }
    for (int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for (int i=1;i<=n;i++){
        for (int j=1; j<=required;j++){
            int yes = false;
            int no = dp[i-1][j];
            if (arr[i-1]<=j){
                yes = dp[i-1][j-arr[i-1]];
            }
            dp[i][j] = yes+no;
        }
    }
    return dp[n][required];
}
