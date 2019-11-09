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

string addStrings(string a, string b){
	int n = makeEqualLength(a, b);
	string c = "";
	int carry = 0;
	for (int i = n - 1; i >= 0; i--){
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		carry = sum/10;
		sum %= 10;
		c = char(sum + '0') + c;
	}
	if (carry!='0')
		c = char(carry + '0') + c;
	int len = c.size();

	int i = 0;
	while(c[i] == '0' and i < len){
		i++;
	}
	c = c.substr(i, len);
	return c;
}

string subtractStrings(string a, string b){
	int n = makeEqualLength(a, b);
	string c = "";
	for (int i = n - 1; i >= 0; i--){
		int inta = a[i] - '0';
		int intb = b[i] - '0';
		if(inta >= intb){
			int diff = inta - intb;
			c = char(diff + '0') + c;
		}
		else{
			inta += 10;
			a[i-1] = a[i-1] - 1;
			int diff = inta - intb;
			c = char(diff + '0') + c;
		}
	}
	int len = c.size();

	int i = 0;
	while(c[i] == '0' and i < len){
		i++;
	}
	c = c.substr(i, len);
	return c;
}

string multiply_karatsuba(string a, string b){
	int n = makeEqualLength(a, b);
	if (n == 0)
		return to_string('0');
	if (n == 1)
		return to_string((a[0] - '0')*(b[0] - '0'));

	int f = n/2;
	int s = n - n/2;

	string al = a.substr(0, f);
	string ar = a.substr(f, s);
	string bl = b.substr(0, f);
	string br = b.substr(f, s);
	string p1 = multiply_karatsuba(al, bl);
	string p2 = multiply_karatsuba(ar, br);
	string p3 = multiply_karatsuba(addStrings(al, ar), addStrings(bl, br));
	
	p3 = subtractStrings(p3, p1);
	p3 = subtractStrings(p3, p2);

	for (int i = 0 ; i < 2*s ; i++) 
			p1 += '0';

	for (int i = 0 ; i < s ; i++) 
			p3 += '0';

	string p = addStrings(p1, p2);
	p = addStrings(p, p3);

	int len = p.size();

	int i = 0;
	while(p[i] == '0' and i < len){
		i++;
	}
	p = p.substr(i, len);
	return p;
}

int main(){
	string a, b;
	cout << "Enter the first number : ";
	cin >> a;
	cout << "Enter the second number : ";
	cin >> b;
	string prod = multiply_karatsuba(a,b);
	cout<< "The product of " << a << " and " << b << " is : " << prod;
	return 0;
}

