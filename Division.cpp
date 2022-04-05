#include <bits/stdc++.h>
#define B 16
using namespace std;

void division(vector<int> a, vector<int> b){
	int l=b.size();
	int k=a.size();
	vector<int> q(k-l+1,0);
	vector<int> r(k+1);
	for(int i=0;i<k;i++){
		r[i]=a[i];
	}
	r[k]=0;

	for(int i=(k-l);i>=0;i--){

		q[i]=(r[i+l]*B + r[i+l-1])/b[l-1];

		if(q[i]>=B){
			q[i]=B-1;
		}

		int carry=0;
		for(int j=0;j<=l-1;j++){
			int temp=r[i+j]-(q[i]*b[j])+carry;
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
				int temp=r[i+j]+b[j]+carry;
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
	for(auto it=q.rbegin();it!=q.rend();it++){
		cout<<*it<<" ";
	}
	cout<<"\n";
	for(auto it=r.rbegin();it!=r.rend();it++){
		cout<<*it<<" ";
	}
	cout<<"\n";

}

int main(){
	vector<int> a={12,13,1,10,8,9}; //10002908
	vector<int> b={15,7,3,2};	//9087
	division(a,b);
}
