#include<bits/stdc++.h>
using namespace std;

int bfsmatrix(vector<vector<int>> &grid)
{
    queue<pair<int,int>> q;
    vector<vector<bool>> visited;
    queue<vector<pair<int,int>>> qOfPaths;
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
    visited[0][0]=true;
    q.push(make_pair(0,0));
    qOfPaths.push({make_pair(0,0)});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        auto currentPath=qOfPaths.front();
        // //cout<<"-------x is "<<x<<" y is "<<y<<"---------\n";
        if(x+1<gridLength)
        {
            if(visited[x+1][y]==false)
            {
                
                if(grid[x+1][y]==0)
                {
                
                    visited[x+1][y]=true;
                    q.push(make_pair(x+1,y));
                    currentPath.push_back(make_pair(x+1,y));
                    qOfPaths.push(currentPath);
                    currentPath.pop_back();
                    //cout<<"x-->"<<x+1<<" y-->"<<y<<"\n";
                    if(x+1==gridLength-1 && y==gridLength-1)
                    {
                        //cout<<"optimal path found\n";
                        for(auto ele:currentPath)
                        {
                            //cout<<"x-->"<<ele.first<<" y-->"<<ele.second<<"\n";
                        }
                        //cout<<"x-->"<<x+1<<" y-->"<<y<<"\n";
                        return currentPath.size()+1;
                    }
                }
            }
        }
        if(y+1<gridWidth)
        {
            if(visited[x][y+1]==false)
            {
            
                if(grid[x][y+1]==0)
                {
                    
                    visited[x][y+1]=true;
                    q.push(make_pair(x,y+1));
                    currentPath.push_back(make_pair(x,y+1));
                    qOfPaths.push(currentPath);
                    currentPath.pop_back();
                    //cout<<"x-->"<<x<<" y-->"<<y+1<<"\n";
                    if(x==gridLength-1 && y+1==gridLength-1)
                    {
                        //cout<<"optimal path found\n";
                        for(auto ele:currentPath)
                        {
                            //cout<<"x-->"<<ele.first<<" y-->"<<ele.second<<"\n";
                        }
                        //cout<<"x-->"<<x<<" y-->"<<y+1<<"\n";
                        return currentPath.size()+1;
                    }

                }
            }
        }
        if(x+1<gridLength && y+1<gridWidth)
        {
            if(visited[x+1][y+1]==false)
            {
                
                if(grid[x+1][y+1]==0)
                {
                    visited[x+1][y+1]=true;
                    q.push(make_pair(x+1,y+1));
                    currentPath.push_back(make_pair(x+1,y+1));
                    qOfPaths.push(currentPath);
                    currentPath.pop_back();
                    //cout<<"x-->"<<x+1<<" y-->"<<y+1<<"\n";
                    if(x+1==gridLength-1 && y+1==gridLength-1)
                    {
                        //cout<<"optimal path found\n";
                        for(auto ele:currentPath)
                        {
                            //cout<<"x-->"<<ele.first<<" y-->"<<ele.second<<"\n";
                        }
                        //cout<<"x-->"<<x+1<<" y-->"<<y+1<<"\n";
                        return currentPath.size()+1;
                    }
                }
            }
        }
        if(x-1>=0)
        {
            if(visited[x-1][y]==false)
            {
                
                
                if(grid[x-1][y]==0)
                {
                    visited[x-1][y]=true;
                    q.push(make_pair(x-1,y));
                    currentPath.push_back(make_pair(x-1,y));
                    qOfPaths.push(currentPath);
                    currentPath.pop_back();
                    //cout<<"x-->"<<x-1<<" y-->"<<y<<"\n";
                }
            }
        }
        if(y-1>=0)
        {
            if(visited[x][y-1]==false)
            {
                
                if(grid[x][y-1]==0)
                {
                    visited[x][y-1]=true;
                    q.push(make_pair(x,y-1));
                    currentPath.push_back(make_pair(x,y-1));
                    qOfPaths.push(currentPath);
                    currentPath.pop_back();
                    //cout<<"x-->"<<x<<" y-->"<<y-1<<"\n";
                }
            }
        }
        if(x-1>=0 && y-1>=0)
        {
            if(visited[x-1][y-1]==false)
            {
                
                
                if(grid[x-1][y-1]==0)
                {
                    visited[x-1][y-1]=true;
                    q.push(make_pair(x-1,y-1));
                    currentPath.push_back(make_pair(x-1,y-1));
                    qOfPaths.push(currentPath);
                    currentPath.pop_back();
                    //cout<<"x-->"<<x-1<<" y-->"<<y-1<<"\n";
                }
            }
        }
        if(x+1<gridLength && y-1>=0)
        {
            if(visited[x+1][y-1]==false)
            {
                
                
                if(grid[x+1][y-1]==0)
                {
                    visited[x+1][y-1]=true;
                    q.push(make_pair(x+1,y-1));
                    currentPath.push_back(make_pair(x+1,y-1));
                    qOfPaths.push(currentPath);
                    currentPath.pop_back();
                    //cout<<"x-->"<<x+1<<" y-->"<<y-1<<"\n";
                }
            }
        }
        if(x-1>=0 && y+1<gridWidth)
        {
            if(visited[x-1][y+1]==false)
            {
                
                
                if(grid[x-1][y+1]==0)
                {
                    visited[x-1][y+1]=true;
                    q.push(make_pair(x-1,y+1));
                    currentPath.push_back(make_pair(x-1,y+1));
                    qOfPaths.push(currentPath);
                    currentPath.pop_back();
                    //cout<<"x-->"<<x-1<<" y-->"<<y+1<<"\n";
                }
            }
        }

        q.pop();
        qOfPaths.pop();
    }
    return -1;
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
    cout<<bfsmatrix(grid);
    return 0;
}