#include "arithmetic.hpp"

int main()
{
    pair<vector<ll>,ll> A={{1,6},0};
    ll p=2;
    pair<vector<ll>,ll> ans={{1},0};
    pair<vector<ll>,ll> half={{0,5},1};
    ll c=0;
    while(c!=p)
    {
        pair<vector<ll>,ll> dan=division(A,ans);
        pair<vector<ll>,ll> aan=add(ans,dan);
        ans=multiplicationd(half,aan);
        c++;
    }
    cout << "1234" << "\n";
}
