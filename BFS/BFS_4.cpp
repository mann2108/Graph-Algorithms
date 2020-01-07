/// @author mann2108
/// BFS


/** Finding Connected Components using BFS */

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
int main(){
    ll t;
    cin>>t;
    while(t--){

        ll n,e;
        cin>>n>>e;

        vector<vector<ll> > adj(n+1);
        vector<ll> visited(n+1);

        while(e--){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ll connected_component=0;

        for(ll i=1;i<=n;i++){

            if(!visited[i]){

                connected_component+=1;

                queue<ll> q;
                q.push(i);
                visited[i]=true;

                while(!q.empty()){
                    ll v = q.front();
                    q.pop();

                    for(ll u:adj[v]){
                        if(!visited[u]){
                           visited[u]=true;

                           q.push(u);
                        }
                    }

                }

            }
        }
        cout<<connected_component<<endl;
    }
}
