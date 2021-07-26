// By Aashish Saxena
// Find the sub array with the maximum sum

// Problem link -> https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

// Kadane's algorithm implementation
int maxSubarraySum(int arr[], int n)
    {
        
        int ans=INT_MIN,cur=arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(cur>ans)
            {
                ans=cur;
            }
            if(cur<0)
            {
                cur=arr[i];
            }
            else
            {
                cur=cur+arr[i];
            }
            
            if(cur>ans)
            {
                ans=cur;
            }
        }
        if(cur>ans)
        {
            ans=cur;
        }
        
        return ans;
    }
