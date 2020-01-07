/// @author mann2108
/// Topological Sorting (TOPO Sort)

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<ll> > adj;
vector<bool> visited;
vector<ll> topoSort;

void dfs(ll u){
    visited[u]=true;
    for(ll v:adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    topoSort.push_back(u);
}


int main(){

    ll n,m;
    cin>>n>>m;
    vector<ll> vec;
    for(ll i=0;i<=n;i++){
        adj.push_back(vec);
        visited.push_back(false);
    }
    ll x,y;
    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
    }

    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    if(topoSort.size()==n){
        reverse(topoSort.begin(),topoSort.end());
        for(ll i=0;i<topoSort.size();i++){
            cout<<topoSort[i]<<" ";
        }
        cout<<endl;
    }
    else{

        /** we cant able to reach all vertices from started node !! */
    }

}
