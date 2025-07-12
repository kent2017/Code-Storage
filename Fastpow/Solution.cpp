#include<bits/stdc++.h>
using namespace std;
long long mod,a,b;
template<class T> T fastpow(T Base, long long index) {
	T tans=1,fans=Base;
	for(long long i=1;i<=index;i<<=1){
		if(i&index){
			tans=(tans*fans)%mod;
		}
		fans=(fans*fans)%mod;
	}
	return tans;
}
int main(){
	cin>>a>>b>>mod;
	cout<<a<<"^"<<b<<" mod "<<mod<<"="<<fastpow(a,b)<<endl;
	return 0;
}
