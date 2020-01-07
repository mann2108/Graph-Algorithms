/// @author mann2108
/// MST using DSU Coin Flip Technique

#include<bits/stdc++.h>
using namespace std;
typedef int ll;

set<pair<ll,pair<ll,ll> > > st;
vector<ll> parent;

ll findParent(ll u){
    if(parent[u]==u){
        return u;
    }
    else{
        return parent[u]=findParent(parent[u]);
    }
}

int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<=n;i++)parent.push_back(i);

    while(m--){
        ll u,v,w;
        cin>>u>>v>>w;
        st.insert({w,{u,v}});
    }
    ll edge=0;
    ll sum=0;
    while(edge<n-1){
        ll u,v,w;
        u=st.begin()->second.first;
        v=st.begin()->second.second;
        w=st.begin()->first;
        u=findParent(u);
        v=findParent(v);
        st.erase(st.begin());
        if(u!=v){
            edge+=1;
            sum+=w;

            /// UNION by coin flip
            if(rand()%2==0)swap(u,v);
            parent[v]=u;

        }
    }
    cout<<sum<<endl;
    return 0;
}
