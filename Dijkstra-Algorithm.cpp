/// @author mann2108
/// DIJKSTRA'S Algorithm (SSSP)

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define push_back pb

int main(){
    ll t;
    cin>>t;
    while(t--){
        double n,m,src,des;

        cin>>n>>m>>src>>des;

        vector<vector<pair<ll,double> > > adj;
        vector<pair<ll,double> > vec;
        for(ll i=0;i<=n;i++)adj.push_back(vec);


        double u,v,len,sp;

        while(m--){
            cin>>u>>v>>len>>sp;
            adj[u].push_back({v,(double)((double)len/(double)sp)});
            adj[v].push_back({u,(double)((double)len/(double)sp)});
        }

        set<pair<double,ll> > q;
        vector<double> d(n+1,(double)LLONG_MAX);
        vector<ll> p(n+1,-1);

        q.insert({0.0,src});
        d[src]=0.0;

        while(!q.empty()){

            ll v=q.begin()->second;
            if(v==des){
                break;
            }
            q.erase(q.begin());


            for(auto edge:adj[v]){
                ll to=edge.first;
                double len=edge.second;

                // Relaxation
                if(d[v]+len<d[to]){
                    q.erase({d[to],to});
                    d[to]=d[v]+len;
                    p[to]=v;
                    q.insert({d[to],to});
                }
            }
        }

        if(d[des]==LLONG_MAX){
            cout<<"-1"<<endl;
        }
        else{
            cout<<fixed<<setprecision(8)<<d[des]<<endl;
        }
    }
}
