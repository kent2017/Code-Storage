#include<bits/stdc++.h>
using namespace std;
int nxt[1000001],len1,len2,head=1;
bool istrue=0;
int main(){
	string a,b;
	cin>>a>>b;
	len1=a.length();len2=b.length();
	a=" "+a;b=" "+b;
	for(int i=2;i<=len2;++i){
		int pos;
		for(pos=i-1;b[i]!=b[nxt[pos]+1]&&pos;pos=nxt[pos]);
		if(pos!=0){
			nxt[i]=nxt[pos]+1;
		}else{
			nxt[i]=0;
		}
	}
	for(int i=1,j=1;i<=len1;){
		if(b[j]==a[i]){
			++i;++j;
		}else if(j>1){
			j=nxt[j-1]+1;
		}else{
			++i;
		}
		if(j==len2+1){
			istrue=1;
			cout<<i-len2<<endl;
			j=nxt[j-1]+1;
			i-=len2-j;
		}
	}
	for(int i=1;i<=len2;++i){
		cout<<nxt[i]<<" ";
	}
	return 0;
}
