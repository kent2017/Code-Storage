#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-7;
int n;
long double ans[114],a[114][514];
void debug(){
	cerr<<fixed<<setprecision(3);
	cerr<<"n="<<n<<endl; 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n+1;++j){
			cerr<<a[i][j]<<"\t";
		}
		cerr<<endl;
	}
}
int gsxy(){
	for(int i=1,i2=1;i<=n&&i2<=n;++i2){
		long double maxn=fabs(a[i][i2]);int id=i;
		for(int j=i;j<=n;++j){
			if(fabs(a[j][i2])>maxn){
				maxn=fabs(a[j][i2]);id=j;
			}
		}
//		long double minn=fabs(a[i][i]);id=i;
//		for(int j=i;j<=n;++j){
//			if(fabs(a[j][i])<minn&&a[j][i]!=0){
//				minn=fabs(a[j][i]);id=j;
//			}
//		}
		debug();
		if(fabs(maxn)<eps){
			continue;
		}
//		cerr<<minn<<" ";
		cerr<<maxn<<" ";
		cerr<<id<<endl;
		for(int j=1;j<=n+1;++j){
			swap(a[i][j],a[id][j]);
		}
		for(int j=i+1;j<=n;++j){
			long double bl=1.0*a[j][i2]/a[i][i2];
			cerr<<endl<<bl<<endl;
			for(int k=i2;k<=n+1;++k){
				cerr<<a[j][k]<<" "<<bl*a[i][k]<<" mark\n";
				a[j][k]-=bl*a[i][k];
			}
		}
		++i;
	}
	debug();
	int awa=0;
	for(int i=1;i<=n;++i){
		int is0=1;
		for(int j=1;j<=n;++j){
			if(fabs(a[i][j])>eps){
				is0=0;
				break;
			}
		}
		if(is0){
			if(fabs(a[i][n+1])>eps){
				return -1;
			}else{
				awa=1;
			}
		}
	}
	if(awa){
		return 1;
	}
	for(int i=n;i>0;--i){
		ans[i]=1.0*a[i][n+1]/a[i][i];
		for(int j=1;j<=n;++j){
			a[j][n+1]-=a[j][i]*ans[i];
			a[j][i]=0;
		}
	}
	return 0;
}
int main(){
	for(int i=0;i<114;++i){
		ans[i]=114514;
	}
	freopen("gsxy.err","w",stderr);
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n+1;++j){
			cin>>a[i][j];
		}
	}
	int t=gsxy();
	if(t){
		if(t==-1){
			cout<<-1<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		cout<<"x"<<i<<"=";
		cout<<fixed<<setprecision(2);
		if(fabs(ans[i])<0.001){
			cout<<"0.00\n";
		}else{
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}

