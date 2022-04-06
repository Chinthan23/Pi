#include "arithmetic.hpp"

int main()
{
    ll pr=10;
    pair<vector<ll>,ll> root2=sqaureroot({{2},0},pr+5);
    pair<vector<ll>,ll> a=root2;
    pair<vector<ll>,ll> b={{0},0};
    pair<vector<ll>,ll> p=add({{2},0},root2);
    pair<vector<ll>,ll> half={{0,5},1};
    ll c=0;
    bool checker=false;
    while(true)
    {
        pair<vector<ll>,ll> a_1=sqaureroot(a,pr+5);
        pair<vector<ll>,ll> a_2=divd({{1},0},a_1,pr+5);
        pair<vector<ll>,ll> a_3=add(a_1,a_2);
        pair<vector<ll>,ll> anew=multiplicationd(half,a_3);
        reverse(anew.first.begin(),anew.first.end());
        truncate(anew.first);
        reverse(anew.first.begin(),anew.first.end());
        truncated(anew);
        pair<vector<ll>,ll> b_1=add({{1},0},b);
        pair<vector<ll>,ll> b_2=multiplicationd(b_1,a_1);
        reverse(b_2.first.begin(),b_2.first.end());
        truncate(b_2.first);
        reverse(b_2.first.begin(),b_2.first.end());
        truncated(b_2);
        pair<vector<ll>,ll> b_3=add(a,b);
        pair<vector<ll>,ll> b_4=divd({{1},0},b_3,pr+5);
        pair<vector<ll>,ll> bnew=multiplicationd(b_2,b_4);
        reverse(bnew.first.begin(),bnew.first.end());
        truncate(bnew.first);
        reverse(bnew.first.begin(),bnew.first.end());
        truncated(bnew);
        pair<vector<ll>,ll> p_1=add({{1},0},anew);
        pair<vector<ll>,ll> p_2=multiplicationd(p_1,p);
        reverse(p_2.first.begin(),p_2.first.end());
        truncate(p_2.first);
        reverse(p_2.first.begin(),p_2.first.end());
        truncated(p_2);
        pair<vector<ll>,ll> p_3=multiplicationd(p_2,bnew);
        reverse(p_3.first.begin(),p_3.first.end());
        truncate(p_3.first);
        reverse(p_3.first.begin(),p_3.first.end());
        truncated(p_3);
        pair<vector<ll>,ll> p_4=add({{1},0},bnew);
        pair<vector<ll>,ll> p_5=divd({{1},0},p_4,pr+5);
        pair<vector<ll>,ll> pnew=multiplicationd(p_3,p_5);
        reverse(pnew.first.begin(),pnew.first.end());
        truncate(pnew.first);
        reverse(pnew.first.begin(),pnew.first.end());
        truncated(pnew);
        pair<vector<ll>,ll> check=subtractiond(pnew,p);
        if(check.second>pr)
        {
            bool icheck=true;
            for(ll i=check.first.size()-check.second;i<check.first.size()-check.second+pr+1;i++)
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
        a=anew;
        b=bnew;
        p=pnew;
        if(checker)
        {
            break;
        }
        c++;
    }
    if(p.second>=pr)
    {
        while(p.second!=pr)
        {
            p.first.pop_back();
            p.second--;
        }
    }
    for(auto i: p.first){
        cout<<i;
    }
}