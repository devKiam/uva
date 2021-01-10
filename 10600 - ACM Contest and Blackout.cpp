#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

vector<int> parent;
int droppedU, droppedV;

int find(int i)
{
    if(parent[i] == i)
        return i;

    int result = find(parent[i]);
    parent[i] = result;
    return result;
}


int kruskal(vector< pair<ll,pair<ll,ll> > > &edgeList, int numOfEdges, int numOfNodes, vector< pair<ll,ll> > &resultantMSTedgeList)
{
    int MSTCount = 0, MSTweigh = 0;

    for(int i=0; i<edgeList.size(); i++)
    {
        int u = edgeList[i].second.first;
        int v = edgeList[i].second.second;
        int w = edgeList[i].first;

        int rootU = find(u), rootV = find(v);

        if(rootU != rootV)
        {
            parent[rootV] = rootU;
            MSTCount++;
            MSTweigh += w;
            resultantMSTedgeList.emplace_back(u, v);
            if(MSTCount == numOfNodes - 1) break;
        }
    }
    return MSTweigh;

}


int kruskalSecondMST(vector< pair<ll,pair<ll,ll> > > &edgeList, int numOfEdges, int numOfNodes)
{
    int MSTCount = 0, MSTweigh = 0;

    for(int i=0; i<edgeList.size(); i++)
    {
        int u = edgeList[i].second.first;
        int v = edgeList[i].second.second;
        int w = edgeList[i].first;

        if(u == droppedU && v == droppedV) continue;

        int rootU = find(u), rootV = find(v);

        if(rootU != rootV)
        {
            parent[rootV] = rootU;
            MSTCount++;
            MSTweigh += w;
            if(MSTCount == numOfNodes - 1) break;
        }
    }
    if(MSTCount < numOfNodes-1) return INT_MAX;
    return MSTweigh;

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int testCases; cin>>testCases;
    while(testCases--)
    {
        int numOfNodes, numOfEdges; cin>>numOfNodes>>numOfEdges;

        vector< pair<ll,pair<ll,ll> > > edgeList;

        for(int i=0; i<numOfEdges; i++)
        {
            int u, v, w; cin>>u>>v>>w;
            edgeList.push_back(make_pair(w, make_pair(u, v)));
        }
        sort(edgeList.begin(), edgeList.end());

        for(int i=0; i<=numOfNodes; i++){
            parent.push_back(i);
        }

        vector< pair<ll,ll> > resultantMSTedgeList;
        int firstMST = kruskal(edgeList, numOfEdges, numOfNodes, resultantMSTedgeList);
        parent.clear();

        vector<int> SecondBestMSTweigh;
        for(int i=0; i<resultantMSTedgeList.size(); i++)
        {
            for(int i=0; i<=numOfNodes; i++){
                parent.push_back(i);
            }
            droppedU = resultantMSTedgeList[i].first;
            droppedV = resultantMSTedgeList[i].second;
            SecondBestMSTweigh.push_back( kruskalSecondMST(edgeList, numOfEdges, numOfNodes) );
            parent.clear();
        }
        sort(SecondBestMSTweigh.begin(), SecondBestMSTweigh.end());

        cout<<firstMST<<" "<<SecondBestMSTweigh[0]<<endl;
        parent.clear();
    }

}
