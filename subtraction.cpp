#include <bits/stdc++.h>

using namespace std;

vector<int> subtract(vector<int> a, vector<int> b, int B){
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
		c[i]=(a[i]-b[i]-carry)%B;
		c[i]+=carry;
		carry=c[i]<0?-1:0;
		c[i]=abs(c[i]);
	}
	if(l==a.size()){
		for(int i=k;i<l;i++){
			c[i]=(a[i]-carry)%B;
			c[i]+=carry;
			carry=c[i]<0?-1:0;
			c[i]=abs(c[i]);
		}
	}
	else{
		for(int i=k;i<l;i++){
			c[i]=(b[i]-carry)%B;
			c[i]+=carry;
			carry=c[i]<0?-1:0;
			c[i]=abs(c[i]);
		}
	}

	return c;

}

int main(){
	vector<int> a={9,9,7,9,8};
	vector<int> b={9,9,8,9,9};

	vector<int>  c=subtract(a,b,10);

	for(auto it= c.rbegin(); it!=c.rend(); it++){
		cout<<*it;
	}
}