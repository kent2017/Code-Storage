#include<bits/stdc++.h>
using namespace std;
long long mod;
long long fastpow1(long long Base,long long index){
	long long tans=1,fans=Base;
	for(long long i=1;i<=index;i<<=1){
//		cout<<fans<<" "<<tans<<" "<<i<<" "<<(i&index)<<endl;
		if(i&index){
			tans*=fans;
		}
		tans%=mod;fans*=fans;fans%=mod;
	}
	return tans%mod;
} 
long long fastpow2(long long Base,int index){
	if(index==1){
		return Base;
	}
	if(index==0){
		return 1;
	}
	long long a=fastpow(Base,index/2)%p;
	long long s=(a*a)%p;
	if(index%2){
		return s*Base%p;
	}else{
		return s;
	}
} 
int main(){
//	freopen("a.out","w",stdout);
	long long a,b;
	cin>>a>>b>>mod;
	cout<<a<<"^"<<b<<" mod "<<mod<<"="<<fastpow1(a,b);
	return 0;
}
