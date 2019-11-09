#include <bits/stdc++.h>

using namespace std;

int makeEqualLength(string &a, string &b) 
{ 
	int l1 = a.size(); 
	int l2 = b.size(); 
	if (l1 < l2) 
	{ 
		for (int i = 0 ; i < l2 - l1 ; i++) 
			a = '0' + a;
		return l2; 
	} 
	else if (l1 > l2) 
	{ 
		for (int i = 0 ; i < l1 - l2 ; i++) 
			b = '0' + b;
	}
	return l1;
}

string multiply(string a, string b){
	int len = makeEqualLength(a, b);
	char product[2*len];
	for (int i = 0; i < 2*len; i++)
		product[i] = '0';
	for (int i = len - 1; i >= 0; i--){
		int carry = 0;
		for (int j = len - 1; j >= 0; j--){
			int mul = (product[i + j + 1] - '0') + carry + (a[i] - '0')*(b[j] - '0');
			carry = mul/10;
			product[i + j + 1] = mul%10 + '0';
		}
		product[i] = (product[i] - '0') + carry + '0';
	}
	int i = 0;
	while(product[i] == '0' and i < 2*len){
		i++;
	}
	string c = string(product);
	c = c.substr(i, 2*len);
	return c;
}

int main(){
	string a, b;
	cout << "Enter the first number : ";
	cin >> a;
	cout << "Enter the second number : ";
	cin >> b;
	string product = multiply(a,b);
	cout<< "The product of " << a << " and " << b << " is : " << product;
	return 0;
}

