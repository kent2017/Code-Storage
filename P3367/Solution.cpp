#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int fa[N],n,m;
int getfa(int x){
	if(fa[x]!=x){
		fa[x]=getfa(fa[x]);
	}
	return fa[x];
}
void mer(int x,int y){
	int xf=getfa(x),yf=getfa(y);
	if(xf!=yf){
		fa[xf]=fa[yf];
	}
	return ;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		fa[i]=i;
	}
	for(;m--;){
		int x,y,z;
		scanf("%d%d%d",&z,&x,&y);
		if(z==1){
			mer(x,y);
		}else{
			if(getfa(x)==getfa(y)){
				printf("Y");
			}else{
				printf("N");
			}
			cout<<endl;
		}
	}
	return 0;
} 
