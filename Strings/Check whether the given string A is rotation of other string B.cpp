// By Aashish Saxena
// Given 2 strings A and B, check whether A is rotation of B



#include <bits/stdc++.h>
using namespace std;

// Function to compute the LPS array
void lps_computation(vector<int> &lps, string s)
{
    int i,j;
    
    lps[0]=0;
    i=1;
    j=0;
    
    while(i<s.length())
    {
        if(s[i]==s[j])
        {
            j++;
            lps[i]=j;
            i++;
        }
        else
        {
            if(j>0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

// String matching KMP algorithm
bool match_string(vector<int> lps, string s1, string s2)
{
    int i,j;
    
    i=0;
    j=0;
    
    while(i<s2.length())
    {
        if(s2[i]==s1[j])
        {
            i++;
            j++;
            
            if(j==s1.length())
            {
                return true;
            }
        }
        else
        {
            if(j>0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    
    return false;
}


int main()
{
    string s1,s2;
    vector<int> lps(100);
    
	cin>>s1>>s2;
	
	lps_computation(lps,s1);
	
	s2=s2+s2;
	
	if(match_string(lps,s1,s2))
	{
	    cout<<"Yes";
	}
	else
	{
	    cout<<"No";
	}
	
	return 0;
}
