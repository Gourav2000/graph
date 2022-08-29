#include<bits/stdc++.h>
using namespace std;

vector<int> bfsmatrix(vector<vector<int>> &grid)
{
    queue<pair<int,int>> q;
    vector<vector<bool>> visited;
    vector<int> output;
    int gridLength=grid[0].size();
    int gridWidth=grid.size();
    int i=0;
    for(auto ele:grid)
    {
        visited.push_back({});
        for(auto ele2:ele)
        {
           visited[i].push_back(false);
        }
        ++i;
    }
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        if(visited[x+1][y]==false && x+1<gridLength)
        {
            visited[x+1][y]=true;
            q.push(make_pair(x+1,y));
            output.push_back(grid[x+1][y]);
            cout<<"x-->"<<x+1<<" y-->"<<y<<"\n";
        }
        if(visited[x][y+1]==false && y+1<gridWidth)
        {
            visited[x][y+1]=true;
            q.push(make_pair(x,y+1));
            output.push_back(grid[x][y+1]);
            cout<<"x-->"<<x<<" y-->"<<y+1<<"\n";
        }
        if(visited[x+1][y+1]==false && x+1<gridLength && y+1<gridWidth)
        {
            visited[x+1][y+1]=true;
            q.push(make_pair(x+1,y+1));
            output.push_back(grid[x+1][y+1]);
            cout<<"x-->"<<x+1<<" y-->"<<y+1<<"\n";
        }
        if(visited[x-1][y]==false && x-1>=0)
        {
            visited[x-1][y]=true;
            q.push(make_pair(x-1,y));
            output.push_back(grid[x-1][y]);
            cout<<"x-->"<<x-1<<" y-->"<<y<<"\n";
        }
        if(visited[x][y-1]==false y-1>=0)
        {
            visited[x][y-1]=true;
            q.push(make_pair(x,y-1));
            output.push_back(grid[x][y-1]);
            cout<<"x-->"<<x<<" y-->"<<y-1<<"\n";
        }
        if(visited[x-1][y-1]==false && x-1>=0 && y-1>=0)
        {
            visited[x-1][y-1]=true;
            q.push(make_pair(x-1,y-1));
            output.push_back(grid[x-1][y-1]);
            cout<<"x-->"<<x-1<<" y-->"<<y-1<<"\n";
        }
        q.pop();
    }
    return output;
}

int main()
{
    vector<vector<int>> grid;
    int dimension;
    cin>>dimension;
    for(int i=0;i<dimension;++i)
    {
        grid.push_back({});
        for(int j=0;j<dimension;++j)
        {
            int x;
            cin>>x;
            grid[i].push_back(x);
        }
    }
    bfsmatrix(grid);
    return 0;
}