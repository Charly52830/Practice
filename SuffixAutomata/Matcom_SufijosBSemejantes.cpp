//https://matcomgrader.com/problem/9524/sufijos-b-semejantes/
#include <string.h>
#include <queue>
#include <map>
#include <iostream>

/* Max length of the string */
#define MAXLEN 100010

using namespace std;

struct state {
	int len, link, freq;
	map<char,int> transitions;
};

int D[2 * MAXLEN];

class SuffixAutomata {
	
	private:
	
	state* states;
	int size, last;
	
	void init_automata() {
		states = (state*)malloc(2 * MAXLEN * sizeof(state));
		for(int i=0;i < 2 * MAXLEN; i++) {
			state tmp_state;
			states[i]=tmp_state;
		}
		last = 0;
		size = 1;
		states[0].link = -1;
		states[0].len = 0;
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
	
	public:
	
	SuffixAutomata(const char *str) {
		init_automata();
		for(int x=0;str[x] != '\0';x++)
			add_char(str[x]);
	}
	
	~SuffixAutomata() {
		free(states);
	}
	
	bool has_transition(int i,char c) {
		return states[i].transitions.count(c);
	}
	
	int next_state(int i, char c) {
		return states[i].transitions[c];
	}
	
	void compute_concurrence() {
		int x;
		memset(D,0,sizeof D);
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
	}
	
	int get_concurrence(int i) {
		return states[i].freq;
	}
	
};

char T[MAXLEN];
int ans[MAXLEN];

int main() {
	int t,x,cur,q,n;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",T);
		n = strlen(T);
		SuffixAutomata sa(T);
		sa.compute_concurrence();
		for(cur=x=0;T[x]!='\0';cur = sa.next_state(cur,T[x]),x++) 
			ans[x] = sa.get_concurrence(cur);
		ans[x] = sa.get_concurrence(cur);
		scanf("%d",&q);
		while(q--) {
			scanf("%d",&x);
			if(x == 0)
				printf("%d ",n);
			else if(x > n)
				printf("0 ");
			else
				printf("%d ",ans[x]);
		}
		printf("\n");
	}
	return 0;
}
