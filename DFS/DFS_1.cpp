/// @author mann2108
/// Standard DFS

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;



void dfs(vector<vector<ll> > &adj,vector<bool> &visited,ll u){
    cout<<u<<" ";
    visited[u]=true;
    for(ll v:adj[u]){
        if(!visited[v]){
            dfs(adj,visited,v);
        }
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,e;
        cin>>n>>e;

        vector<vector<ll> > adj;
        vector<bool> visited;




        for(ll i=0;i<=n;i++)visited.push_back(false);
        for(ll i=0;i<=n;i++){
            vector<ll> vec;
            adj.push_back(vec);
        }


        while(e--){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll cnt=0;
        for(ll i=1;i<=n;i++){

            if(!visited[i]){
                cnt+=1;
                dfs(adj,visited,i);
            }
        }
        cout<<endl;
        cout<<cnt<<endl;
    }

}
