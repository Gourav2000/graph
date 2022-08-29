#include<bits/stdc++.h>

using namespace std;
void displayGraph(map<int,vector<int>> adjList)
{
    for(auto ele:adjList)
    {
        cout<<ele.first<<"---> ";
        for(auto ele2:ele.second)
        {
            cout<<ele2<<" ";
        }
        cout<<"\n";
    }
}
vector<int>dfs( map<int,vector<int>> adjList, int src)
{
    stack<int> stck;
    map<int,bool> visited;
    vector<int> output;
    output.push_back(src);
    for(auto ele:adjList)
    {
        visited[ele.first]=false;
    }
    visited[src]=true;
    stck.push(src);
    while(!stck.empty())
    {
        int node=stck.top();
        
        stck.pop();
        for(auto ele:adjList[node])
        {
            if(visited[ele]==false)
            {
                visited[ele]=true;
                output.push_back(ele);
                stck.push(ele);
            }
        }
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
        adjList[y].push_back(x);
    }
    vector<int> output=dfs(adjList,1);
    for(auto ele:output)
    {
        cout<<ele<<" ";
    }
    //displayGraph(adjList);
}