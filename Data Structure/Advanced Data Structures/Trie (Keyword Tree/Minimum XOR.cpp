/*
=====================
|  ID:   mshafqats  |
|  LANG: C++        |
=====================
Mohammad Shafqat Siddiqui
*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
 
struct node{
    node *child[2];
	int freq;
    node(){
		freq=0;
        child[0]=NULL;
        child[1]=NULL;
    }
};
 
void insert(node *root, int x){
    for(int i=62;i>=0;i--){
        int bit=(x>>i) & 1ll;
        if(root->child[bit]){
            root=root->child[bit];
        }
        else{
            root->child[bit]=new node();
            root=root->child[bit];
        }
		root->freq++;
    }
}
 
int kthXor(node *root, int k, int x){
    int ans = 0;
	int add = 0;
	for(int i=62;i>=0;i--){
		int bit = (x>>i) & 1ll;
		if(root->child[bit]){
			if(root->child[bit]->freq+add>=k){
				root = root->child[bit];
			}
			else{
				add+=root->child[bit]->freq;
	    		ans |= (1ll<<i);
	    		root = root->child[bit^1];
        	} 
        }
        else{
	    	ans |= (1ll<<i);
	    	root = root->child[bit^1];
        }
	}
    return ans;
}
 
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	node *root= new node();
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int x;
			cin>>x;
			insert(root,x);
		}
		else{
			int x,k;
			cin>>x>>k;
			cout<<kthXor(root,k,x)<<'\n';
		}
	}
	return 0;
}
