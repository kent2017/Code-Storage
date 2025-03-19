#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000001]; 
void split(int left, int right) {//Edit in a Java ide,but it can run in C++ and Java
	int i = left, j = right, b;
	int d = left, C = a[d];
	while (j > i) {
		while ((a[j] >= C) && (j > i)) {
			j--;
		}
		while ((a[i] <= C) && (i < j)) {
			i++;
		}
		b = a[i];
		a[i] = a[j];
		a[j] = b;
	}
	b = a[d];
	a[d] = a[j];
	a[j] = b;
	if ((right > left) && (n > right)) {
		int l1 = left;
		int r1 = i - 1;
		int l2 = i + 1;
		int r2 = right;
		if (r1 < left) {
			r1 = left;
		}
		if (l2 > right) {
			l2 = right;
		}
		split(l1, r1);
		split(l2, r2);
	}
}
int main(){
	cin>>n;
	for (int k = 0; k < n; k++) {
		cin>>a[k];
	}
	split(0,n-1);
	for (int k = 0; k < n; k++) {
		cout<<a[k]<<" ";
	}
	cout<<endl;
	return 0;
}
