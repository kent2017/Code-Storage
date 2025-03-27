#include<bits/stdc++.h> 
using namespace std;
int a[3000010],n,st[3000010],top=0,ans[3000010];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=n;i>0;--i){
		for(;a[i]>=a[st[top]]&&top;){
			--top;
		}
		ans[i]=st[top];
		st[++top]=i;
	}
	for(int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
