/// @author mann2108
/// Shortest Path finding in DAG (Directed Acyclic Graph)

/**
SHORTEST PATH IN DAG
*/

/**
LONGEST PATH for UNDIRECTED Graph is NP-Hard Problem.
but
LONGEST PATH for DAG is in O(V+E)
where multiply all edges with -1 and find shortest path then multiply final result with -1.
*/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;
void dfs(ll u,vector<ll> &topoSort,vector<pair<ll,ll> > adj[],vector<bool> &visited){
    visited[u]=true;
    for(auto v:adj[u]){
        if(!visited[v.second]){
            dfs(v.second,topoSort,adj,visited);
        }
    }
    topoSort.pb(u);
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<bool> visited(n+1,false);
        vector<ll> depth(n+1,LLONG_MAX);
        vector<pair<ll,ll> > adj[n+1];
        vector<ll> topoSort;
        ll u,v,w;
        while(m--){
            cin>>u>>v>>w;
            adj[u].pb({w,v});
        }
        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i,topoSort,adj,visited);
            }
        }
        reverse(topoSort.begin(),topoSort.end());
        depth[topoSort[0]]=0;
        for(ll i=0;i<topoSort.size();i++){
            ll u=topoSort[i];
            for(pair<ll,ll> v:adj[u]){
                depth[v.second]=min(depth[v.second],depth[u]+v.first);
            }
        }
        for(ll i=1;i<=n;i++){
            cout<<depth[i]<<" ";
        }
        cout<<endl;
    }
}
