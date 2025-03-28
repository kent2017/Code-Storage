#include<bits/stdc++.h>
using namespace std;
long long p=2,fact[1000001];
void init(){
	fact[0]=1;
	for(long long i=1;i<=1000000;++i){
		fact[i]=(1LL*fact[i-1]*i)%p;
	}
}
long long fastpow(long long Base,long long index){
	long long tans=1,fans=Base;
	for(long long i=1;i<=index;i<<=1){
		if(i&index){
			tans*=fans;
		}
		tans%=p;fans*=fans;fans%=p;
	}
	return tans;
}
long long C(long long n,long long m){
	if(m>n){
		return 0;
	}
	return 1LL*((fact[n]*fastpow(fact[m],p-2))%p*fastpow(fact[n-m],p-2))%p;
}
long long Lucas(long long n,long long m){
	if(m==0){
		return 1;
	}
	long long c=C(n%p,m%p),lu=Lucas(n/p,m/p);
	return c*lu%p;
} 
int main(){
	
	return 0;
}
