// IMT2020109-Chinthan Chandra IMT2020119-Darshak Jivrajani
#include "arithmetic.hpp"

int main()
{
    ll minp, cinp, pinp;
    cin >> cinp >> pinp >> minp;
    ll pr = pinp;
    ll B = 1 << minp;
    pair<vector<ll>, ll> root2, a, b, p, two;
    pair<vector<ll>, ll> half = {{B / 2}, 1};
    two = {{2}, 0};
    ll pri = pr + 5;
    root2 = sqaureroot(two, pr + 5, B);
    if (cinp == 1)
    {
        a = root2;
        b = {{0}, 0};
        p = add({{2}, 0}, root2, B);
        pair<vector<ll>, ll> a_1, a_2, a_3, anew;
        pair<vector<ll>, ll> b_1, b_2, b_3, b_4, bnew;
        pair<vector<ll>, ll> p_1, p_2, p_3, p_4, p_5, pnew, check;
        ll c = 0;
        bool checker = false;
        while (true)
        {
            a_1 = sqaureroot(a, pri, B);
            a_2 = divd({{1}, 0}, a_1, pri, B);
            a_3 = add(a_1, a_2, B);
            anew = multiplicationd(a_3, half, B);
            b_1 = add({{1}, 0}, b, B);
            b_2 = multiplicationd(b_1, a_1, B);
            b_3 = add(a, b, B);
            b_4 = divd({{1}, 0}, b_3, pri, B);
            bnew = multiplicationd(b_2, b_4, B);
            p_1 = add({{1}, 0}, anew, B);
            p_2 = multiplicationd(p_1, p, B);
            p_3 = multiplicationd(p_2, bnew, B);
            p_4 = add({{1}, 0}, bnew, B);
            p_5 = divd({{1}, 0}, p_4, pri, B);
            pnew = multiplicationd(p_3, p_5, B);
            check = subtractiond(pnew, p, B);
            if (check.second > pr)
            {
                bool icheck = true;
                for (ll i = check.first.size() - check.second; i < check.first.size() - check.second + pr + 1; i++)
                {
                    if (check.first[i] != 0)
                    {
                        icheck = false;
                        break;
                    }
                }
                if (icheck)
                {
                    checker = true;
                }
            }
            a = anew;
            b = bnew;
            p = pnew;
            if (checker)
            {
                break;
            }
            c++;
        }
        if (p.second >= (2 * pr))
        {
            while (p.second != (2 * pr))
            {
                p.first.pop_back();
                p.second--;
            }
        }
        ll cpy = B;
        pair<vector<ll>, ll> ans({p.first[p.first.size() - (p.second + 1)]}, 0);
        pair<vector<ll>, ll> powB{{B}, 0}, pb{{B}, 0}, o{{1}, 0}, ob{{1}, 0}, ptb{{1}, 0};
        B = 10;
        powB.first.pop_back();
        pb.first.pop_back();
        while (cpy > 0)
        {
            ll t3 = cpy % 10;
            powB.first.push_back(t3);
            pb.first.push_back(t3);
            cpy = cpy / 10;
        }
        reverse(powB.first.begin(), powB.first.end());
        reverse(pb.first.begin(), pb.first.end());
        for (ll i = p.first.size() - (p.second + 2); i >= 0; i--)
        {
            pair<vector<ll>, ll> temp1{{p.first[i]}, 0};
            ptb = multiplicationd(temp1, powB, B);
            ans = add(ans, ptb, B);
            powB = multiplicationd(powB, pb, B);
        }
        for (ll i = p.first.size() - (p.second); i < p.first.size(); i++)
        {
            pair<vector<ll>, ll> temp2{{p.first[i]}, 0};
            o = divr(o, pb, pri, B);
            ob = multiplicationd(temp2, o, B);
            ans = add(ans, ob, B);
        }
        if (ans.second >= pr)
        {
            while (ans.second != pr)
            {
                ans.first.pop_back();
                ans.second--;
            }
        }
        bool point = false;
        for (auto i : ans.first)
        {
            cout << i;
            if (!point)
            {
                cout << ".";
                point = true;
            }
        }
    }
    if (cinp == 2)
    {
        if (root2.second >= (2 * pr))
        {
            while (root2.second != (2 * pr))
            {
                root2.first.pop_back();
                root2.second--;
            }
        }
        ll cpy = B;
        pair<vector<ll>, ll> ans({root2.first[root2.first.size() - (root2.second + 1)]}, 0);
        pair<vector<ll>, ll> powB{{B}, 0}, pb{{B}, 0}, o{{1}, 0}, ob{{1}, 0}, ptb{{1}, 0};
        B = 10;
        powB.first.pop_back();
        pb.first.pop_back();
        while (cpy > 0)
        {
            ll t3 = cpy % 10;
            powB.first.push_back(t3);
            pb.first.push_back(t3);
            cpy = cpy / 10;
        }
        reverse(powB.first.begin(), powB.first.end());
        reverse(pb.first.begin(), pb.first.end());
        for (ll i = root2.first.size() - (root2.second + 2); i >= 0; i--)
        {
            pair<vector<ll>, ll> temp1{{root2.first[i]}, 0};
            ptb = multiplicationd(temp1, powB, B);
            ans = add(ans, ptb, B);
            powB = multiplicationd(powB, pb, B);
        }
        for (ll i = root2.first.size() - (root2.second); i < root2.first.size(); i++)
        {
            pair<vector<ll>, ll> temp2{{root2.first[i]}, 0};
            o = divr(o, pb, pri, B);
            ob = multiplicationd(temp2, o, B);
            ans = add(ans, ob, B);
        }
        if (ans.second >= pr)
        {
            while (ans.second != pr)
            {
                ans.first.pop_back();
                ans.second--;
            }
        }
        bool point = false;
        for (auto i : ans.first)
        {
            cout << i;
            if (!point)
            {
                cout << ".";
                point = true;
            }
        }
    }
    cout<<"\n";
}