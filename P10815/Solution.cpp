#include<bits/stdc++.h>
using namespace std;
#define getchar getchar_unlocked
//It is non-thread-safe and should be used with caution
int read(){
    char ch=getchar();
    int f=1,val=0;
    for(;ch!='-'&&(ch>'9'||ch<'0');ch=getchar());
    if(ch=='-'){f=-1;ch=getchar();}
    for(;ch<='9'&&ch>='0';ch=getchar()){
        val*=10;val+=ch-'0';
    }
    return val*f;
}
void write(int x){
	if(x<0){
		x*=-1;putchar('-');
	}
	int cnts[50],cnt=0;
	for(;x;x/=10,++cnt){
		cnts[cnt]=x%10;
	}
	for(int i=cnt-1;i>=0;--i){
		putchar('0'+cnts[i]);
	}
	return;
} 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n=read(),k=read();
    for(;--n;){
        k+=read();
    }
    write(k);
	return 0;
}

