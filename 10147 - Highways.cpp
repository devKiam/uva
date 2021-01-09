#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<int> parent;

int find(int i)
{
    if(parent[i] == i)
        return i;

    int root = find(parent[i]);
    parent[i] = root;
    return root;
}


void kruskal(vector< pair<ll,pair<ll,ll> > > &edgeList, int numOfEdges, int numOfNodes, vector< pair<ll, ll> > &resultMSTedges, int MSTcount)
{
    for(int i=0; i<edgeList.size(); i++)
    {
        int u = edgeList[i].second.first;
        int v = edgeList[i].second.second;
        int w = edgeList[i].first;

        int rootU = find(u), rootV = find(v);

        if(rootU != rootV)
        {
            parent[rootV] = rootU;
            resultMSTedges.emplace_back(u,v);
            MSTcount++;
        }
        if(MSTcount == numOfNodes -1) break;
    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int testCases; cin>>testCases;
    while(testCases--)
    {
        int numOfNodes; cin>>numOfNodes;
        vector< pair<ll,ll> > coOrdinates;
        for(int i=0; i<numOfNodes; i++)
        {
            int x, y; cin>>x>>y; coOrdinates.emplace_back(x, y);
        }

        int numOfEdges; cin>>numOfEdges;
        vector< pair<ll, pair<ll,ll> > > edgeList;
        for(int i=1; i<=numOfNodes; i++)
        {
            for(int j=1; j<=numOfNodes; j++)
            {
                if(i!=j)
                {
                    int w = ((coOrdinates[i-1].first - coOrdinates[j-1].first) * (coOrdinates[i-1].first - coOrdinates[j-1].first)) + ((coOrdinates[i-1].second - coOrdinates[j-1].second) * (coOrdinates[i-1].second - coOrdinates[j-1].second));
                    edgeList.emplace_back(w, make_pair(i, j));
                }
            }
        }

        sort(edgeList.begin(), edgeList.end());

        // 1 2 3 4 5 ......
        // 1 2 3 4 5 ......
        for(int i=0; i<=numOfNodes; i++){
            parent.push_back(i);
        }
        int MSTcount = 0;
        for(int i=0; i<numOfEdges; i++)
        {
            int u, v; cin>>u>>v;

            int rootU = find(u), rootV = find(v);
            if(rootU != rootV)
            {
                parent[rootV] = rootU;
                MSTcount++;
            }
        }
        vector< pair<ll, ll> > resultMSTedges;
        kruskal(edgeList, numOfEdges, numOfNodes, resultMSTedges, MSTcount);
        if(!resultMSTedges.empty())
        {
            for(int i=0; i<resultMSTedges.size(); i++)
                cout<<resultMSTedges[i].first<<" "<<resultMSTedges[i].second<<endl;
        }
        else cout<<"No new highways need"<<endl;
        parent.clear();
        if(testCases) cout<<endl;
    }
}
