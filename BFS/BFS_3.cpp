/// @author mann2108
/// BFS


/** Find all minimum edges required to reach source to all vertex */

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main(){

    ll t;
    cin>>t;

    while(t--){

        ll n,s,e;

        cin>>n>>s>>e;

        vector<vector<ll> > adj(n+1);
        vector<ll> visited(n+1);
        vector<ll> distance(n+1);

        while(e--){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<ll> q;
        visited[s]=true;
        distance[s]=0;
        q.push(s);

        while(!q.empty()){
            ll v = q.front();
            q.pop();

            for(ll u:adj[v]){
                if(!visited[u]){
                    visited[u]=true;
                    q.push(u);
                    distance[u]=distance[v]+1;
                }
            }
        }

        for(ll i=1;i<=n;i++)cout<<distance[i]<<" ";
        cout<<endl;

    }

}
