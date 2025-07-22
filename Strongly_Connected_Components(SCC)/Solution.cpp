#include<bits/stdc++.h>
using namespace std;
const int N=10004;
const int M=100005;
int n,h[N],cntedge,m,inv[N],w[N],val[N],dp[N],cntnode,ans;
int dfn[N],low[N],cntdfn,sta[N],top,sz[N],scc[N],sccnt;
bitset<N>in_stack;
set<pair<int,int>>edge2;
queue<int>que;
struct Edge{
	int to,nxt,from;
}edge[M*2];
void add(int u,int v){
	edge[++cntedge].to=v;
	edge[cntedge].from=u;
	edge[cntedge].nxt=h[u];
	h[u]=cntedge;
}
void dfs(int now){
	low[now]=dfn[now]=++cntdfn;sta[++top]=now;
	in_stack[now]=1;
	for(int i=h[now];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(!dfn[v]){
			dfs(v);
			low[now]=min(low[now],low[v]);
		}else if(in_stack[v]){
			low[now]=min(low[now],dfn[v]);
		}
	}
	if(dfn[now]==low[now]){
		++sccnt;
		do{
			scc[sta[top]]=sccnt;
			++sz[sccnt];
			in_stack[sta[top]]=0;
		}while(sta[top--]!=now);
	}
}
int/*signed*/ main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
	for(int i=1;i<=m;++i){
		int a,b;
		cin>>a>>b;
		add(a,b);
    	}
	for(int i=1;i<=n;++i){
		if(!dfn[i]){
			dfs(i);
		}
	}
	for(int i=1;i<=cntedge;++i){
		if(scc[edge[i].from]==scc[edge[i].to]){
			continue;
		}
		edge2.insert(make_pair(scc[edge[i].from],scc[edge[i].to]));
		edge[i].from=edge[i].to=edge[i].nxt=0;
	}
	for(int i=1;i<=n;++i){
		h[i]=0;
	}
	for(auto it=edge2.begin();it!=edge2.end();it++){
		pair<int,int>x=*it;
		add(x.first,x.second);++inv[x.second];
	}
	return 0;
}
