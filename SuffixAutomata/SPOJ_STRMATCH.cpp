//https://www.spoj.com/problems/STRMATCH/
#include<queue>
#include<map>
#include<iostream>

/* Max length of the string */
#define MAXLEN 3000

/* Macro for querying existence of transitions */
#define has_transition(state, c)	state.transitions.count(c)

/* Macro for getting next state through transition c */
#define next_state(state, c)	state.transitions[c]

using namespace std;

struct state {
	int len, link, freq;
	map<char,int> transitions;
};

state states[MAXLEN * 2];
int size, last;

void init_automaton() {
	states[0].len = 0;
	states[0].link = -1;
	size++;
	last = 0;
}

void add_char(char c) {
	int cur = size++;
	states[cur].len = states[last].len + 1;
	states[cur].freq = 1;
	int p = last;
	while(p != -1 && !has_transition(states[p], c)) {
		states[p].transitions[c] = cur;
		p = states[p].link;
	}
	if(p == -1) {
		states[cur].link = 0;
	}
	else {
		int q = next_state(states[p], c);
		if(states[p].len + 1 == states[q].len) {
			states[cur].link = q;
		}
		else {
			int clone = size++;
			states[clone].len = states[p].len + 1;
			states[clone].transitions = states[q].transitions;
			states[clone].link = states[q].link;
			states[clone].freq = 0;
			while(p != -1 && next_state(states[p],c) == q) {
				states[p].transitions[c] = clone;
				p = states[p].link;
			}
			states[q].link = states[cur].link = clone;
		}
	}
	last = cur;
}

void build_machine(const char *str) {
	init_automaton();
	for(int i = 0; str[i] != '\0';i++) 
		add_char(str[i]);
}

int query(const char *str) {
	int x,cur;
	for(x=cur=0;str[x]!='\0';x++) {
		if(has_transition(states[cur],str[x]))
			cur=next_state(states[cur],str[x]);
		else
			return 0;
	}
	return states[cur].freq;
}

char s[MAXLEN],T[500010];
int D[MAXLEN];

int main() {
	int n,q,x;
	scanf("%d %d",&n,&q);
	scanf("%s",s);
	build_machine(s);
	for(x=1;x<size;x++) 
		D[states[x].link]++;
	
	// Toposort
	queue<int> Q;
	for(x=1;x<size;x++) {
		if(D[x] == 0)
			Q.push(x);
	}
	while(!Q.empty()) {
		x=Q.front();
		Q.pop();
		int link = states[x].link;
		if(link == -1)
			continue;
		states[link].freq+=states[x].freq;
		D[link]--;
		if(D[link] == 0)
			Q.push(link);
	}
	while(q--) {
		scanf("%s",T);
		printf("%d\n",query(T));
	}
	return 0;
}
