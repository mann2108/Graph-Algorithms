/// @author mann2108
/// DFS

/** DFS WITH INTIME AND OUTTIME OF EACH NODE */

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;


void dfs(vector<vector<ll> > &adj,vector<bool> &visited,vector<pair<ll,ll> > &time_data,ll u){
    visited[u]=true;
    time_data[u].first=timer++;
    for(ll v:adj[u]){
        if(!visited[v]){
            dfs(adj,visited,time_data,v);
        }
    }
    time_data[u].second=timer++;
}

int main(){
    ll t;
    cin>>t;
    while(t--){

        ll n,e;
        cin>>n>>e;

        vector<vector<ll> > adj;
        vector<bool> visited;
        vector<pair<ll,ll> > time_data;
        vector<ll> temp;
        timer=0;


        /** Reserving and Assigning default values */

        for(ll i=0;i<=n;i++)visited.push_back(false);
        for(ll i=0;i<=n;i++)time_data.push_back(make_pair(-1,-1));
        for(ll i=0;i<=n;i++)adj.push_back(temp);

        while(e--){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                dfs(adj,visited,time_data,i);
            }
        }

        for(ll i=1;i<=n;i++){
            cout<<i<<" "<<time_data[i].first<<" "<<time_data[i].second<<endl;
        }

    }

}
