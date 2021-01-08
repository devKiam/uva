#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


int dfs(vector<int> adjList[], vector<int> &color, map<ll, ll> &startTime, map<ll, ll> &endTime, int source, int time)
{
    int u = source;
    int s = startTime[u] = ++time;
    color[u] = 6;

    for(int i=0; i<adjList[u].size(); i++)
    {
        int v = adjList[u][i];
        if(color[v] == 0)
        {
            time = dfs(adjList, color, startTime, endTime, v, time);
        }
    }
    color[u] = 1;
    int e = endTime[u] = ++time;
    return time;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int numOfNodes, numOfEdges;

    while(cin>>numOfNodes>>numOfEdges)
    {
        if(numOfNodes == 0 && numOfEdges == 0) break;
        vector<int> adjList[numOfNodes+1];
        vector<int> color(numOfNodes+1, 0);
        map<ll, ll> startTime, endTime;

        for(int i=0; i<numOfEdges; i++)
        {
            int u, v; cin>>u>>v;
            adjList[u].push_back(v);
//        adjList[v].push_back(u);
        }

        int source = 1;
        int time = 0;
        for(int i=1; i<=numOfNodes; i++)
        {
            if(color[i] == 0)
                time = dfs(adjList, color, startTime, endTime, i, time);
        }


//    for(int i=1; i<=numOfNodes; i++)
//    {
//        cout<<startTime[i]<<" "<<endTime[i]<<endl;
//    }
        vector< pair<ll,ll> > result;
        for(int i=0; i<= numOfNodes; i++)
        {
            result.push_back(make_pair(endTime[i+1], i));
        }
        sort(result.begin(), result.end());
        reverse(result.begin(), result.end());
        for(int i=0; i<numOfNodes; i++)
        {
            cout<<result[i].second + 1<<" ";
        }
        cout<<endl;
    }

}
