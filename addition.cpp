#include "arithmetic.hpp"

pair<vector<ll>,ll> add(pair<vector<ll>,ll> a, pair<vector<ll>,ll> b){
	
	pair<pair<vector<ll>,ll>,pair<vector<ll>,ll>> An=decex(a,b);
	a=An.first;
	b=An.second;
	reverse(a.first.begin(),a.first.end());
	reverse(b.first.begin(),b.first.end());
	ll k=0,l=0;
	// l is the size of the greatest number
	if(a.first.size()>b.first.size()){
		l=a.first.size();
		k=b.first.size();
	}
	else if(a.first.size()==b.first.size()){
		l=a.first.size(),k=a.first.size();
	}
	else{
		k=a.first.size(),l=b.first.size();
	}
	ll carry=0;
	pair<vector<ll>,ll> c{vector<ll>(l+1, 0),0};
	for(ll i=0;i<k;i++){
		c.first[i]=(a.first[i]+b.first[i]+carry)%B;
		carry=(a.first[i]+b.first[i]+carry)/B;
	}
	if(l==a.first.size()){
		for(ll i=k;i<l;i++){
			c.first[i]=(a.first[i]+carry)%B;
			carry=(a.first[i]+carry)/B;
		}
	}
	else{
		for(ll i=k;i<l;i++){
			c.first[i]=(b.first[i]+carry)%B;
			carry=(b.first[i]+carry)/B;
		}
	}
	c.second=max(a.second,b.second);
	if(carry>0) c.first[l]=carry;
	truncate(c.first);
	reverse(c.first.begin(),c.first.end());
	return c;
}