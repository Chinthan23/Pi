#include "Sub.h"
pair<vector <long long int>,long long int> sub(pair<vector<long long int>,long long int> A,pair<vector<long long int>,long long int> B,long long int b)
{
    reverse(A.first.begin(),A.first.end());
    reverse(B.first.begin(),B.first.end());
    vector <long long int> grt=A.first;
    vector <long long int> les=B.first;
    if(A.first.size()!=B.first.size())
    {
        if(A.first.size()<B.first.size())
        {
            grt=B.first;
            les=A.first;
        }
    }
    else
    {
        for(long long int i=A.first.size()-1;i>=0;i--)
        {
            if(B.first[i]>A.first[i])
            {
                grt=B.first;
                les=A.first;
                break;
            }
            else
            {
                break;
            }
        }
    }
    long long int grte=grt.size();
    long long int lese=les.size();
    pair<vector <long long int>,long long int> ans;
    long long int carry=0;
    
    for(long long int i=0;i<lese;i++)
    {    
        int temp=(grt[i]-les[i]-carry);
        if(temp<0)
        {
            temp=temp+b;
            carry=1;
        }
        else
        {
            carry=0;
        }
        ans.first.push_back(temp);
    }
    for(long long int i=lese;i<grte;i++)
    {
        int temp=grt[i]-carry;
        if(temp<0)
        {
            temp=temp+b;
            carry=1;
        }
        else
        {
            carry=0;
        }
        ans.first.push_back(temp);
    }
    ans.second=max(A.second,B.second);
    return(ans);
}
pair<pair<vector<long long int>,long long int>,pair<vector<long long int>,long long int>> decex(pair<vector<long long int>,long long int> A,pair<vector<long long int>,long long int> B)
{
    long long int final=max(A.second,B.second);
    while(A.second!=final)
    {
        A.first.push_back(0);
        A.second++;
    }
    while(B.second!=final)
    {
        B.first.push_back(0);
        B.second++;
    }
    return {A,B};
}
pair<vector <long long int>,long long int> subtractiond(pair<vector<long long int>,long long int> A,pair<vector<long long int>,long long int> B,long long int b)
{
    pair<pair<vector<long long int>,long long int>,pair<vector<long long int>,long long int>> An=decex(A,B);
    A=An.first;
    B=An.second;
    pair<vector <long long int>,long long int>ans=sub(A,B,b);
    return ans;
}