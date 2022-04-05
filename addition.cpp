#include <bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> a, vector<int> b, int B){
	int k=0,l=0;
	// l is the size of the greatest number
	if(a.size()>b.size()){
		l=a.size();
		k=b.size();
	}
	else if(a.size()==b.size()){
		l=a.size(),k=a.size();
	}
	else{
		k=a.size(),l=b.size();
	}
	int carry=0;
	vector<int> c(l+1, 0);
	for(int i=0;i<k;i++){
		c[i]=(a[i]+b[i]+carry)%B;
		carry=(a[i]+b[i]+carry)/B;
	}
	if(l==a.size()){
		for(int i=k;i<l;i++){
			c[i]=(a[i]+carry)%B;
			carry=(a[i]+carry)/B;
		}
	}
	else{
		for(int i=k;i<l;i++){
			c[i]=(b[i]+carry)%B;
			carry=(b[i]+carry)/B;
		}
	}
	if(carry>0) c[l]=carry;

	return c;
}

int main()
{
	pair<vector<int> a={9,9,9,9,9,9,9,9};
	vector<int> b={9,9,9,9,9,9,9,9};

	vector<int>  c=add(a,b,10);


}