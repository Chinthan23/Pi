#include "arithmetic.hpp"

int main()
{
    ll pr=1000;
    pair<vector<ll>,ll> root2,a,b,p,two;
    pair<vector<ll>,ll> half={{B/2},1};
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
    ll pri=pr+5;
    while(true)
    {
        a_1=sqaureroot(a,pri);
        a_2=divd({{1},0},a_1,pri);
        a_3=add(a_1,a_2);
        anew=multiplicationd(a_3,half);
        b_1=add({{1},0},b);
        b_2=multiplicationd(b_1,a_1);
        b_3=add(a,b);
        b_4=divd({{1},0},b_3,pri);
        bnew=multiplicationd(b_2,b_4);
        p_1=add({{1},0},anew);
        p_2=multiplicationd(p_1,p);
        p_3=multiplicationd(p_2,bnew);
        p_4=add({{1},0},bnew);
        p_5=divd({{1},0},p_4,pri);
        pnew=multiplicationd(p_3,p_5);
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