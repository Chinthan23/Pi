#include "mul.h"
pair<vector <long long int>,long long int> mn(pair<vector<long long int>,long long int> A,pair<vector<long long int>,long long int> B,long long int b)
{
    long long int i,j;
    pair<vector <long long int>,long long int> ans;
    for(i=0;i<A.first.size()*2;i++)
    {
        ans.first.push_back(0);
    }
    for(j=0;j<B.first.size();j++)
    {
        for(i=0;i<A.first.size();i++)
        {
            ans.first[j+i]+=A.first[i]*B.first[j];
        }
    }
    ans.second=A.second+B.second;
    return ans;
}
vector <long long int> carryh(vector <long long int> Z,long long int b)
{
    long long int cr=0,i;
    for(i=0;i<Z.size();i++)
    {
        Z[i]+=cr;
        if(Z[i]<0)
        {
            cr=-(-(Z[i]+1)/b+1);
        }
        else
        {
            cr=Z[i]/b;
        }
        Z[i]-=cr*b;
    }
    
    return Z;
}
pair<vector <long long int>,long long int> mul(pair<vector<long long int>,long long int> A,pair<vector<long long int>,long long int> B,long long int b)
{
    reverse(A.first.begin(),A.first.end());
    while(A.first.size()%3!=0)
    {
        A.first.push_back(0);
    }
    reverse(B.first.begin(),B.first.end());
    while(B.first.size()!=A.first.size())
    {
        B.first.push_back(0);
    }
    vector<long long int > a0,a1,a2,b0,b1,b2;
    for(long long int i=A.first.size()/3-1;i>=0;i--)
    {
        a0.push_back(A.first[i]);
    }
    for(long long int i=2*(A.first.size()/3)-1;i>=(A.first.size()/3);i--)
    {
        a1.push_back(A.first[i]);
    }
    for(long long int i=A.first.size()-1;i>=2*(A.first.size()/3);i--)
    {
        a2.push_back(A.first[i]);
    }
    for(long long int i=B.first.size()/3-1;i>=0;i--)
    {
        b0.push_back(B.first[i]);
    }
    for(long long int i=2*(B.first.size()/3)-1;i>=(A.first.size()/3);i--)
    {
        b1.push_back(B.first[i]);
    }
    for(long long int i=B.first.size()-1;i>=2*(B.first.size()/3);i--)
    {
        b2.push_back(B.first[i]);
    }
    if(A.first.size()<=9)
    {
        return mn(A,B,b);
    }
    pair<vector <long long int>,long long int> a_2,b_2;
    for(long long int i=0;i<A.first.size()/3;i++)
    {
        a_2.first.push_back((a2[i]<<2)-(a1[i]<<1)+a0[i]);
    }
    for(long long int i=0;i<B.first.size()/3;i++)
    {
        b_2.first.push_back((b2[i]<<2)-(b1[i]<<1)+b0[i]);
    }
    a_2.second=0;
    b_2.second=0;
    pair<vector <long long int>,long long int> a_m1,b_m1;
    for(long long int i=0;i<A.first.size()/3;i++)
    {
        a_m1.first.push_back(a2[i]-a1[i]+a0[i]);
    }
    for(long long int i=0;i<B.first.size()/3;i++)
    {
        b_m1.first.push_back(b2[i]-b1[i]+b0[i]);
    }
    a_m1.second=0;
    b_m1.second=0;
    pair<vector <long long int>,long long int> a_1,b_1;
    for(long long int i=0;i<A.first.size()/3;i++)
    {
        a_1.first.push_back(a2[i]+a1[i]+a0[i]);
    }
    for(long long int i=0;i<B.first.size()/3;i++)
    {
        b_1.first.push_back(b2[i]+b1[i]+b0[i]);
    }
    a_1.second=0;
    b_1.second=0;
    pair<vector <long long int>,long long int> a_inf,b_inf;
    for(long long int i=0;i<A.first.size()/3;i++)
    {
        a_inf.first.push_back(a2[i]);
    }
    for(long long int i=0;i<B.first.size()/3;i++)
    {
        b_inf.first.push_back(b2[i]);
    }
    a_inf.second=0;
    b_inf.second=0;
    pair<vector <long long int>,long long int> a_0,b_0;
    for(long long int i=0;i<A.first.size()/3;i++)
    {
        a_0.first.push_back(a0[i]);
    }
    for(long long int i=0;i<B.first.size()/3;i++)
    {
        b_0.first.push_back(b0[i]);
    }
    a_0.second=0;
    b_0.second=0;
    pair<vector<long long int>,long long int> c_m2=mul(a_2,b_2,b);
    pair<vector<long long int>,long long int> c_m1=mul(a_m1,b_m1,b);
    pair<vector<long long int>,long long int> c_0=mul(a_0,b_0,b);
    pair<vector<long long int>,long long int> c_1=mul(a_1,b_1,b);
    pair<vector<long long int>,long long int> c_inf=mul(a_inf,b_inf,b);
    vector <long long int> c1((A.first.size()/3)*2),c2((A.first.size()/3)*2),c3((A.first.size()/3)*2),c4((A.first.size()/3)*2),c0((A.first.size()/3)*2);
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        c4[i]=c_inf.first[i];
    }
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        c3[i]=-c_m2.first[i];
        c3[i]+=(c_m1.first[i] <<1)+ c_m1.first[i];
        c3[i]-=(c_0.first[i]<<1)+c_0.first[i];
        c3[i]+=c_1.first[i];
        c3[i]+=(c_inf.first[i]<<3)+(c_inf.first[i]<<2);
        c3[i]/=6;
    }
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        c2[i]=(c_m1.first[i] <<1)+ c_m1.first[i];
        c2[i]-=(c_0.first[i]<<2)+(c_0.first[i]<<1);
        c2[i]+=(c_1.first[i]<<1)+c_1.first[i];
        c2[i]-=(c_inf.first[i]<<2)+(c_inf.first[i]<<1);
        c2[i]/=6;
    }
    c2.push_back(0);
    vector<long long int> c2c=carryh(c2,b);
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        c1[i]=c_m2.first[i];
        c1[i]-=(c_m1.first[i] <<2)+ (c_m1.first[i]<<1);
        c1[i]+=(c_0.first[i]<<1)+c_0.first[i];
        c1[i]+=(c_1.first[i]<<1);
        c1[i]-=(c_inf.first[i]<<3)+(c_inf.first[i]<<2);
        c1[i]/=6;
    }
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        c0[i]=c_0.first[i];
    }
    pair<vector <long long int>,long long int> ans((A.first.size()/3)*6,0);
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        ans.first[i+((A.first.size()/3)*4)]+=c4[i];
    }
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        ans.first[i+A.first.size()]+=c3[i];
    }
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        ans.first[i+((A.first.size()/3)*2)]+=c2[i];
    }
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        ans.first[i+((A.first.size()/3)*1)]+=c1[i];
    }
    for(long long int i=0;i<((A.first.size()/3)*2);i++)
    {
        ans.first[i]+=c0[i];
    }
    ans.second=A.second+B.second;
    return ans;
}
pair<vector<long long int>,long long int> multiplicationd(pair<vector<long long int>,long long int> A,pair<vector<long long int>,long long int> B,long long int b)
{
    pair<vector <long long int>,long long int>ans=mul(A,B,b);
    ans.first=carryh(ans.first,b);
    return ans;
}

