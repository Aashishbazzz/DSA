//By Aashish Saxena

//Problem link -> https://practice.geeksforgeeks.org/problems/coin-change2448/1   


 long long int count( int S[], int m, int n )
    {
        vector<vector<long long int>> dp(m+1,vector<long long int>(n+1));
        long long int i,j;
        
        for(i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        for(i=0;i<=m;i++)
        {
            dp[i][0]=1;
        }
        
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(S[i-1]<=j)
                {
                    dp[i][j]= dp[i][j-S[i-1]]+ dp[i-1][j];
                }
                else
                {
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        
        return dp[m][n];
    }
