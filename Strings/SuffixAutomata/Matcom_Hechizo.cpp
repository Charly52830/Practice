//https://matcomgrader.com/problem/9526/un-buen-hechizo/

/* Suffix automata
*
*  Source: https://cp-algorithms.com/string/suffix-automaton.html
*/

#include<map>
#include<iostream>
#define oo 1000000010

/* Max length of the string */
#define MAXLEN 200010

/* Macro for querying existence of transitions on state i */
#define has_transition(i, c)	states[i].transitions.count(c)

/* Macro for getting next state through transition c from state i */
#define next_state(i, c)	states[i].transitions[c]

using namespace std;

struct state {
	int len, link;
	map<char,int> transitions;
	int dp;
};

state states[MAXLEN * 2];
int size, last;
int alphabet_size;
char T[MAXLEN];

void init_automata() {
	states[0].len = 0;
	states[0].link = -1;
	size = 1;
	last = 0;
}

void add_char(char c) {
	int cur = size++;
	states[cur].len = states[last].len + 1;
	states[cur].dp = 0;
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
			states[clone].dp = 0;
			while(p != -1 && next_state(p,c) == q) {
				states[p].transitions[c] = clone;
				p = states[p].link;
			}
			states[q].link = states[cur].link = clone;
		}
	}
	last = cur;
}

void build_machine(const char *str) {
	init_automata();
	for(int i = 0; str[i] != '\0';i++) 
		add_char(str[i]);
}

// Shortest non-appearing substring
int SNAS(int cur) {
	if(states[cur].dp == 0) {
		states[cur].dp = 1;
		if(states[cur].transitions.size() == alphabet_size) {
			char c='a';
			for(auto next:states[cur].transitions) {
				if(SNAS(next.second) < SNAS(states[cur].transitions[c]))
					c=next.first;
			}
			states[cur].dp += SNAS(states[cur].transitions[c]);
		}
	}
	return states[cur].dp;
}

char ans[MAXLEN];

int main() {
	int n,i=0;
	scanf("%d %d",&n,&alphabet_size);
	scanf("%s",T);
	build_machine(T);
	int t=SNAS(0);
	int cur=0;
	while(states[cur].dp > 1) {
		for(auto next:states[cur].transitions) {
			if(states[next.second].dp == states[cur].dp - 1) {
				ans[i++]=next.first;
				cur = next.second;
				break;
			}
		}
	}
	for(char c:"abcdefghijklmnoprstuvwxyz") {
		if(!states[cur].transitions.count(c)) {
			ans[i++]=c;
			break;
		}
	}
	printf("%s\n",ans);
	return 0;
}
