#include "arithmetic.hpp"

int main()
{
    ll pr=2000;
    pair<vector<ll>,ll> root2,a,b,p,two;
    pair<vector<ll>,ll> half={{0,B/2},1};
    two={{2},0};
    root2=sqaureroot(two,pr+5);
    a=root2;
    b={{0},0};
    p=add({{2},0},root2);
    pair<vector<ll>,ll> a_1,a_2,a_3,anew;
    pair<vector<ll>,ll> b_1,b_2,b_3,b_4,bnew;
    pair<vector<ll>,ll> p_1,p_2,p_3,p_4,p_5,pnew,check;
    ll c=0;
    bool checker=false;
    ll pri=4;
    while(true)
    {
        a_1=sqaureroot(a,pri);
        a_2=divd({{1},0},a_1,pri);
        a_3=add(a_1,a_2);
        anew=multiplicationd(a_3,half);
        reverse(anew.first.begin(),anew.first.end());
        truncate(anew.first);
        reverse(anew.first.begin(),anew.first.end());
        truncated(anew);
        b_1=add({{1},0},b);
        b_2=multiplicationd(b_1,a_1);
        reverse(b_2.first.begin(),b_2.first.end());
        truncate(b_2.first);
        reverse(b_2.first.begin(),b_2.first.end());
        truncated(b_2);
        b_3=add(a,b);
        b_4=divd({{1},0},b_3,pri);
        bnew=multiplicationd(b_2,b_4);
        reverse(bnew.first.begin(),bnew.first.end());
        truncate(bnew.first);
        reverse(bnew.first.begin(),bnew.first.end());
        truncated(bnew);
        p_1=add({{1},0},anew);
        p_2=multiplicationd(p_1,p);
        reverse(p_2.first.begin(),p_2.first.end());
        truncate(p_2.first);
        reverse(p_2.first.begin(),p_2.first.end());
        truncated(p_2);
        p_3=multiplicationd(p_2,bnew);
        reverse(p_3.first.begin(),p_3.first.end());
        truncate(p_3.first);
        reverse(p_3.first.begin(),p_3.first.end());
        truncated(p_3);
        p_4=add({{1},0},bnew);
        p_5=divd({{1},0},p_4,pri);
        pnew=multiplicationd(p_3,p_5);
        reverse(pnew.first.begin(),pnew.first.end());
        truncate(pnew.first);
        reverse(pnew.first.begin(),pnew.first.end());
        truncated(pnew);
        check=subtractiond(pnew,p);
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
        pri=2*pri;
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
        cout<<i ;
    }
    
}