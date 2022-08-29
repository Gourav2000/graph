#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bfsAllpaths( map<int,vector<int>> adjList, int src, int dest)
{
    queue<vector<int>> q;
    map<int,bool> visited;
    vector<vector<int>> output;
    for(auto ele:adjList)
    {
        visited[ele.first]=false;
    }
    
    visited[src]=true;
    q.push({src});
    while(!q.empty())
    {
        int node=q.front().back();
        for(auto ele:adjList[node])
        {
            if(ele==dest && count(q.front().begin(),q.front().end(),dest)==0)
            {
                vector<int> oneOfThePaths(q.front().begin(),q.front().end());
                oneOfThePaths.push_back(ele);
                output.push_back(oneOfThePaths);
                // cout<<"path---->>";
                // for(auto ele2:q.front())
                // {
                //     cout<<ele2<<" ";
                // }
                // cout<<ele;
                // cout<<"\n";
            }
            if(count(q.front().begin(),q.front().end(),ele)==0)
            {
                visited[ele]=true;
                vector<int> element(q.front().begin(),q.front().end());
                
                element.push_back(ele);
                q.push(element);
                for(auto ele3:element )
                {
                    cout<<ele3<<" ";
                }
                cout<<"\n";
            }
        }
        q.pop();
    }
    return output;
}

int main()
{
    map<int,vector<int>> adjList;
    int x,y;
    int noOfVertices;
    int noOfEdges;
    cin>>noOfVertices>>noOfEdges;
    for(int i=0;i<noOfEdges;++i)
    {
        cin>>x>>y;
        adjList[x].push_back(y);
        
    }
    //displayGraph(adjList);
    vector<vector<int>> output=bfsAllpaths(adjList,0,4);
    int pathIndex=0;
    for(auto ele:output)
    {
        
        ++pathIndex;
        cout<<"path"<<pathIndex<<"--->> ";
        for(auto ele2:ele)
        {
            cout<<ele2<<" ";
        }
        cout<<"\n";
    }
    return 0;
}