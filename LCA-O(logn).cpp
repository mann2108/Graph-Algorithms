/// @author mann2108
/// Lowest Common Ancestor in O(log(n)) using (Segment Tree + Euler Tour)

/** o(Q*log(n)) using RMQ range minimum query
Q-> Queries
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll MAXN=1e5+1e5;

pair<ll,ll> t[4*MAXN];

pair<ll,ll> combine(pair<ll,ll> p1,pair<ll,ll> p2){
    if(p1.first<=p2.first){
        return p1;
    }
    else{
        return p2;
    }
}

void build(ll a[],ll v,ll tl,ll tr){
    if(tl==tr){
        t[v]=make_pair(a[tl],tl);
    }
    else{

        ll tm = (tl+tr)/2;

        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);

        t[v]=combine(t[2*v],t[2*v+1]);
    }
}


void dfs(vector<vector<ll> > &adj,vector<bool> &visited,vector<ll> &vertexes,vector<ll> &depths,ll u,ll h=1){

    visited[u]=true;

    vertexes.push_back(u);
    depths.push_back(h);

    for(ll v:adj[u]){
        if(!visited[v]){
            dfs(adj,visited,vertexes,depths,v,h+1);
            vertexes.push_back(u);
            depths.push_back(h);
        }
    }

}

int main(){
    ll test;
    cin>>test;

    while(test--){

        ll n;
        cin>>n;

        ll e=(n-1);

        vector<vector<ll> > adj;
        vector<bool> visited;
        vector<ll> temp,vertexes,depths;

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
                dfs(adj,visited,vertexes,depths,i);
            }
        }


        for(ll i=0;i<vertexes.size();i++){
            cout<<vertexes[i]<<" ";
        }
        cout<<endl;
        for(ll i=0;i<depths.size();i++){
            cout<<depths[i]<<" ";
        }
        cout<<endl;

        vector<ll> occurences(n+1);

        for(ll i=0;i<=n;i++)occurences[i]=-1;

        for(ll i=0;i<vertexes.size();i++){
            if(occurences[vertexes[i]]==-1){
                occurences[vertexes[i]]=i;
            }
        }

        for(ll i=1;i<=n;i++){
            cout<<occurences[i]<<" ";
        }
        cout<<endl;

        ll q;
        cin>>q;
        ll a[2*n];

        for(ll i=0;i<depths.size();i++)a[i+1]=depths[i];

        build(a,1,1,2*n+1);


        while(q--){
            ll u,v;
            ll l=occurences[u];
            ll r=occurences[v];
//            pair<ll,ll> ans = query(1,1,n,l,r);
//            cout<<vertexes[ans.second]<<endl;
        }
    }
}
