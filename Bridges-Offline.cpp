/// @author mann2108
/// Bridges Offline

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll MAX=1e5+10;

ll cnt=1;
vector<ll> low;
vector<ll> id;
vector<bool> visited;
set<pair<ll,ll> > bridges;

void dfs(ll at,ll p,vector<ll> adj[]){
    visited[at]=true;
    id[at]=low[at]=cnt++;

    for(ll to:adj[at]){
        if(to==p)continue;
        if(!visited[to]){
            dfs(to,at,adj);
            low[at]=min(low[at],low[to]);
            if(id[at]<low[to]){
                bridges.insert({min(at,to),max(at,to)});
            }
        }
        else{
            low[at]=min(low[at],id[to]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    for(ll k=1;k<=t;k++){
        cnt=1;
        bridges.clear();
        vector<ll> adj[MAX];

        ll n,m;

        cin>>n>>m;

        visited.assign(n+1,false);
        ll u,v;

        low.assign(n+1,0);
        id.assign(n+1,0);

        while(m--){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        for(ll i=1;i<=n;i++){
            if(!visited[i]){
                dfs(i,-1,adj);
            }
        }

        ll brg=bridges.size();
        if(brg==0){
            cout<<"Caso #"<<k<<endl;
            cout<<"Sin bloqueos"<<endl;

        }
        else{
            cout<<"Caso #"<<k<<endl;
            cout<<brg<<endl;
            for(pair<ll,ll> i:bridges){
                cout<<i.first<<" "<<i.second<<endl;
            }
        }
    }

}
