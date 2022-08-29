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
        return find(x)==find(y);
    }
};

int main()
{
    DisJointUnion d=DisJointUnion(5);
    int noOFEdges;
    cin>>noOFEdges;
    for(int i=0;i<noOFEdges;++i)
    {
        int src,dest;
        cin>>src>>dest;
        if(d.isConnected(src,dest))
        {
            cout<<"cycle Detected";
            return 0;
        }
        else
        {
            d.unionF(src,dest);
        }
    }
    cout<<"no cycle Detected";
    return 0;
}
