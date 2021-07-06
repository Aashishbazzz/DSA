// By Aashish Saxena
// Problem Link -> https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1


  int solve(int arr[], int i, int j,vector<vector<int>> &dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int k,temp,ans;
        ans= INT_MAX;
        
        for(k=i;k<j;k++)
        {
            temp= solve(arr,i,k,dp)+ solve(arr,k+1,j,dp)+ arr[i-1]*arr[k]*arr[j];
            
            if(temp<ans)
            {
                ans=temp;
            }
        }
        
        dp[i][j]=ans;
        
        return ans;
    }
    
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        
        int ans= solve(arr,1,N-1,dp);
        
        return ans;
    }
