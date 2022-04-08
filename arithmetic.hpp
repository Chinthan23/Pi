#include <bits/stdc++.h>

#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

using namespace std;
typedef long long ll;

extern ll B;

// Subtraction
pair<vector<ll>, ll> sub(pair<vector<ll>, ll> X, pair<vector<ll>, ll> Y, ll B);

void decex(pair<vector<ll>, ll> &X, pair<vector<ll>, ll> &Y);

pair<vector<ll>, ll> subtractiond(pair<vector<ll>, ll> X, pair<vector<ll>, ll> Y, ll B);

// Multiplication

pair<vector<ll>, ll> mn(pair<vector<ll>, ll> X, pair<vector<ll>, ll> Y, ll B);

vector<ll> carryh(vector<ll> Z, ll B);

pair<vector<ll>, ll> mul(pair<vector<ll>, ll> X, pair<vector<ll>, ll> Y, ll B);

pair<vector<ll>, ll> multiplicationd(pair<vector<ll>, ll> X, pair<vector<ll>, ll> Y, ll B);

// Addition

pair<vector<ll>, ll> add(pair<vector<ll>, ll> a, pair<vector<ll>, ll> b, ll B);

// Division

pair<vector<ll>, ll> division(pair<vector<ll>, ll> a, pair<vector<ll>, ll> b, ll B);

pair<vector<ll>, ll> divisionr(pair<vector<ll>, ll> a, pair<vector<ll>, ll> b, ll B);

pair<vector<ll>, ll> divr(pair<vector<ll>, ll> a, pair<vector<ll>, ll> b, ll p, ll B);

pair<vector<ll>, ll> divd(pair<vector<ll>, ll> a, pair<vector<ll>, ll> b, ll p, ll B);

void truncate(vector<ll> &v);

void precision(pair<vector<ll>, ll> &a);

void truncated(pair<vector<ll>, ll> &v);

// Square Root

pair<vector<ll>, ll> sqaureroot(pair<vector<ll>, ll> A, ll p, ll B);

#endif