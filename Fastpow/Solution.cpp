#include<bits/stdc++.h>
using namespace std;
template<typename T>T Identity_element(const T& base);
template<> inline int Identity_element<int>(const int&) { return (int)1; }
template<> inline long long Identity_element<long long>(const long long&) { return (long long)1; }
template<> inline unsigned Identity_element<unsigned>(const unsigned&) { return (unsigned)1; }
template<> inline unsigned long long Identity_element<unsigned long long>(const unsigned long long&) { return (unsigned long long)1; }
template<> inline float Identity_element<float>(const float&) { return (float)1; }
template<> inline double Identity_element<double>(const double&) { return (double)1; }
template<> inline long double Identity_element<long double>(const long double&) { return (long double)1; }
long long mod,a,b;
template<class T> T fastpow(T Base, long long index) {//只需有*运算符,%运算符,和自定义的Identity_element函数即可使用
	T tans=Identity_element(Base),fans=Base;
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
