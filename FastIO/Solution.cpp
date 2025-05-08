#include<bits/stdc++.h>
using namespace std;
int input(){
    char ch=getchar();int f=1,val=0;
    for(;ch!='-'&&(ch>'9'||ch<'0');ch=getchar());
    if(ch=='-'){f=-1;ch=getchar();}
    for(;ch<='9'&&ch>='0';ch=getchar()){
		val*=10;val+=ch-'0';
    }
    return val*f;
}
void output(int x){
	if(x<0){x*=-1;putchar('-');}
	if(!x){putchar('0');return; }
	int cnts[50],cnt=0;
	for(;x;x/=10,++cnt){cnts[cnt]=x%10;}
	for(int i=cnt-1;i>=0;--i){putchar('0'+cnts[i]);}
	return;
} 
int main(){
	
	return 0;
}
