#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout << 'Y' << 'E' << 'S' << nl
#define no cout << 'N' << 'O' << nl
#define nl endl
#define tr ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define tst   \
    int t;    \
    cin >> t; \
    while (t--)
#define Max 1000000000000000014
#define Min -1000000000000000014
#define PI 3.1415926535897
#define all(v) v.begin(), v.end()
#define mem(a, v) memset(a, v, sizeof(a))
#define COUT(v)              \
    for (auto it : v)        \
        cout << it << space; \
    cout << nl;
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define eb emplace_back
#define error cout << -1 << nl
#define oneInbin(x) __builtin_popcount(x)                                                                                                      // return number of one in binary representation ,replace popcount with popcountll for long long
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end))) // this will iterate through the loop ex rep(i,1,10) from 1 to 9 and rep(i,10,1) will run from 9 to 1 also i will be variable that run the loop we can change it to any
#define lambda sort(begin(v), end(v), [](int a, int b) { return a > b; });                                                                     // an example of lambda function for sorting
// int x=min({a,b,c,d});instead of x=min(min(min(a,b),c),d);

int main()
{
    tr;
    tst
    {
        int n;
        cin >> n;
        vi vIn, vVal;
        int i, x;
        map<int, vi> m;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            if (i == 0)
                vIn.emplace_back(-1);
            else
            {
                if (x == vVal.back())
                    vIn.emplace_back(vIn.back());
                else
                {
                    vIn.push_back(i + 1);
                }
            }
            vVal.emplace_back(x);
        }
        // for(auto it:vIn)
        //     cout << it << ' ';
        // cout << '\n';
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            if (vIn[l - 1] == vIn[r - 1])
                cout << "-1 -1\n";
            else if (vVal[l - 1] == vVal[r - 1])
            {
                {
                    // for (i = l-1; i < r;i++){
                    //     if(vVal[i]!=vVal[l-1]){
                    //         cout<<l<<' ' << i + 1 << endl;break;
                    //     }
                    // }
                    int lo = l - 1, hi = r - 1;
                    while(lo<hi){
                        if(vVal[lo]==vVal[hi])
                            lo++;
                        if(vVal[lo]==vVal[hi])
                            hi--;
                        else break;
                    }
                    cout << lo + 1 << ' ' << hi + 1 << endl;
                }
            }
            else
                cout << l << ' ' << r << '\n';
        }
    }
}