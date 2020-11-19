#include <bits/stdc++.h>
using namespace std;

void create (int st[],int v[],int low,int high, int pos ){
    cout<<low<<" "<<high<<endl;
    if(low==high){
        st[pos]=v[low];
        return;
    }
    int mid = (high+low)/2;
    create(st,v,low,mid,pos*2+1);
    create(st,v,mid+1,high,pos*2+2);
    st[pos]=min(st[pos*2+1],st[pos*2+2]);
    

}

int range_min_query(int st[],int ql, int qh,int l, int h, int root){
    if(ql <=l && qh >= h )return root;
    if (ql>h || qh <l) return 1000000;
    int m =(l+h)/2;
    int left = range_min_query(st, ql, qh, l, m, 2*root+1);
    int right = range_min_query(st, ql, qh, m+1, h, 2*root+2);
    return min(left, right);
}


int main(){
    int v[4]={-1,2,4,0};
    int st[7]={0,0,0,0,0,0,0};
    create(st,v,0,3,0);
    for(int i=0;i<7;i++){
        cout<<st[i]<<" ";
    }cout<<endl;
    cout<<range_min_query(st,0,6,1,3,0)<<endl;
}


