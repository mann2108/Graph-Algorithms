/// @author mann2108
/// DP ON TREE - 1 (EASY)

/**
 * Problem Description : -
 * Given a rooted tree with node 1, also each node contain some score.
 * Task is to find the maximum possible score from the root to leaf node.
**/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define pb push_back


void dp_with_dfs(ll u, vector<ll> adj[], ll score_array[], vector<bool> &visited, vector<ll> &dp){
    visited[u]=true;
    dp[u] = score_array[u];
    ll max_child = 0;
    for(ll v:adj[u]){
        if(!visited[v]){
            dp_with_dfs(v,adj,score_array,visited,dp);
            max_child = max(max_child,dp[v]);
        }
    }
    dp[u]+=max_child;
}

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;

        vector<ll> adj[n+1];

        ll u,v;

        for(ll i=0;i<n-1;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        ll score_array[n+1];

        for(ll i=1;i<=n;i++)cin>>score_array[i];

        vector<bool> visited(n+1,false);
        vector<ll> dp(n+1,0);

        dp_with_dfs(1,adj,score_array,visited,dp);

        cout<<dp[1]<<endl;
    }
}
