#include "arithmetic.hpp"

pair <vector<ll>,ll> sqaureroot(pair<vector<ll>,ll> A,ll p)
{
    pair<vector<ll>,ll> ans=A;
    pair<vector<ll>,ll> half={{0,5},1};
    ll c=0;
    bool checker=false;
    while(true)
    {
        pair<vector<ll>,ll> dan=divd(A,ans,c+1);
        pair<vector<ll>,ll> aan=add(ans,dan);
        pair<vector<ll>,ll> ansd=multiplicationd(half,aan);
        reverse(ansd.first.begin(),ansd.first.end());
        truncate(ansd.first);
        reverse(ansd.first.begin(),ansd.first.end());
        truncated(ansd);
        pair<vector<ll>,ll> check=subtractiond(ansd,ans);
        if(check.second>p)
        {
            bool icheck=true;
            for(ll i=check.first.size()-check.second;i<check.first.size()-check.second+p;i++)
            {
                if(check.first[i]!=0)
                {
                    icheck=false;
                    break;
                }
            }
            if(icheck)
            {
                checker=true;
            }
        }
        ans=ansd;
        if(checker)
        {
            break;
        }
        c++;
    }
    if(ans.second>=p)
    {
        while(ans.second!=p)
        {
            ans.first.pop_back();
            ans.second--;
        }
    }
    return ans;
}
