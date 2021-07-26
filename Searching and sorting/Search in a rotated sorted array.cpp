// By Aashish Saxena
// Given a rotated sorted array around some unknown point, we have to search for a target element x.

//Problem link -> https://leetcode.com/problems/search-in-rotated-sorted-array/

    int search(vector<int>& nums, int target) 
    {
        int s,e,mid;
        
        s=0;
        e=nums.size()-1;
        
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            
          // If rotation point is on the right of mid
            if(nums[mid]>=nums[s])
            {
                if(target>=nums[s] && target<=nums[mid])
                {
                    e=mid-1;
                }
                else
                {
                    s=mid+1;
                }
            }
          // If sorted point is on the left of mid
            else
            {
                if(target<=nums[e] && target>=nums[mid])
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
            }
        }
        
        return -1;
    }
