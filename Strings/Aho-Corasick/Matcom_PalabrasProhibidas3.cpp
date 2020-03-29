//https://matcomgrader.com/problem/9533/palabras-prohibidas-iii/
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;

const int alphabet_size = 26;

struct Vertex {
	
	int transitions[alphabet_size];
	int suffix_link = -1, weight = -1;
	bool leaf = false;
	int parent = -1;
	char parent_char;
	
	Vertex(int p = -1, char c = '$') : parent(p), parent_char(c) {
		memset(transitions, -1, sizeof transitions);
	}
	
	bool has_transition(char c) {
		return transitions[c - 'a'] != -1;
	}
	
	void set_transition(char c, int state) {
		transitions[c - 'a'] = state;
	}
	
};

vector<Vertex> states(1);

int next_state(int i, char c);

void add_string(string const& str) {
	int cur = 0;
	for(char c : str) {
		if(!states[cur].has_transition(c)) {
			states[cur].set_transition(c, states.size());
			states.emplace_back(cur, c);
		}
		cur = next_state(cur, c);
	}
	states[cur].leaf = true;
}

int get_link(int i) {
	if(states[i].suffix_link == -1) {
		if(i == 0 || states[i].parent == 0) 
			states[i].suffix_link = 0;
		else
			states[i].suffix_link = next_state(get_link(states[i].parent), states[i].parent_char);
	}
	return states[i].suffix_link;
}

int weight(int i) {
	if(states[i].weight == -1) {
		states[i].weight = states[i].leaf;
		if(i != 0) 
			states[i].weight += weight( get_link(i) );
	}
	return states[i].weight;
}

int next_state(int i, char c) {
	if(!states[i].has_transition(c)) {
		if(i == 0) 
			states[i].transitions[c - 'a'] = 0;
		else
			states[i].transitions[c - 'a'] = next_state(get_link(i), c);
	}
	return states[i].transitions[c - 'a'];
}

int dp[110][110][25];
string alphabet="abcdefghijklmnopqrstuvwxyz";

int main() {
	int n,L,K,k,i,j;
	cin>>n>>L>>K;
	string s;
	for(int x=0;x<n;x++) {
		cin>>s;
		add_string(s);
	}
	for(j = L; j >=0; j--) {
		for(k=0;k<=K;k++) {
			for(i = 0;i<states.size();i++) {
				if(j == L && k == 0)
					dp[i][j][k] = 26;
				else if(j == L && k > 0)
					dp[i][j][k] = -1;
				else {
					dp[i][j][k] = -1;
					for(char c:alphabet) {
						int x=next_state(i,c);
						if(weight(x) <= k && dp[x][j + 1][k - weight(x)] != -1) {
							dp[i][j][k] = c - 'a';
							break;
						}
					}
				}
			}
		}
	}
	if(dp[0][0][K] != -1) {
		s="";
		i=0,j=0,k=K;
		for(int c=dp[i][j][k];dp[i][j][k] != 26;j++, i = next_state(i,c+'a'), k-=weight(i), c=dp[i][j][k]) 
			s.push_back((char)('a' + dp[i][j][k]));
		cout<<s<<endl;
	}
	else
		cout<<"Imposible\n";
	return 0;
}
