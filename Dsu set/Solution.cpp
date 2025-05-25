#include<bits/stdc++.h>
using namespace std;
struct dsu{
	int fa[200001];
	int getfa(int x){
		if(fa[x]!=x){
			fa[x]=getfa(fa[x]);
		}
		return fa[x];
	}
	bool same(int x,int y){
		return getfa(x)==getfa(y);
	}
	void merge(int x,int y){
		if(!same(x,y)){
			int xf=getfa(x),yf=getfa(y);
			fa[xf]=yf;
		}
	}
	void clear(){
		for(int i=1;i<=200000;++i){
			fa[i]=i;
		}
	}
}kent2017;
int main(){
    kent2017.clear();
    int n,m;
	cin>>n>>m;++m;
	for(;--m;){
		int x,y,z;
		cin>>z>>x>>y;
		if(z==1){
			kent2017.merge(x,y);
		}else{
			puts(kent2017.same(x,y)?"Y":"N");
		}
	}
	return 0;
} 
