#include "arithmetic.hpp"

int main()
{
    pair<vector<ll>,ll> A={{4,6,1,3,4,6,4},0};
    pair<vector<ll>,ll> p={{0,0,0,0,0,0,0,0,0,0,1},10};
    pair<vector<ll>,ll> ans=A;
    pair<vector<ll>,ll> half={{0,5},1};
    ll c=0;
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
        bool checker=false;
        c++;
    }
    cout << "1234" << "\n";
}
