#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;


ll bfs(vector<int> adjList[], vector<int> distance, map<int, int> &days, int start)
{
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    int totalDays = 0;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0; i<adjList[u].size(); i++)
        {
            int v = adjList[u][i];
            if(distance[v] == -1)
            {
                q.push(v);
                distance[v] = distance[u] + 1;
                totalDays += days[v];
            }
        }
    }
    return totalDays;
}


int bfsMax(vector<int> adjList[], vector<int> distance, map<int, int> &days, int start)
{
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    int totalDays = days[start];
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i=0; i<adjList[u].size(); i++)
        {
            int v = adjList[u][i];
            if(distance[v] == -1)
            {
                q.push(v);
                distance[v] = distance[u] + 1;
                totalDays += days[v];
            }
        }
    }
    return totalDays;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    int nodes, edges, testCases = 1;
    while(cin>>nodes>>edges)
    {
        if(nodes == 0 && edges == 0) break;
        map<int, int> days;
        int totalDays = 0;
        for(int i=0; i<nodes; i++)
        {
            int day; cin>>day; days[i+1] = day; totalDays += day;
        }
        vector<int> adjList[nodes+1], adjListBackWard[nodes+1];
        vector<int> distance(nodes+1, -1);
        for(int i=0; i<edges; i++)
        {
            int u, v; cin>>u>>v;
            adjList[v].push_back(u);
            adjListBackWard[u].push_back(v);
        }
        int queries; cin>>queries;
        vector<int> answers;

        for(int i=0; i<queries; i++)
        {
            int job; cin>>job;
            int minDaysNeed = bfs(adjList, distance, days, job);
            int maxDaysNeed = bfsMax(adjListBackWard, distance, days, job);
            answers.push_back(abs((totalDays - maxDaysNeed) - minDaysNeed));
        }
        cout<<"Case #"<<testCases++<<":"<<endl;
        for(int i=0; i<answers.size(); i++)
            cout<<answers[i]<<endl;
        cout<<endl;
    }
}
