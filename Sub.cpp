#include "arithmetic.hpp"

pair<vector <ll>,ll> sub(pair<vector<ll>,ll> A,pair<vector<ll>,ll> Y)
{
    reverse(A.first.begin(),A.first.end());
    reverse(Y.first.begin(),Y.first.end());
    vector <ll> grt=A.first;
    vector <ll> les=Y.first;
    if(A.first.size()!=Y.first.size())
    {
        if(A.first.size()<Y.first.size())
        {
            grt=Y.first;
            les=A.first;
        }
    }
    else
    {
        for(ll i=A.first.size()-1;i>=0;i--)
        {
            if(Y.first[i]>A.first[i])
            {
                grt=Y.first;
                les=A.first;
                break;
            }
            else
            {
                break;
            }
        }
    }
    ll grte=grt.size();
    ll lese=les.size();
    pair<vector <ll>,ll> ans;
    ll carry=0;
    
    for(ll i=0;i<lese;i++)
    {    
        int temp=(grt[i]-les[i]-carry);
        if(temp<0)
        {
            temp=temp+B;
            carry=1;
        }
        else
        {
            carry=0;
        }
        ans.first.push_back(temp);
    }
    for(ll i=lese;i<grte;i++)
    {
        int temp=grt[i]-carry;
        if(temp<0)
        {
            temp=temp+B;
            carry=1;
        }
        else
        {
            carry=0;
        }
        ans.first.push_back(temp);
    }
    ans.second=max(A.second,Y.second);
    return(ans);
}
pair<pair<vector<ll>,ll>,pair<vector<ll>,ll>> decex(pair<vector<ll>,ll> A,pair<vector<ll>,ll> Y)
{
    ll final=max(A.second,Y.second);
    while(A.second!=final)
    {
        A.first.push_back(0);
        A.second++;
    }
    while(Y.second!=final)
    {
        Y.first.push_back(0);
        Y.second++;
    }
    return {A,Y};
}
pair<vector <ll>,ll> subtractiond(pair<vector<ll>,ll> A,pair<vector<ll>,ll> Y)
{
    pair<pair<vector<ll>,ll>,pair<vector<ll>,ll>> An=decex(A,Y);
    A=An.first;
    Y=An.second;
    pair<vector <ll>,ll>ans=sub(A,Y);
    reverse(ans.first.begin(),ans.first.end());
    return ans;
}