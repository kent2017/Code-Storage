#include<bits/stdc++.h>
using namespace std;
string a="##";
int l,r=-1,d[22000002],ans=-1,cnt;
inline void write(int x){
    if(x>9){
    	write(x/10);
	}	
    putchar(x%10+'0');
}
void manacher(string x){
	string a="##";
	for(int i=0;i<x.length();++i){
		a+=x[i];a+='#';
	}
	for(int i=1;i+ans<a.length();++i){
		for(cnt=(i>r)?1:min(d[l+r-i],r-i+1);i-cnt+1>0&&i+cnt-1<a.length();++cnt){
			if(a[i-cnt+1]!=a[i+cnt-1]){
				break;
			}
		}
		d[i]=cnt-1;
		if(i+d[i]-1>r){
			l=i-cnt+1;r=i+cnt-1; 
		}
		ans=max(ans,d[i]);
	}
}
int main(){
	string x;cin>>x;
	manacher(x);
	write(ans-1);
	return 0;
}
