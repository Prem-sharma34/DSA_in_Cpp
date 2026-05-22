#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>

using namespace std;


vector<int> nge(vector<int>&a, vector<int>&b)
{
  unordered_map<int,int>mpp;
  stack<int>st;

  for(int i = b.size() -1 ; i >= 0 ; i--)
  {
      while(!st.empty() && b[i] >= st.top())
      {
        st.pop();
      }

      if(st.empty())
      {
        mpp[b[i]] = -1;
      }
      else 
      {
        mpp[b[i]] = st.top();
      }

      st.push(b[i]);

  }


      vector<int>ans(a.size());

      for(int i = 0 ; i < a.size() ; i++)
      {
        ans[i] = mpp[a[i]];
      }

      return ans;
}


int main()
{
  vector<int>a = {1,4,2};

  vector<int> b = {1 , 3 , 5 , 4 , 2 };

  vector<int>ans = nge(a , b);

  for(auto i : ans) 
  {
    cout<<i<<" ";
    
  }

  cout<<endl;
}
