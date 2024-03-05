#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> dis(N, INT_MAX);
vector<pair<int, int>> graph[N];
void dijkstra(int source){
    vector<bool> vis(N,false);
    // vector<int> dis(N, INT_MAX);
    set<pair<int, int>> st;
    st.insert({0, source});
    dis[source] = 0;
    while(st.size()>0){
        auto node = *st.begin();
        int v = node.second;
        int v_weight = node.first;
        st.erase(st.begin());
        if(vis[v])continue;
         vis[v] = true;
         for(auto child:graph[v]){
             int child_v = child.first;
             int child_weight = child.second;
             if(dis[v]+child_weight<dis[child_v]){
                 dis[child_v] = dis[v] + child_weight;
                 st.insert({dis[child_v], child_v});
             }
         }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
    }
    dijkstra(1);
    for (int i = 1; i <= n;i++)
        cout << dis[i] << ' ';
}
/*
6 9 
1 2 1
1 3 5
2 3 2
2 4 2
2 5 1
4 6 1
4 5 3
5 6 2
3 5 2
*/