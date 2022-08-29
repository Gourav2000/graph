#include<bits/stdc++.h>
using namespace std;
int indexOfNodeAtMInDistance(vector<int> &dist,  vector<bool> &visited)
{
    int min=INT_MAX;
    int minIndex=-1;
    int i=0;
    
    for(auto ele:dist)
    {
        if(visited[i]==false && ele<min)
        {
            min=ele;
            minIndex=i;
        }
        ++i;
    }
    //cout<<"minIndex="<<minIndex<<endl;
    return minIndex;
}
vector<int> disjktra(int src,vector<vector<pair<int,int>>> graph)
{
    vector<int> dist(graph.size(),INT_MAX);
    vector<bool> visited(graph.size(),false); 
    dist[src]=0;
    for(int i=0;i<graph.size()-1;++i)
    {
        
        int minIndex=indexOfNodeAtMInDistance(dist,visited);
        if(minIndex==-1)
            break;
        visited[minIndex]=true;
        
        for(auto ele2:graph[minIndex])
        {
           if(dist[ele2.second]>ele2.first + dist[minIndex])
           {
               dist[ele2.second]=ele2.first+dist[minIndex];
           }

        }
        int j=0;
        for(auto ele:dist)
        {
            cout<<"d of "<<j<<" is-- "<<ele<<endl;
            ++j;
        }
        cout<<"###\n";
         
    }
    
    return dist;
}
int main()
{
    vector<vector<pair<int,int>>> graph;
    int noOfEdges;
    cin>>noOfEdges;
    graph=vector<vector<pair<int,int>>>(noOfEdges);
    for(int i=0;i<noOfEdges;++i)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        graph[src].push_back({weight,dest});
        graph[dest].push_back({weight,src});
    }
    auto dist=disjktra(0,graph);
    int i=0;
    for(auto ele:dist)
    {
        if(ele!=INT_MAX)
            cout<<"the distance of src from vertex "<<i<<"is--"<<ele<<'\n';
        ++i;
    }
    return 0;

}