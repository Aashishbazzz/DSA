// By Aashish Saxena
// Program to find all permutations of a string


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,t,c,p;
    vector<string> ans;
    string s="abc";
    
    p=pow(2,s.length());
    
    ans.push_back(" ");
    
    for(i=1;i<=p;i++)
    {
        t=i;
        c=0;
        string t_ans="";
        
        while(t!=0)
        {
            if(t%2!=0)
            {
                t_ans+=s[c];
            }
            c++;
            t=t/2;
        }
        ans.push_back(t_ans);
    }
    
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
	
	return 0;
}
