#include "arithmetic.hpp"

void truncate(vector<ll> &v)
{
    int i=v.size()-1;
    while(i != 0 && v[i] == 0)
    {
        v.pop_back();
        i--;
    }
}

pair<vector<ll> , ll> division(pair<vector<ll>, ll> a, pair<vector<ll>,ll> b){
	reverse(a.first.begin(), a.first.end());
	reverse(b.first.begin(), b.first.end());
	int l=b.first.size();
	int k=a.first.size();
	vector<ll> q(k-l+1,0);
	vector<ll> r(k+1);
	cout<<"here\n";
	for(int i=0;i<k;i++){
		r[i]=a.first[i];
	}
	r[k]=0;
	cout<<"here\n";

	for(int i=(k-l);i>=0;i--){

		q[i]=(r[i+l]*B + r[i+l-1])/b.first[l-1];

		if(q[i]>=B){
			q[i]=B-1;
		}

		int carry=0;
		for(int j=0;j<=l-1;j++){
			int temp=r[i+j]-(q[i]*b.first[j])+carry;
			carry=temp/B;
			r[i+j]=temp%B;
			if(r[i+j]<0){
				carry-=1;
				r[i+j]+=B;
			}
		}

		r[i+l]+=carry;

		while(r[i+l]<0){
			carry=0;
			int j;
			for(j=0;j<=l-1;j++){
				int temp=r[i+j]+b.first[j]+carry;
				carry=temp/B;
				r[i+j]=temp%B;
				if(r[i+j]<0){
					r[i+j]+=B;
					carry-=1;
				}
			}
			r[i+l]+=carry;	
			q[i]-=1;
		}
	}
	truncate(q);
	// for(auto it=q.rbegin();it!=q.rend();it++){
	// 	cout<<*it<<" ";
	// }
	// cout<<"\n";
	// for(auto it=r.rbegin();it!=r.rend();it++){
	// 	cout<<*it<<" ";
	// }
	// cout<<"\n";
	reverse(q.begin(),q.end());
	return {q,0};
}

