#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];


int solve(int wt[],int val[], int W, int n){
  if (n==0 || W==0){
    return  0;
  }
  if (dp[n][W]!=-1){
    return dp[n][W];
  }
  if (wt[n-1]<=W){
    return dp[n][W]=max(val[n-1]+solve(wt,val,W-wt[n-1],n-1),solve(wt,val,W,n-1));
  }
  else{
    return dp[n][W]=solve(wt,val,W,n-1);
  }
}
  
int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};

    int W = 7;
    int n = 4;

    memset(dp, -1, sizeof(dp));

    cout << solve(wt, val, W, n);

    return 0;
}
