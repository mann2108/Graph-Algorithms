/// @author mann2108
/// DP ON TREE - 2 (EASY)

/**
 * Problem Description : -
 * Given a rooted tree with node 1.
 * Task is to find the height of the tree.
**/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define pb push_back


void dp_with_dfs(ll u, vector<ll> adj[], vector<bool> &visited, vector<ll> &dp){
    visited[u]=true;
    ll max_child = 1;
    for(ll v:adj[u]){
        if(!visited[v]){
            dp_with_dfs(v,adj,visited,dp);
            max_child = max(max_child,dp[v]+1);
        }
    }
    dp[u] = max_child;
}

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;

        vector<ll> adj[n+1];

        ll u,v;

        for(ll i=0;i<n-1;i++)cin>>u>>v, adj[u].pb(v), adj[v].pb(u);

        vector<bool> visited(n+1,false);
        vector<ll> dp(n+1,0);

        dp_with_dfs(1,adj,visited,dp);

        cout<<dp[1]<<endl;
    }
}

