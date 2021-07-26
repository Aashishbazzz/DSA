// By Aashish Saxena
// Given a 2D array with 2 columns, each row have a given time interval having start time and end time
// we have to merge the overlapping intervals


// Problem link -> https://leetcode.com/problems/merge-intervals/submissions/    


vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int i,mins,maxs;
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end());
        
        mins= intervals[0][0];
        maxs= intervals[0][1];
        
        for(i=1;i<intervals.size();i++)
        {
          // IF interval overlaps with the previous one then store the range
            if(intervals[i][0]<=maxs && intervals[i][0]>=mins)
            {
                mins= min(mins,intervals[i][0]);
                maxs= max(maxs,intervals[i][1]);
            }
          // If the interval does not overlap then add the current start and end time
            else
            {
                ans.push_back({mins,maxs});
                mins= intervals[i][0];
                maxs= intervals[i][1];
            }
        }
        
        
        ans.push_back({mins,maxs});
        
        return ans;
    }
