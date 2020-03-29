//https://www.spoj.com/problems/SUBLEX/
#include<map>
#include<iostream>

/* Max length of the string */
#define MAXLEN 90010

/* Macro for querying existence of transitions */
#define has_transition(state, c)	state.transitions.count(c)

/* Macro for getting next state through transition c */
#define next_state(state, c)	state.transitions[c]

using namespace std;

typedef long long ll;

struct state {
	int len, link;
	long long substr;
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
	states[cur].substr = 0;
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
			states[clone].substr = 0;
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

ll dp(int cur) {
	if(!states[cur].substr) {
		for(auto i:states[cur].transitions) 
			states[cur].substr+=dp(i.second);
		states[cur].substr++;
	}
	return states[cur].substr;
}

char T[MAXLEN];
char ans[MAXLEN];
int j;

void query(ll k,int cur=0) {
	if(k==0) {
		ans[j++]='\0';
		return;
	}
	ll sum=0;
	for(auto st:states[cur].transitions) {
		if(sum < k && k <= sum + states[st.second].substr) {
			ans[j++]=st.first;
			query(k-sum-1,st.second);
			break;
		}
		sum+=states[st.second].substr;
	}
}

int main() {
	scanf("%s",T);
	build_machine(T);
	ll substrings=dp(0);
	int q,k;
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&k);
		if(k<=substrings) {
			j=0;
			query(k);
			printf("%s\n",ans);
		}
	}
	return 0;
}
