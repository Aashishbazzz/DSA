// By Aashish Saxena
// Program to print all subsequences of a string

#include <bits/stdc++.h>
using namespace std;

void solve(string s,vector<string> &ans, string temp, int j)
{
    if(j==s.length())
    {
        ans.push_back(temp);
        return;
    }
    
    solve(s,ans,temp+s[j],j+1);
    solve(s,ans,temp,j+1);
}

int main()
{
    int i;
    vector<string> ans;
    string s="abc",temp;
    
    temp="";
    
    solve(s,ans,temp,0);
    
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
	
	return 0;
}
