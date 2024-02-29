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
const int N = 2e4 + 7;
bool chk[N+5];
vector<int> prime;
void sieve(){
    int i, j;
    for (i = 2; i * i <= N;i++){
        if(chk[i]==false){
        for (j = i * i; j <= N;j+=i){
            chk[j] = true;
        }
        }
    }
    for (i = 2; i <= N;i++){
        if(!chk[i])
            prime.push_back(i);
    }
}
int main()
{
    sieve();
    // cout << prime.size() << '\n';
    tr;
    tst
    {
        int n;
        cin >> n;
        map<int, int> m,mm;
        vector<int> v;
        int i, x;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            if(x>1)
            v.emplace_back(x);
            m[x]++;
        }
        if (m[1] > 1)
            no;
        else
        {
            for(auto &it:v){
                for(auto &iit:prime){
                    if(it%iit==0){
                        while(it%iit==0){
                            mm[iit]++;
                            it /= iit;
                        }
                        if(it<iit){
                            m[it]++;
                            break;
                        }
                    }
                }
            }
            bool ok = false;
            for(auto it:mm){
                if(it.second%2==1){
                    ok = true;break;
                }
            }
            if(ok)
                yes;
            else
                no;
        }
    }
}