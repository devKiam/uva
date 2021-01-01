#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll dirRow[] = {-1, -2, -2, -1, 1, 2, 2, 1};
ll dirCol[] = {-2, -1, 1, 2, -2, -1, 1, 2};

ll bfs(vector< vector<ll> > &distance, ll startRow, ll startColumn, ll destinationRow, ll destinationColumn)
{
    queue<ll> rowQ;
    queue<ll> columnQ;
    rowQ.push(startRow); columnQ.push(startColumn);
    distance[startRow][startColumn] = 0;

    while(!rowQ.empty())
    {
        ll r = rowQ.front(); ll c = columnQ.front();
        rowQ.pop(); columnQ.pop();

        for(int i=0; i<8; i++)
        {
            if(r + dirRow[i] > 8 || r + dirRow[i] < 1 || c + dirCol[i] > 8 || c + dirCol[i] < 1) continue;
            if(distance[r + dirRow[i]][c + dirCol[i]] == -1)
            {
                distance[r + dirRow[i]][c + dirCol[i]] = distance[r][c] + 1;
                rowQ.push(r + dirRow[i]); columnQ.push(c + dirCol[i]);
            }
        }
        if(distance[destinationRow][destinationColumn] != -1) return distance[destinationRow][destinationColumn];
    }

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    string start, destination;
    map<char, char> m;
    m['a'] = '1'; m['b'] = '2'; m['c'] = '3'; m['d'] = '4'; m['e'] = '5'; m['f'] = '6'; m['g'] = '7'; m['h'] = '8';

    while(cin>>start>>destination)
    {
        string START = start, DESTINATION = destination;
        start[0] = m[start[0]]; destination[0] = m[destination[0]];
        ll startRow = int(start[1])-48, startColumn = int(start[0])-48, destinationRow = int(destination[1])-48, destinationColumn = int(destination[0])-48;
        vector< vector<ll> > distance(9, vector<ll> (9, -1));

        ll result = bfs(distance, startRow, startColumn, destinationRow, destinationColumn);
        cout<<"To get from "<<START<<" to "<<DESTINATION<<" takes "<<result<<" knight moves."<<endl;
    }

}
