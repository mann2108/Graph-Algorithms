/// @author mann2108
/// DFS - # Connected Components in a undirected graph using DFS

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(ll u,vector<ll> adj[],vector<bool> &visited){
    visited[u]=true;
    for(ll v:adj[u]){
        if(!visited[v]){
            dfs(v,adj,visited);
        }
    }
}


int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll> adj[n+1];
    ll u,v;
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1,false);
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            cnt+=1;
            dfs(i,adj,visited);
        }
    }

    cout<<cnt<<endl;

}
