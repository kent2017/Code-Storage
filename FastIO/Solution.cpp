#include<bits/stdc++.h>
using namespace std;
// int input(){
//     char ch=getchar();int f=1,val=0;
//     for(;ch!='-'&&(ch>'9'||ch<'0');ch=getchar());
//     if(ch=='-'){f=-1;ch=getchar();}
//     for(;ch<='9'&&ch>='0';ch=getchar()){val*=10;val+=ch-'0';}
//     return val*f;
// }
// void output(int x){
// 	if(x<0){x*=-1;putchar('-');}
// 	if(!x){putchar('0');return; }
// 	int cnts[50],cnt=0;
// 	for(;x;x/=10,++cnt){cnts[cnt]=x%10;}
// 	for(int i=cnt-1;i>=0;--i){putchar('0'+cnts[i]);}
// 	return;
// } 
#include<bits/stdc++.h>
using namespace std;
template<typename T> typename std::enable_if<std::is_integral<T>::value>::type input(T &x){
    x=0;bool f=0;char c=getchar();
    for(;c!='-'&&(c<'0'||c>'9');c=getchar());
    if(c=='-')f=1,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
    if(f)x=-x;
}
template<typename T> typename std::enable_if<std::is_floating_point<T>::value>::type input(T &x){
    x=0;bool f=0;char c=getchar();
    for(;c!='-'&&c!='.'&&(c<'0'||c>'9');c=getchar());
    if(c=='-')f=1,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())x=x*10+(c-'0');
    if(c=='.'){
        T base=0.1;
        for(c=getchar();c>='0'&&c<='9';c=getchar(),base*=0.1)x+=base*(c-'0');
    }
    if(f)x=-x;
}
template<typename T> typename std::enable_if<std::is_integral<T>::value>::type output(T x){
    if(x==0){putchar('0');return;}
    if(x<0)putchar('-'),x=-x;
    char buf[21];int pos=0;
    for(;x;x/=10)buf[pos++]=x%10+'0';
    for(;pos--;)putchar(buf[pos]);
}
template<typename T> typename std::enable_if<std::is_floating_point<T>::value>::type output(T x,int precision){
    if(x<0)putchar('-'),x=-x;
    long long int_part=static_cast<long long>(x);
    output(int_part);
    putchar('.');
    x-=int_part;
    for(int i=0;i<precision;++i){
        x*=10;
        putchar(int(x)%10+'0');
        x-=int(x);
    }
}
template<> inline void read</*Your type*/>(/*Your type*/ &x) {
    //Your code
}
template<> inline void output</*Your type*/>(const /*Your type*/ &x) {
	//Your code

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	return 0;
}
