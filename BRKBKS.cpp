#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){

    ll t;
    cin>>t;

    while(t--){
        ll s,w1,w2,w3;
        cin>>s>>w1>>w2>>w3;
        if(s>=(w1+w2+w3)){
            cout<<1<<endl;
        }
        else{
            if(s>=w1+w2 or s>=w2+w3){
                cout<<2<<endl;
            }
            else{
                cout<<3<<endl;
            }
        }
    }

}
