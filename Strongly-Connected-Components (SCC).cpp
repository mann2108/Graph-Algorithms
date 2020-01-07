/// @author mann2108
/// Strongly Connected Components DAG using DSU

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

///SCC

const ll max1=1e5+10;
vector<ll> adj[max1];
vector<ll> adjReverse[max1];
vector<bool> visited;
vector<ll> topoSort;
vector<vector<ll> > scc;

void dfs1(ll u){
    visited[u]=true;
    for(ll v:adjReverse[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    topoSort.push_back(u);
}

void dfs2(ll u,vector<ll> &cc){
    cc.push_back(u);
    visited[u]=true;
    for(ll v:adj[u]){
        if(!visited[v]){
            dfs2(v,cc);
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;

    cin>>n>>m;
    ll x,y;

    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
        adjReverse[y].push_back(x);
    }

    visited.assign(n+1,false);
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }

    reverse(topoSort.begin(),topoSort.end());
    visited.assign(n+1,false);

    for(ll i=0;i<topoSort.size();i++){
        if(!visited[topoSort[i]]){
            vector<ll> cc;
            dfs2(topoSort[i],cc);
            scc.push_back(cc);
        }
    }
    for(ll i=0;i<scc.size();i++){
        for(ll j=0;j<scc[i].size();j++){
            cout<<scc[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

