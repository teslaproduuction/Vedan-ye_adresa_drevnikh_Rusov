#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <bitset>

using namespace std;

void ip_to_int(string ip, int& a, string& str) {
	string temp;
	for (int i = 0; i < ip.find('.'); i++) {
		temp += ip[i];
	}
	a = stoi(temp);
	temp = "";
	int i = 0;
	while (ip[i] != '.') {
		ip.erase(i, 1);
	}
	ip.erase(0, 1);
	str = ip;
}

void ip_to_int2(string ip, int& a, string& str) {
	string temp2 = "";
	for (int i = 0; i < ip.find('/'); i++) {
		temp2 += ip[i];
	}
	a = stoi(temp2);
	temp2 = "";
	int i = 0;
	while (ip[i] != '/') {
		ip.erase(i, 1);
	}
	ip.erase(0, 1);
	str = ip;
}

void decdv(int& o, string& temp) {
	unsigned long long int i = 1, binary = 0;
	while (o > 0) {
		binary += (o % 2) * i;
		o = o / 2;
		i *= 10;
	}
	temp = to_string(binary);
}

void dvdec(int& p, int& l) {
	int counter = 1, timeless;
	long int  decimal = 0;
	while (p != 0)
	{
		timeless = p % 10 * counter;
		decimal = decimal + timeless;
		p = p / 10;
		counter *= 2;
	}
	l = decimal;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, c, d, a2, b2, c2, d2, t = 0, m = 0;
	string str, temp, st, st1, st2, st3, st4;
	cout << "Введите IP в формате (x.x.x.x/маска): ";
	cin >> str;
	ip_to_int(str, a, temp);
	ip_to_int(temp, b, temp);
	ip_to_int(temp, c, temp);
	ip_to_int2(temp, d, temp);
	m = stoi(temp);
	string mask = "00000000000000000000000000000000";
	for (int i = 0; i < m; i++) {
		if (mask[i] = '0') {
			mask[i] = '1';
		}
	};
	for (int i = 0; i < 32; i++) {
		if (i < 8) {
			st1 += mask[i];
		}
		if (i > 7 && i < 16) {
			st2 += mask[i];
		}
		if (i > 15 && i < 24) {
			st3 += mask[i];
		}
		if (i > 24) {
			st4 += mask[i];
		}
	}
	int buff = stoi(st1);
	dvdec(buff, a2);
	buff = stoi(st2);
	dvdec(buff, b2);
	buff = stoi(st3);
	dvdec(buff, c2);
	buff = stoi(st4);
	dvdec(buff, d2);
	cout << endl << "Network: " << (a & a2) << "." << (b & b2) << "." << (c & c2) << "." << (d & d2) << endl;
	cout << "Broadcast: " << bitset<8>((bitset<8>(a) | ~(bitset<8>(a2)))).to_ulong() << "." << bitset<8>((bitset<8>(b) | ~(bitset<8>(b2)))).to_ulong() << "." << bitset<8>((bitset<8>(c) | ~(bitset<8>(c2)))).to_ulong() << "." << bitset<8>((bitset<8>(d) | ~(bitset<8>(d2)))).to_ulong() << endl;
	cout << "Mask: " << a2 << "." << b2 << "." << c2 << "." << d2 << endl;
	decdv(a2, temp);
	st += temp;
	decdv(b2, temp);
	st += temp;
	decdv(c2, temp);
	st += temp;
	decdv(d2, temp);
	st += temp;
	int o = st.length();
	for (int i = 0; i < o; i++) {
		if (st[i] == '1') {
			t++;
		}
	}
	cout << "Hosts: " << pow(2, (32 - t)) << endl;
	system("pause");
}