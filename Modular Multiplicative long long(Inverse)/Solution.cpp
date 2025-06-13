#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
pair<long long,long long> ex_gcd(long long a,long long b){
    if(b==0) return make_pair(1,0);
    pair<long long,long long> qwq=ex_gcd(b,a%b);
    long long tx=qwq.first;
    qwq.first=qwq.second;
    qwq.second=tx-a/b*qwq.second;
    return qwq;
}
long long modinverse(long long base,long long mod1){
    pair<long long,long long> ans=ex_gcd(base,mod1);
    return (ans.first%mod1+mod1)%mod1;
}
struct mll{
    long long val;
    mll():val(0){}
    mll(long long v):val((v%mod+mod)%mod){}
    mll operator+(const mll& x)const{return mll(val+x.val);}
    mll operator-(const mll& x)const{return mll(val-x.val);}
    mll operator*(const mll& x)const{return mll(val*x.val);}
    mll operator/(const mll& x)const{return mll(val*modinverse(x.val,mod));}
    bool operator==(const mll& x)const{return (val%mod+mod)%mod==(x.val%mod+mod)%mod;}
    bool operator!=(const mll& x)const{return (val%mod+mod)%mod!=(x.val%mod+mod)%mod;}
    bool operator<(const mll& x)const{return (val%mod+mod)%mod<(x.val%mod+mod)%mod;}
    bool operator<=(const mll& x)const{return (val%mod+mod)%mod<=(x.val%mod+mod)%mod;}
    bool operator>(const mll& x)const{return (val%mod+mod)%mod>(x.val%mod+mod)%mod;}
    bool operator>=(const mll& x)const{return (val%mod+mod)%mod>=(x.val%mod+mod)%mod;}
    mll& operator+=(const mll& x){val=(val+x.val)%mod;return *this;}
    mll& operator-=(const mll& x){val=(val-x.val+mod)%mod;return *this;}
    mll& operator*=(const mll& x){val=(val*x.val)%mod;return *this;}
    mll& operator/=(const mll& x){val=(val*modinverse(x.val,mod))%mod;return *this;}
    mll operator-()const{return mll(-val);}
    mll& operator++(){val=(val+1)%mod;return *this;}
    mll operator++(int){mll temp=*this;++(*this);return temp;}
    mll& operator--(){val=(val-1+mod)%mod;return *this;}
    mll operator--(int){mll temp=*this;--(*this);return temp;}
    operator long long()const{return (val%mod+mod)%mod;}
    mll pow(long long exponent)const{
        mll res(1);mll base(*this);
        while(exponent>0){
            if(exponent%2==1) res*=base;
            base*=base;exponent/=2;
        }
        return res;
    }
    mll inv()const{return mll(modinverse(val,mod));}
};
istream& operator>>(istream& is,mll& x){
    long long v;is>>v;x=mll(v);return is;
}
ostream& operator<<(ostream& os,const mll& x){
    os<<(x.val%mod+mod)%mod;return os;
}
int main(){
	long long a,b;cin>>a>>b;
	cout<<modinverse(a,b)<<endl;
    return 0;
}
