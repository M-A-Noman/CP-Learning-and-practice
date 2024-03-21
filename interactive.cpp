#include<bits/stdc++.h>
using namespace std;
int main(){
    int lo = 1, hi = 1000000,ans=0;
    while(lo<=hi){
        int mid = (lo + hi+1) / 2;
        cout << mid <<endl;
        fflush(stdout);
        string s;
        cin >> s;
        if(s.size()==1){
            hi = mid - 1;
        }else{
            ans = mid;
            lo = mid+1 ;
        }
    }
    cout << "! " << ans << endl;
     fflush(stdout);
}