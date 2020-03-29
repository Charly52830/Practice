//https://matcomgrader.com/problem/9523/buscando-la-semejanza/
#include<map>
#include<iostream>

/* Max length of the string */
#define MAXLEN 1000020

/* Macro for querying existence of transitions on state i */
#define has_transition(i, c)	states[i].transitions.count(c)

/* Macro for getting next state through transition c from state i */
#define next_state(i, c)	states[i].transitions[c]

using namespace std;

int N;

struct state {
	int len, link;
	map<char,int> transitions;
};

state states[MAXLEN * 2];
short dp[MAXLEN * 2];
int size, last;

void init_automata() {
	states[0].len = 0;
	states[0].link = -1;
	size = 1;
	last = 0;
}

int add_char(char c) {
	int cur = size++;
	states[cur].len = states[last].len + 1;
	int p = last;
	while(p != -1 && !has_transition(p, c)) {
		states[p].transitions[c] = cur;
		p = states[p].link;
	}
	if(p == -1) {
		states[cur].link = 0;
	}
	else {
		int q = next_state(p, c);
		if(states[p].len + 1 == states[q].len) {
			states[cur].link = q;
		}
		else {
			int clone = size++;
			states[clone].len = states[p].len + 1;
			states[clone].transitions = states[q].transitions;
			states[clone].link = states[q].link;
			while(p != -1 && next_state(p,c) == q) {
				states[p].transitions[c] = clone;
				p = states[p].link;
			}
			states[q].link = states[cur].link = clone;
		}
	}
	last = cur;
	return cur;
}

int add_string(string &str) {
	int last;
	for(int i = 0; i < str.size();i++) 
		last = add_char(str[i]);
	return last;
}

string T;
int res;

short dfs(int n) {
	if(!dp[n]) {
		for(auto i:states[n].transitions) 
			dp[n]|=dfs(i.second);
		if(dp[n] == (1<<N) -1)
			res = max(states[n].len, res);
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i;
	cin>>N;
	init_automata();
	for(i=0;i<N;i++) {
		cin>>T;
		T.push_back('0' + i);
		int index = add_string(T);
		dp[index]=(1<<i);
	}
	dfs(0);
	cout<<res<<endl;
	return 0;
}
