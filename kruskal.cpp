#include<bits/stdc++.h>

using namespace std;

class DisJointUnion
{

public:

    vector<int> rootArray;
    DisJointUnion(int size)
    {
        rootArray=vector<int>(size);
        for(int i=0;i<size;++i)
        {
            rootArray[i]=i;
        }
    }

    int find(int node)
    {
        return rootArray[node];
    }

    void unionF(int x, int y)
    {
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY)
        {
            for(int i=0;i<rootArray.size();++i)
            {
                if(rootArray[i]==rootY)
                {
                    rootArray[i]=rootX;
                }
            }
        }
    }

    bool isConnected(int x, int y)
    {   
        // cout<<find(x)<<find(y)<<"@@";
        return find(x)==find(y);
    }
};

int kruskal(vector<pair<int,pair<int,int>>> weightedGraph)
{
    int minCost=0;
    sort(weightedGraph.begin(),weightedGraph.end());
    DisJointUnion d=DisJointUnion(4);
    for(auto edge:weightedGraph)
    {
        // cout<<edge.second.first<<" -- "<<edge.second.second<<" == "<<edge.first<< endl;
        if(d.isConnected(edge.second.first,edge.second.second)==false)
        {
            cout<<edge.second.first<<" -- "<<edge.second.second<<" == "<<edge.first<< endl;
            minCost=minCost+edge.first;
            d.unionF(edge.second.first,edge.second.second);
        }
    }
    return minCost;
}
int main()
{
    int noOfEdges;
    cin>>noOfEdges;
    vector<pair<int,pair<int,int>>> weightedGraph;
    for(int i=0;i<noOfEdges;++i)
    {
        int src, dest, weight;
        cin>>src>>dest>>weight;
        weightedGraph.push_back({weight,{src,dest}});
    }
    int ans=kruskal(weightedGraph);
    cout<<ans;
return 0;
}