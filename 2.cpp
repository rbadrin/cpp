#include<iostream>
#include<vector>
#include<math.h>
#include<stack>
#include<string>
#include<set>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<bitset>
#include<map>
#include<climits>
#define lld long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
#define mod 1000000007

vector<int> b(35,0);
void incr(int x){
  int k=0;
  while(x){
    if(x&1)
      b[k]++;
    k++;
    x=x>>1;
  }
}

int solve(){
  vector<int> a;
  a.insert(a.end(), 5, 1);
  for(auto it : a) cout<<it<<" ";

}
int main(){
  solve();
}
