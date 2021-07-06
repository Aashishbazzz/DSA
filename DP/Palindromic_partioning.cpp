// By Aashish Saxena
// Problem link -> https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1


  int dp[510][510];
    
    bool isPalindrome(string s,int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i, int j)
    {
        if(i>=j || isPalindrome(s,i,j))
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int k,ans,left,right;
        ans= INT_MAX;
        
        for(k=i;k<j;k++)
        {
            if(dp[i][k]!=-1)
            {
                left= dp[i][k];
            }
            else
            {
                left= solve(s,i,k);
            }
            
            if(dp[k+1][j]!=-1)
            {
                right= dp[k+1][j];
            }
            else
            {
                right= solve(s,k+1,j);
            }
            
            ans= min(left+right+1,ans);
        }
        
        dp[i][j]= ans;
        
        return ans;
    }

    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        
        int ans= solve(str,0,str.length()-1);
        
        return ans;
    }
