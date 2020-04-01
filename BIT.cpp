#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
using namespace std;
const int N=1e5+50;
const int mod=1e9+7;

int tree[N];
void update(int n, int idx, int val){
	while(idx <= n){
		tree[idx] += val;
		idx += (idx & (-idx));
	}
}

int query(int idx){
	int sum = 0;
	while(idx > 0){
		sum += tree[idx];
		idx -= (idx & (-idx));
	}
	return sum;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll tc=1;
	for(ll T=1; T<=tc;T++){
		int n; cin>>n;
		int a;
		for(int i=1; i<=n; i++){
			cin>>a;
			update(n, i, a);
		}
		int q; cin>>q;
		while(q--){
			int op; cin>>op;
			if(op == 1){
				int l,r; cin>>l>>r;
				int res = query(r) - query(l-1);
				cout<<res<<"\n";
			}
			else{
				int idx, val; cin>>idx>>val;
				update(n, idx, val);
			}
		}
	}
	return 0;
}
