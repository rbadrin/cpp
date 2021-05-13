#include<iostream>
#include<vector>
#include<math.h>
#include<stack>
#include<string>
#include<set>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<map>
#include<climits>
#define lld long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
map<char,vector<pair<char,int> > > a;
int insert(char from ,char to, int path){
  a[from].push_back(make_pair(to,path));
}
int ispath(char from,char to){
  for(auto it=a[from].begin();it!=a[from].end();it++){
    if(it->first==to)
      return it->second;
  }
  return -1;
}
map<char,bool> visted;
vector<char>  ans;
void dfs(char p){
    for(auto it1=a[p].begin();it1!=a[p].end();it1++){
      if(visted[it1->first]==false){
        visted[it1->first]=true;
        ans.push_back(it1->first);
        dfs(it1->first);
      }
    }
}
queue<char> ans1;
void bfs(char p){
    for(auto it1=a[p].begin();it1!=a[p].end();it1++){
      if(visted[it1->first]==false){
        visted[it1->first]=true;
        ans1.push(it1->first);
        ans.push_back(it1->first);
      }
    }
    char c=ans1.front();
    if(ans1.size()==0)
      return ;
    ans1.pop();
    bfs(c);
}
int  main(){
  char from,to,path;
  insert('a','b',4);
  insert('a','p',4);
  insert('a','q',4);
  insert('b','c',7);
  // insert('c','a',7);
  insert('c','e',7);
  insert('a','d',15);
  for(char p='a';p<'z';p++){
    visted[p]=false;
  }
  visted['c']=true;
  ans.push_back('c');
  dfs('c');
  // bfs('a');

  for(auto it : ans)
    cout<<it<<" ";

  // cout<<ispath('d','c')<<endl;
  // cout<<ispath('d','a')<<endl;
  // allpath();

}
