#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define yes cout<<'Y'<<'E'<<'S'<<nl
#define no  cout<<'N'<<'O'<<nl
#define nl  endl
#define tr ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define tst int t;cin>>t;while(t--)
#define     Max             1000000000000000014
#define     Min             -1000000000000000014
#define     PI              3.1415926535897
#define     all(v)          v.begin(),v.end()
#define     mem(a,v)        memset(a,v,sizeof(a))
#define COUT(v) for(auto it:v)cout<<it<<space;cout<<nl;
#define vi    vector<int>
#define    vl    vector<ll>
#define    pii    pair<int,int>
#define    pll    pair<ll,ll>
#define    eb    emplace_back
#define    error    cout<<-1<<nl
#define    oneInbin(x)    __builtin_popcount(x) //return number of one in binary representation ,replace popcount with popcountll for long long 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))//this will iterate through the loop ex rep(i,1,10) from 1 to 9 and rep(i,10,1) will run from 9 to 1 also i will be variable that run the loop we can change it to any
#define lambda sort(begin(v), end(v), [] (int a, int b) { return a > b; });//an example of lambda function for sorting
//int x=min({a,b,c,d});instead of x=min(min(min(a,b),c),d); 
int main()
{
    tr;
    tst{
        int a, b, l;
        cin >> a >> b >> l;
        int x = 1, y = 1;
        int ans = 0, tem = 0,tt=l;
        ;
        while(tt%a==0){
            tt /= a;
            tem++;
        }
        ans += tem;
        for (int i = 1; i <= tem;i++){
             tt = 1;
             x *= a;
             int ttt = l / x;
             while(ttt%b==0){
                 ttt /= b;
                 tt++;
             }
             ans += tt;
        }
        if(ans==0)
            ans++;
        cout << ans << endl;
    }
}