 #include<bits/stdc++.h>

 using namespace std;
 int indexOfMaxElementOftheGivenColumn(vector<vector<int>> mat,int columnNum)
    {
        int n=0;
        n=mat.size();
        int max=INT_MIN,maxIndex=-1;
        int start=0,end=n-1;
        int mid;
        while(start<=end)
        {
            mid=(start+end)/2;
            // cout<<"@"<<start<<"$$"<<end<<"\n";
            // cout<<mat[mid][columnNum]<<"--"<<mat[mid+1][columnNum]<<"\n";
            if(mid==0)
            {
               
                if(mat[mid][columnNum]>mat[mid+1][columnNum])
                    return mid;
            }
            if(mid==n-1)
            {
                if(mat[mid][columnNum]>mat[mid-1][columnNum])
                    return mid;
            }
            if(mat[mid][columnNum]<mat[mid+1][columnNum])
            {
                 //cout<<"**";
                start=mid+1;
            }
            
           
            
            else if(mat[mid][columnNum]<mat[mid-1][columnNum])
            {
                end=mid-1;
            }
            
            else//(mat[mid][columnNum]>mat[mid+1][columnNum] && mat[mid][columnNum]>mat[mid-1][columnNum] )
            {
                return mid;
            }
            
        }
        cout<<mat[maxIndex][columnNum]<<"@";
        return mid;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int rows=mat.size();
        int columns=mat[0].size();
        int start=0,end=columns-1;
        int mid,maxIndex;
        int i=0;
        while(start<=end)
        {
            mid=(start+end)/2;
            // cout<<mid<<"#\n";
            maxIndex= indexOfMaxElementOftheGivenColumn(mat,mid);//maxIndexOfTheMidElement
            // if(mat[maxIndex][mid]==14)
            //         cout<<"@@";
            if(mid==0)
            {
                
                if(mat[maxIndex][mid]>mat[maxIndex][mid+1])
                {
                    return {maxIndex,mid};
                }
            }
            else if(mid==columns-1)
            {
                
                if(mat[maxIndex][mid]>mat[maxIndex][mid-1])
                {
                    return {maxIndex,mid};
                }
            }
            else
            {
                
                if(mat[maxIndex][mid]<mat[maxIndex][mid+1])
                {
                    start=mid+1;
                }
                else if(mat[maxIndex][mid]<mat[maxIndex][mid-1])
                {
                    end=mid-1;
                }
                else
                {
                    return{maxIndex,mid};
                }
            }
            
        }
        return {maxIndex,mid};
        
    }
    int main()
    {
        vector<vector<int>> nums;
        for(int i=0;i<2;++i)
        {
            int x, y,z;
            cin>>x>>y>>z;
            nums.push_back({x,y,z});
        }
        auto ans=findPeakGrid(nums);
        for(auto ele:ans)
        {
            cout<<ele<<" ";
        }

    }