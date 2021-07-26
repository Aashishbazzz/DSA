// By Aashish Saxena
// Given an array and a no n, find if there is any pair exist with the given difference

// Problem link -> https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1


bool findPair(int arr[], int size, int n)
{
    unordered_set<int> s;
    int i,t;
    
    for(i=0;i<size;i++)
    {
        auto itr=s.find(arr[i]);
        
      // Checking if any number exist in the set which can pair up with arr[i] to make the given difference
        if(itr!=s.end())
        {
            return true;
        }
        else
        {
            {
              // Storing 2 numbers in the array which can pair up with arr[i] to make the given difference
                s.insert(abs(arr[i]+n));
                s.insert(abs(arr[i]-n));
            }
        }
    }
    
    return false;
    
}
