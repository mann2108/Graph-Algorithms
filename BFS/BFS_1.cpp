/// @author mann2108
/// BFS

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

        queue<ll> q;

        vector<bool> used(n+1);

        while(e--){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        q.push(s);
        used[s]=true;
        while(!q.empty()){

            ll v=q.front();
            cout<<v<<" ";
            q.pop();

            for(ll u:adj[v]){
                if(!used[u]){
                    used[u]=true;
                    q.push(u);
                }
            }
        }
        cout<<endl;
    }
}
