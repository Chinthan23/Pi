#include "arithmetic.h"

pair<vector<ll>, ll> mn(pair<vector<ll>, ll> A, pair<vector<ll>, ll> Y)
{
    ll i, j;
    pair<vector<ll>, ll> ans;
    for (i = 0; i < A.first.size() * 2; i++)
    {
        ans.first.push_back(0);
    }
    for (j = 0; j < Y.first.size(); j++)
    {
        for (i = 0; i < A.first.size(); i++)
        {
            ans.first[j + i] += A.first[i] * Y.first[j];
        }
    }
    ans.second = A.second + Y.second;
    return ans;
}
vector<ll> carryh(vector<ll> Z)
{
    ll cr = 0, i;
    for (i = 0; i < Z.size(); i++)
    {
        Z[i] += cr;
        if (Z[i] < 0)
        {
            cr = -(-(Z[i] + 1) / B + 1);
        }
        else
        {
            cr = Z[i] / B;
        }
        Z[i] -= cr * B;
    }

    return Z;
}
pair<vector<ll>, ll> mul(pair<vector<ll>, ll> A, pair<vector<ll>, ll> Y)
{
    reverse(A.first.begin(), A.first.end());
    while (A.first.size() % 3 != 0)
    {
        A.first.push_back(0);
    }
    reverse(Y.first.begin(), Y.first.end());
    while (Y.first.size() != A.first.size())
    {
        Y.first.push_back(0);
    }
    vector<ll> a0, a1, a2, b0, b1, b2;
    for (ll i = A.first.size() / 3 - 1; i >= 0; i--)
    {
        a0.push_back(A.first[i]);
    }
    for (ll i = 2 * (A.first.size() / 3) - 1; i >= (A.first.size() / 3); i--)
    {
        a1.push_back(A.first[i]);
    }
    for (ll i = A.first.size() - 1; i >= 2 * (A.first.size() / 3); i--)
    {
        a2.push_back(A.first[i]);
    }
    for (ll i = Y.first.size() / 3 - 1; i >= 0; i--)
    {
        b0.push_back(Y.first[i]);
    }
    for (ll i = 2 * (Y.first.size() / 3) - 1; i >= (A.first.size() / 3); i--)
    {
        b1.push_back(Y.first[i]);
    }
    for (ll i = Y.first.size() - 1; i >= 2 * (Y.first.size() / 3); i--)
    {
        b2.push_back(Y.first[i]);
    }
    if (A.first.size() <= 9)
    {
        return mn(A, Y);
    }
    pair<vector<ll>, ll> a_2, b_2;
    for (ll i = 0; i < A.first.size() / 3; i++)
    {
        a_2.first.push_back((a2[i] << 2) - (a1[i] << 1) + a0[i]);
    }
    for (ll i = 0; i < Y.first.size() / 3; i++)
    {
        b_2.first.push_back((b2[i] << 2) - (b1[i] << 1) + b0[i]);
    }
    a_2.second = 0;
    b_2.second = 0;
    pair<vector<ll>, ll> a_m1, b_m1;
    for (ll i = 0; i < A.first.size() / 3; i++)
    {
        a_m1.first.push_back(a2[i] - a1[i] + a0[i]);
    }
    for (ll i = 0; i < Y.first.size() / 3; i++)
    {
        b_m1.first.push_back(b2[i] - b1[i] + b0[i]);
    }
    a_m1.second = 0;
    b_m1.second = 0;
    pair<vector<ll>, ll> a_1, b_1;
    for (ll i = 0; i < A.first.size() / 3; i++)
    {
        a_1.first.push_back(a2[i] + a1[i] + a0[i]);
    }
    for (ll i = 0; i < Y.first.size() / 3; i++)
    {
        b_1.first.push_back(b2[i] + b1[i] + b0[i]);
    }
    a_1.second = 0;
    b_1.second = 0;
    pair<vector<ll>, ll> a_inf, b_inf;
    for (ll i = 0; i < A.first.size() / 3; i++)
    {
        a_inf.first.push_back(a2[i]);
    }
    for (ll i = 0; i < Y.first.size() / 3; i++)
    {
        b_inf.first.push_back(b2[i]);
    }
    a_inf.second = 0;
    b_inf.second = 0;
    pair<vector<ll>, ll> a_0, b_0;
    for (ll i = 0; i < A.first.size() / 3; i++)
    {
        a_0.first.push_back(a0[i]);
    }
    for (ll i = 0; i < Y.first.size() / 3; i++)
    {
        b_0.first.push_back(b0[i]);
    }
    a_0.second = 0;
    b_0.second = 0;
    pair<vector<ll>, ll> c_m2 = mul(a_2, b_2);
    pair<vector<ll>, ll> c_m1 = mul(a_m1, b_m1);
    pair<vector<ll>, ll> c_0 = mul(a_0, b_0);
    pair<vector<ll>, ll> c_1 = mul(a_1, b_1);
    pair<vector<ll>, ll> c_inf = mul(a_inf, b_inf);
    vector<ll> c1((A.first.size() / 3) * 2), c2((A.first.size() / 3) * 2), c3((A.first.size() / 3) * 2), c4((A.first.size() / 3) * 2), c0((A.first.size() / 3) * 2);
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        c4[i] = c_inf.first[i];
    }
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        c3[i] = -c_m2.first[i];
        c3[i] += (c_m1.first[i] << 1) + c_m1.first[i];
        c3[i] -= (c_0.first[i] << 1) + c_0.first[i];
        c3[i] += c_1.first[i];
        c3[i] += (c_inf.first[i] << 3) + (c_inf.first[i] << 2);
        c3[i] /= 6;
    }
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        c2[i] = (c_m1.first[i] << 1) + c_m1.first[i];
        c2[i] -= (c_0.first[i] << 2) + (c_0.first[i] << 1);
        c2[i] += (c_1.first[i] << 1) + c_1.first[i];
        c2[i] -= (c_inf.first[i] << 2) + (c_inf.first[i] << 1);
        c2[i] /= 6;
    }
    c2.push_back(0);
    vector<ll> c2c = carryh(c2);
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        c1[i] = c_m2.first[i];
        c1[i] -= (c_m1.first[i] << 2) + (c_m1.first[i] << 1);
        c1[i] += (c_0.first[i] << 1) + c_0.first[i];
        c1[i] += (c_1.first[i] << 1);
        c1[i] -= (c_inf.first[i] << 3) + (c_inf.first[i] << 2);
        c1[i] /= 6;
    }
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        c0[i] = c_0.first[i];
    }
    pair<vector<ll>, ll> ans((A.first.size() / 3) * 6, 0);
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        ans.first[i + ((A.first.size() / 3) * 4)] += c4[i];
    }
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        ans.first[i + A.first.size()] += c3[i];
    }
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        ans.first[i + ((A.first.size() / 3) * 2)] += c2[i];
    }
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        ans.first[i + ((A.first.size() / 3) * 1)] += c1[i];
    }
    for (ll i = 0; i < ((A.first.size() / 3) * 2); i++)
    {
        ans.first[i] += c0[i];
    }
    ans.second = A.second + Y.second;
    return ans;
}
pair<vector<ll>, ll> multiplicationd(pair<vector<ll>, ll> A, pair<vector<ll>, ll> Y, ll b)
{
    pair<vector<ll>, ll> ans = mul(A, Y);
    ans.first = carryh(ans.first);
    return ans;
}
