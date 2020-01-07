/// @author mann2108
/// BFS


/** Showing all shortest path from source vertex s */

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
        vector<bool> visited(n+1);
        vector<ll> parent(n+1);

        while(e--){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<ll> q;
        q.push(s);
        visited[s]=true;
        parent[s]=-1;


        while(!q.empty()){
            ll v = q.front();
            q.pop();

            for(ll u:adj[v]){
                if(!visited[u]){
                    visited[u]=true;
                    cout<<u<<" ";
                    q.push(u);
                    parent[u]
                }
            }
        }
        cout<<endl;

        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                cout<<"NO PATH !!"<<endl;
            }
            else{
                vector<ll> path;
                for(ll v=i;v!=-1;v=parent[v]){
                    path.push_back(v);
                }
                reverse(path.begin(),path.end());
                cout<<"Path: "<<i<<endl;
                for(ll v:path){
                    cout<<v<<" ";
                }
                cout<<endl;
            }
        }
    }
}
