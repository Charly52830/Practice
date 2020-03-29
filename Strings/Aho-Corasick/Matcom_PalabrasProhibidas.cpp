//https://matcomgrader.com/problem/9534/palabras-prohibidas/
#include<string.h>
#include<vector>
#include<iostream>
#define L 510
using namespace std;

const int alphabet_size = 26;

struct Vertex {
	
	int transitions[alphabet_size];
	int suffix_link = -1, exit_link = -1;
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

int get_exit_link(int i) {
	if(states[i].exit_link == -1) {
		states[i].exit_link = states[i].leaf;
		if(i != 0) 
			states[i].exit_link |= get_exit_link( get_link(i) );
	}
	return states[i].exit_link;
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

char res[L];
int n,l;
string alphabet="abcdefghijklmnopqrstuvwxyz";

bool dfs(int i,int j) {
	if(j == l) {
		res[j] = '\0';
		return 1;
	}
	for(char c: alphabet) {
		int k=next_state(i,c);
		if(get_exit_link(k) == 0) {
			res[j] = c;
			if(dfs(k, j + 1)) 
				return 1;
		}
	}
	return 0;
}

int main() {
	cin>>n>>l;
	string s;
	for(int x=0;x<n;x++) {
		cin>>s;
		add_string(s);
	}
	if(dfs(0,0)) {
		printf("%s\n",res);
	}
	else {
		printf("Imposible\n");
	}
	return 0;
}
