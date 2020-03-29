//https://matcomgrader.com/problem/9256/nivel-de-diferencia/
#include<queue>
#include<map>
#include<iostream>

/* Max length of the string */
#define MAXLEN 1000020

/* Macro for querying existence of transitions on state i */
#define has_transition(i, c)	states[i].transitions.count(c)

/* Macro for getting next state through transition c from state i */
#define next_state(i, c)	states[i].transitions[c]

using namespace std;

typedef long long ll;

struct state {
	int len, link;
	ll substr = 0;
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

short dfs(int n) {
	if(!dp[n]) {
		for(auto i:states[n].transitions) 
			dp[n]|=dfs(i.second);
	}
	return dp[n];
}

int D[MAXLEN * 2]; 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x;
	string a,b;
	cin>>a>>b;
	a.push_back('0');
	b.push_back('1');
	init_automata();
	int i=add_string(a), j=add_string(b);
	dp[i]=1, dp[j]=2;
	for(x=0;x<size;x++) {
		for(auto k:states[x].transitions) 
			D[k.second]++;
		if(dp[x] == 0)
			dfs(x);
	}
	ll sum=0;
	queue<int> q;
	for(x=0;x<size;x++) {
		if(!D[x]) {
			q.push(x);
			states[x].substr = 1;
		}
	}
	while(!q.empty()) {
		x=q.front();
		q.pop();
		for(auto k:states[x].transitions) {
			if(x!=i && x!=j)
				states[k.second].substr+=states[x].substr;
			D[k.second]--;
			if(!D[k.second]) 
				q.push(k.second);
		}
		if((dp[x] == 1 || dp[x] == 2) && (x!= i && x!=j)) 
			sum+=states[x].substr;
	}
	cout<<sum<<endl;
	return 0;
}
