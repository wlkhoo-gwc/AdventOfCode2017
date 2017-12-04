#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<algorithm>
using namespace std;

vector<string> tokenize(string str) {
	vector<string> res;
	int prev, pos;
	prev = pos = 0;
	string delim = " ";
	
	do {
		pos = str.find(delim, prev);
		if (pos == string::npos)
			pos = str.length();
		string token = str.substr(prev, pos-prev);
		if (!token.empty())
			res.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	
	return res;
}

bool validPassphrase(string str) {
	vector<string> tokens = tokenize(str);
	map<string, int> passphrases;
	
	for (int i = 0; i < tokens.size(); i++) {
		if (passphrases.find(tokens[i]) == passphrases.end())
			passphrases[tokens[i]] += 1;
		else
			return false;
	}
	
	return true;
}

bool anagram(string str1, string str2) {
	int n1 = str1.length();
	int n2 = str2.length();
	
	if (n1 != n2)
		return false;
	
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	
	for (int i = 0; i < n1; i++) {
		if (str1[i] != str2[i])
			return false;
	}
	
	return true;
}

bool validPassAnagram(string str) {
	vector<string> tokens = tokenize(str);
	
	for (int i = 0; i < tokens.size(); i++) {
		for (int j = i+1; j < tokens.size(); j++) {
			if (anagram(tokens[i], tokens[j]))
				return false;
		}
	}
	
	return true;
}

int main() {
	ifstream inFile("AoC4_Input.txt");
	string line;
	int cnt = 0;
	
	while(getline(inFile, line)) {
//		if(validPassphrase(line))
		if(validPassAnagram(line))
			cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}