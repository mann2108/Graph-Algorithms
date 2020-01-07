/// @author mann2108
/// Lowest Common Ancestor (LCA) in O(N)

/** LCA O(Q*N)*/

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll LCA(vector<ll> &vertices,vector<ll> &depth,ll u,ll v){
    ll x=0,y=0;
    bool flag_x=true;
    bool flag_y=true;
    for(ll i=0;i<vertices.size();i++){
        if(u==vertices[i] and flag_x){
            x=i;
            flag_x=false;
        }
        if(v==vertices[i] and flag_y){
            y=i;
            flag_y=false;
        }
    }

    ll min=INT_MAX;

    ll z=0;

    for(ll i=x;i<=y;i++){
        if(depth[i]<min){
            z=i;
            min=depth[i];
        }
    }

    return vertices[z];
}

void dfs(vector<vector<ll> > &adj,vector<bool> &visited,vector<ll> &vertices,vector<ll> &depth,ll u,ll h=1){
    visited[u]=true;
    depth.push_back(h);
    vertices.push_back(u);
    for(ll v:adj[u]){
        if(!visited[v]){
            dfs(adj,visited,vertices,depth,v,h+1);
            depth.push_back(h);
            vertices.push_back(u);
        }
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){

        vector<vector<ll> > adj;
        vector<bool> visited;
        vector<ll> vertices;
        vector<ll> depth;
        vector<ll> temp;

        ll n,e;
        cin>>n>>e;

        for(ll i=0;i<=n;i++)adj.push_back(temp);
        for(ll i=0;i<=n;i++)visited.push_back(false);

        while(e--){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                dfs(adj,visited,vertices,depth,i);
            }
        }
        for(ll i=0;i<vertices.size();i++)cout<<vertices[i]<<" ";
        cout<<endl;
        for(ll i=0;i<depth.size();i++)cout<<depth[i]<<" ";
        cout<<endl;
        ll q;
        cin>>q;
        while(q--){
            ll u,v;
            cin>>u>>v;
            cout<<LCA(vertices,depth,u,v)<<endl;
        }
    }
}



