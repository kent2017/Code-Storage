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
const int mod=1e9+7;
struct Matrixs{
	int matrix_rows,matrix_columns;
	long long matrix[150][150]={};
	Matrixs operator*(const Matrixs& Matrix2){
		Matrixs Result_matrix,Matrix1=*this;
		memset(Result_matrix.matrix,0,sizeof(Result_matrix.matrix));
		if(Matrix1.matrix_columns!=Matrix2.matrix_rows){
			Result_matrix.matrix_columns=Result_matrix.matrix_rows=-2;
			return Result_matrix; 
		}
		Result_matrix.matrix_rows=Matrix1.matrix_rows;Result_matrix.matrix_columns=Matrix2.matrix_columns;
		for(int i=1;i<=Matrix1.matrix_rows;++i){
			for(int j=1;j<=Matrix2.matrix_columns;++j){
				for(int k=1;k<=Matrix2.matrix_rows;++k){
					Result_matrix.matrix[i][j]+=Matrix1.matrix[i][k]*Matrix2.matrix[k][j];
					Result_matrix.matrix[i][j]%=mod;
				}
			}
		}
		return Result_matrix;
	}
	Matrixs operator%(const int& b){
		Matrixs Result_matrix=*this;
		for(int i=1;i<=Result_matrix.matrix_rows;++i){
			for(int j=1;j<=Result_matrix.matrix_columns;++j){
				Result_matrix.matrix[i][j]%=b;
			}
		}
		return Result_matrix;
	}
	void print(){
		for(int i=1;i<=this->matrix_rows;++i){
			for(int j=1;j<=this->matrix_columns;++j){
				cout<<this->matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
template<> inline Matrixs Identity_element<Matrixs>(const Matrixs& t){
	int level=t.matrix_rows;
	Matrixs Result_matrix;Result_matrix.matrix_columns=Result_matrix.matrix_rows=level;
	for(int i=1;i<=level;++i){
		Result_matrix.matrix[i][i]=1;
	}
	return Result_matrix;
}
template<class T>T fastpow(T Base,long long index){
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
	Matrixs a,res;long long index;
	cin>>a.matrix_rows>>index;a.matrix_columns=a.matrix_rows;
	for(int i=1;i<=a.matrix_rows;++i){
		for(int j=1;j<=a.matrix_columns;++j){
			cin>>a.matrix[i][j];
		}
	}
	res=fastpow(a,index);
	for(int i=1;i<=res.matrix_rows;++i){
		for(int j=1;j<=res.matrix_columns;++j){
			cout<<res.matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
