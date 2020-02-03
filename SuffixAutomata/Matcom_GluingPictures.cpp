//https://matcomgrader.com/problem/9641/gluing-pictures/
/* Suffix automata
*
*  Source: https://cp-algorithms.com/string/suffix-automaton.html
*/

#include <map>
#include <iostream>

/* Max length of the string */
#define MAXLEN 200010

using namespace std;

struct state {
	int len, link;
	map<char,int> transitions;
};

class SuffixAutomata {
	
	private:
	
	state* states;
	int size, last;
	
	void init_automata() {
		states = (state*) malloc(2 * MAXLEN * sizeof(state));
		for(int i = 0; i < 2 * MAXLEN; i++) {
			state tmp_state;
			states[i] = tmp_state;
		}
		last = 0;
		size = 1;
		states[0].link = -1;
		states[0].len = 0;
	}
	
	void add_char(char c) {
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
				while(p != -1 && next_state(p, c) == q) {
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
		for(int x = 0; str[x] != '\0'; x++)
			add_char(str[x]);
	}
	
	~SuffixAutomata() {
		free(states);
	}
	
	bool has_transition(int i, char c) {
		return states[i].transitions.count(c);
	}
	
	int next_state(int i, char c) {
		return states[i].transitions[c];
	}
	
};

char T[MAXLEN];

int main() {
	scanf("%s",T);
	SuffixAutomata sa(T);
	int n;
	scanf("%d",&n);
	while(n--) {
		int cur,x;
		int sum=0;
		scanf("%s",T);
		for(cur = x = 0;T[x] != '\0'; x++) {
			if(sa.has_transition(cur,T[x])) 
				cur = sa.next_state(cur,T[x]);
			else {
				if(!cur) {
					sum = -2;
					break;
				}
				else {
					cur = 0, sum++;
					x--;
				}
			}
		}
		printf("%d\n",sum+1);
	}
	return 0;
}

