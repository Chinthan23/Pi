#include <bits/stdc++.h>

#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

using namespace std;
typedef long long ll;
#define B 16


//Subtraction
pair<vector <ll>,ll> sub(pair<vector<ll>,ll> X,pair< vector <ll>,ll> Y);

pair<pair<vector<ll>,ll>,pair<vector<ll>,ll> > decex(pair<vector<ll>,ll> X,pair<vector<ll>, ll > Y);

pair<vector <ll>,ll> subtractiond(pair<vector<ll>,ll> X,pair<vector<ll>,ll> Y);


//Multiplication

pair<vector <ll>,ll> mn(pair<vector<ll>,ll> X,pair<vector<ll>,ll> Y);

vector <ll> carryh(vector <ll> Z);

pair<vector <ll>,ll> mul(pair<vector<ll>,ll> X,pair<vector<ll>,ll> Y);

pair<vector<ll>,ll> multiplicationd(pair<vector<ll>,ll> X,pair<vector<ll>,ll> Y);

//Addition

vector<int> add(vector<int> a, vector<int> b);

//Division

pair<vector<ll>, ll> division(vector<int> a, vector<int> b);

#endif