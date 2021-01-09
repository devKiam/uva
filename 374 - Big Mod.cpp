#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll M;

ll F(ll N,ll P)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        ll x = F(N,P/2);
        return ((x%M)*(x%M))%M;
    }
    else return ((N%M)*(F(N,P-1) % M))%M;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll b, p;

    while(cin>>b>>p>>M)
    {
        cout<<F(b, p)<<endl;
    }
}
