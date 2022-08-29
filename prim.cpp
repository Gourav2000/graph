#include<bits/stdc++.h>
//incorrect and incomplete love and lies
using namespace std;
int prim(vector<pair<int,pair<int,int>>> edgeList)
{
    int minCost=0;
    priority_queue<pair<int,pair<int,int>>> pq;
    vector<bool> visited(5,false);
    int verticeCount=4;
    visited[0]=true;
    for(auto edge:edgeList)
    {
        pq.push({edge.first,{edge.second.first,edge.second.second}});
    }
    while(pq.empty()==false && verticeCount>0)
    {
        auto edge=pq.top();
        pq.pop();
        int src=edge.second.first;
        int dest=edge.second.second;
        int weight=edge.first;
        if(visited[dest]==false)
        {
            visited[dest]=true;
            minCost=minCost+weight;
            verticeCount--;
        }
    }
    return minCost;
}
int main()
{
    int noOfEdges;
    cin>>noOfEdges;
    vector<pair<int,pair<int,int>>> edgeList;
    for(int i=0;i<noOfEdges;++i)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        edgeList.push_back({weight,{src,dest}});
    }
    int minCost=prim(edgeList);
    cout<<minCost;
    return 0;
}