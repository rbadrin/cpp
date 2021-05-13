#include<iostream>
#include<vector>
#include<math.h>
#include<stack>
#include<string>
#include<set>
#include<iomanip>
#include<algorithm>
#include <cstdio>
#include<queue>
#include<climits>
#define lld long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int change(int seg_tr[],int p,int val,int s,int e,int pos){
  if(s==e && s==p){
    seg_tr[pos]+=val;
    return 1;
  }
  int mid=(s+e)/2;
  if(p<=mid){
    seg_tr[pos]+=val;
    change(seg_tr,p,val,s,mid,2*pos+1);
  }
  else{
    seg_tr[pos]+=val;
    change(seg_tr,p,val,mid+1,e,2*pos+2);
  }
}
int getsum(int seg_tr[],int fs,int fe,int s,int e,int pos){
  if(fs<=s && fe>=e)
    return seg_tr[pos];
  if(fs>e || fe<s)
    return 0;
  int mid=(s+e)/2;
  return getsum(seg_tr,fs,fe,s,mid,2*pos+1)+getsum(seg_tr,fs,fe,mid+1,e,2*pos+2);
}

int intialize(int seg_tr[],int n){
  int p=log2(n)+1;
  n=(2*pow(2,p)-1);
  for(int i=0;i<(2*pow(2,p)-1);i++)
    seg_tr[i]=INT_MAX;
}
int create_segmenttree(int a[],int seg_tr[],int s,int e,int pos){
    if(s==e){
      seg_tr[pos]=a[s];
      return 1;
    }
    int mid=(s+e)/2;
    create_segmenttree(a,seg_tr,s,mid,2*pos+1);
    create_segmenttree(a,seg_tr,mid+1,e,2*pos+2);
    seg_tr[pos]=seg_tr[2*pos+1]+seg_tr[2*pos+2];
}
int main(){
  int a[5]={15,-2,27,50,7};
  int seg_tr[16];
  intialize(seg_tr,5);
  create_segmenttree(a,seg_tr,0,4,0);
  cout<<getsum(seg_tr,1,3,0,4,0)<<endl;
  change(seg_tr,2,0,0,4,0);
  for(int i=0;i<16;i++)
    cout<<seg_tr[i]<<" ";
  cout<<getsum(seg_tr,1,3,0,4,0)<<endl;
}
