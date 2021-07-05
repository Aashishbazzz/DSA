// Aashish Saxena
// Problem link -> https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#	


int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1,vector<int>(V+1));
	    int i,j;
	    
	    for(i=0;i<=V;i++)
	    {
	        dp[0][i]=0;
	    }
	    for(i=0;i<=M;i++)
	    {
	        dp[i][0]=1;
	    }
	    
	    for(i=1;i<=M;i++)
	    {
	        for(j=1;j<=V;j++)
	        {
	            if(coins[i-1]<=j)
	            {
	                if(dp[i][j-coins[i-1]]!=0 && dp[i-1][j]!=0)
	                {
	                    dp[i][j]= min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
	                }
	                else
	                {
	                    if(dp[i][j-coins[i-1]]!=0)
	                    {
	                        dp[i][j]= dp[i][j-coins[i-1]]+1;
	                    }
	                    else
	                    {
	                        dp[i][j]= dp[i-1][j];
	                    }
	                }
	            }
	            else
	            {
	                dp[i][j]= dp[i-1][j];
	            }
	        }
	    }
	    
	    return dp[M][V]-1;
	} 
