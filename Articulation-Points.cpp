/// @author mann2108
/// Articulation Points & Cut Vertices

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long int ll;

const ll MAX = 1e4+10;
vector<ll> tin,low;
vector<bool> visited;
set<ll> cutPoint;
ll timer;



void clear(){
    timer=0;
    tin.clear();
    low.clear();
    cutPoint.clear();
}


void dfs(ll u,ll p,vector<ll> adj[]){
    visited[u]=true;
    low[u]=tin[u]=timer++;
    ll children=0;
    for(ll to:adj[u]){
        if(to==p)continue;
        if(!visited[to]){
            dfs(to,u,adj);
            low[u]=min(low[u],low[to]);
            if(low[to]>=tin[u] and p!=-1){
                cutPoint.insert(u);
            }
            children++;
        }
        else{
            low[u]=min(low[u],tin[to]);
        }

    }

    if(p==-1 and children>1){
        cutPoint.insert(u);
    }
}


int main(){
    ll t;
    ll n,m;
    cin>>n>>m;

    while(n!=0 and m!=0){

        clear();

        ll u,v;

        visited.assign(n+1,false);
        low.assign(n+1,false);
        tin.assign(n+1,false);
        vector<ll> adj[n+1];
        while(m--){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i,-1,adj);
            }
        }

        cout<<cutPoint.size()<<endl;
        cin>>n>>m;
    }
}
