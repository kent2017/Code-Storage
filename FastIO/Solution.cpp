
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
template<typename T> typename std::enable_if<std::is_floating_point<T>::value>::type output(T x, int precision){
    if(x<0) putchar('-'), x=-x;
    long long int_part = static_cast<long long>(x);
    output(int_part);
    if(precision==0) return;
    putchar('.');
    x-=int_part;
    long long frac=static_cast<long long>(x*pow(10,precision)+0.5);
    output(frac);
}
template<> inline void read</*Your type*/>(/*Your type*/ &x) {
	//Your code
}
template<> inline void output</*Your type*/>(const /*Your type*/ &x) {
	//Your code
}
int main(){
	
	return 0;
}
