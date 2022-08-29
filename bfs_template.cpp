#include<bits/stdc++.h>
using namespace std;
bool cond(vector<vector<int>>& A,int x,int y,int n,int m){
	return (x>=0 && y>=0 && x<n && y<m && A[x][y]==0);
}
long long minLength (int N, int M, int Q, vector<vector<int> > query, int r, int c) {
   // Write your code here
   const int X[4]={-1,0,1,0};
   const int Y[4]={0,-1,0,1};
   vector<vector<int>> mat(N,vector<int>(M));
   for(auto ele:query)
   {
       if(ele[0]==1)
       {
           mat[ele[1]-1][ele[2]-1]=1;
       }
   }
   queue<pair<int,int>> q;
   vector<vector<bool>> visited(N,vector<bool>(M));
    q.push({r-1,c-1});
   vector<vector<int>> dis(N,vector<int>(M,INT_MAX));
   dis[r-1][c-1]=0;
   while(!q.empty())
   {
       auto x=q.front();
       int index1=x.first;
       int index2=x.second;
       for(int l=0;l<4;++l)
       {
           int in1=index1+X[l];
           int in2=index2+Y[l];
           if(cond(mat,in1,in2,N,M) && !visited[in1][in2] )
            {
                q.push({in1,in2});
                visited[in1][in2]=true;
                dis[in1][in2]=dis[index1][index2]+1;
            }

       }
       q.pop();
       
   }
   if(dis[N-1][M-1]==INT_MAX)
        return -1;
    return dis[N-1][M-1];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        int Q;
        cin >> Q;
        vector<vector<int> > query(Q, vector<int>(3));
        for (int i_query = 0; i_query < Q; i_query++)
        {
        	for(int j_query = 0; j_query < 3; j_query++)
        	{
        		cin >> query[i_query][j_query];
        	}
        }
        int r;
        cin >> r;
        int c;
        cin >> c;

        long long out_;
        out_ = minLength(N, M, Q, query, r, c);
        cout << out_;
        cout << "\n";
    }
}