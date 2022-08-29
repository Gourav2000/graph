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
void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}
vector<int> bfs(map<int,vector<int>> adjList, int src)
{
    queue<int> q;
    q.push(src);
    vector<int> output;
    map<int,bool> visited;
    vector<int> currentPath;
    vector<vector<int>> allPaths;
    //currentPath.push_back(src);
    output.push_back(src);
    for(auto ele:adjList)
    {
        visited[ele.first]=false;
    }
    visited[src]=true;
    while(!q.empty())
    {
        int node=q.front();
       
        for(auto ele: adjList[node])
        {
            
            if(visited[ele]==false)
            {
                visited[ele]=true;
               
                output.push_back(ele);
                q.push(ele);
                
            }
        }
        q.pop();
        cout<<"at node"<<node<<"--->";
                showq(q);
                cout<<"\n";
        
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
    //displayGraph(adjList);
    vector<int> output=bfs(adjList,1);
    for(auto ele:output)
    {
        cout<<ele<<" ";
    }
    return 0;
}