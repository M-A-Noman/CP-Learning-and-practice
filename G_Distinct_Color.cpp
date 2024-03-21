#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> graph[N];
vector<int> color;
int main(){
    int n;
    cin >> n;
    int i, x;
    for (i = 0; i < n;i++){
        cin >> x;
        color.emplace_back(x);
    }
    int v1, v2;
    for (i = 0; i < n - 1;i++){
        cin >> v1 >> v2;
        graph[v1].emplace_back(v2);
        graph[v2].emplace_back(v1);
    }
}