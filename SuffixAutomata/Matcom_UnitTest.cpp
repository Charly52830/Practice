//https://matcomgrader.com/problem/9525/unit-testing/
#include<queue>
#include<map>
#include<iostream>

/* Max length of the string */
#define MAXLEN 200010

/* Macro for querying existence of transitions on state i */
#define has_transition(i, c)	states[i].transitions.count(c)

/* Macro for getting next state through transition c from state i */
#define next_state(i, c)	states[i].transitions[c]

using namespace std;

typedef long long ll;

struct state {
	int len, link, freq;
	ll substr = 0, substr_freq = 0;
	map<char,int> transitions;
};

state states[MAXLEN * 2];
int size, last;

void init_automata() {
	states[0].len = 0;
	states[0].link = -1;
	size = 1;
	last = 0;
}

void add_char(char c) {
	int cur = size++;
	states[cur].len = states[last].len + 1;
	states[cur].freq = 1;
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
			states[clone].freq = 0;
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

ll dfs_freq(int cur) {
	if(!states[cur].substr_freq) {
		for(auto i:states[cur].transitions) 
			states[cur].substr_freq+=dfs_freq(i.second);
		states[cur].substr_freq+=states[cur].freq;
	}
	return states[cur].substr_freq;
}

ll dfs(int cur) { 
	if(!states[cur].substr) {
		for(auto i:states[cur].transitions) 
			states[cur].substr+=dfs(i.second);
		states[cur].substr++;
	}
	return states[cur].substr;
}

char T[MAXLEN];
int D[MAXLEN];
int j;

void query_freq(int k,int cur=0) {
	if(k<=0) 
		T[j++] = '\0';
	else {
		ll sum=0;
		for(auto i:states[cur].transitions) {
			if(states[i.second].substr_freq + sum >= k) {
				T[j++] = i.first;
				query_freq(k-sum-states[i.second].freq,i.second);
				break;
			}
			sum+=states[i.second].substr_freq;
		}
	}
}

void query(int k,int cur=0) {
	if(k<=0) {
		T[j++] = '\0';
	}
	else {
		ll sum=0;
		for(auto i:states[cur].transitions) {
			if(states[i.second].substr + sum >= k) {
				T[j++] = i.first;
				query(k-sum-1,i.second);
				break;
			}
			sum+=states[i.second].substr;
		}
	}
}

int main() {
	int x;
	scanf("%s",T);
	build_machine(T);
	
	//Preprocesar frecuencias
	queue<int> q;
	for(x=0;x<size;x++) 
		D[states[x].link]++;
	for(x=0;x<size;x++)
		if(D[x] == 0)
			q.push(x);
	while(!q.empty()) {
		x=q.front();
		q.pop();
		int link = states[x].link;
		if(link != -1) {
			states[link].freq+=states[x].freq;
			D[link]--;
			if(!D[link])
				q.push(link);
		}
	}
	
	//Preprocesar subcadenas
	ll substr = dfs(0);
	ll substr_freq = dfs_freq(0);
	substr_freq-=states[0].freq;
	
	//Responder preguntas
	int Q,k;
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d",&k);
		if(k <= substr_freq) {
			j=0;
			query_freq(k);
			printf("%s\n",T);
		}
		else 
			printf("No existe.\n");
		if(k <substr ) {
			j=0;
			query(k);
			printf("%s\n",T);
		}
		else 
			printf("No existe.\n");
	}	
	return 0;
}
