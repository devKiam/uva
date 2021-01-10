#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

map<string, string> parent;
map<string, ll> numOfMember;

string find(string i)
{
    if(parent[i] == i)
        return i;

    string result = find(parent[i]);
    parent[i] = result;
    return result;
}

void Union(string u, string v)
{
    string rootU = find(u), rootV = find(v);
    if(rootU != rootV)
    {
        parent[rootV] = rootU;
        numOfMember[rootU] = numOfMember[rootU] + numOfMember[rootV] + 1;
    }
    cout<<numOfMember[rootU]+1<<endl;

}

void kruskal(vector< pair<ll,pair<string, string> > > &edgeList, int numOfEdges, int numOfNodes)
{
    for(int i=0; i<edgeList.size(); i++)
    {
        string u = edgeList[i].second.first;
        string v = edgeList[i].second.second;
        int w = edgeList[i].first;

        Union(u, v);

    }

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int testCases; cin>>testCases;
    while(testCases--)
    {
        int numOfNodes, numOfEdges; cin>>numOfEdges;

        vector< pair<ll,pair<string,string> > > edgeList;

        for(int i=0; i<numOfEdges; i++)
        {
            string u, v; cin>>u>>v;
            int w = 1;
            edgeList.emplace_back(w, make_pair(u, v));
            parent[u] = u; parent[v] = v;
        }

        kruskal(edgeList, numOfEdges, numOfNodes);
        parent.clear();
        numOfMember.clear();
    }

}
