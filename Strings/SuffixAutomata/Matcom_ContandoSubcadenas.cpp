//https://matcomgrader.com/problem/9520/contando-subcadenas/
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<iostream>
#define mp make_pair

/* Max length of the string */
#define MAXLEN 200010

/* Macro for querying existence of transitions on state i */
#define has_transition(i, c)	states[i].transitions.count(c)

/* Macro for getting next state through transition c from state i */
#define next_state(i, c)	states[i].transitions[c]

using namespace std;

typedef pair<int,int> pii;

struct state {
	int len, link, freq;
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

class BIT {

	/* Binary Indexed Tree */

	private:
	
	int *tree, size;
	
	void add(int x,int k) {
		while(x <= size) {
			tree[x] += k;
			x += x & -x;
		}
	}
	
	public:
	
	BIT(int n) {
		size = n;
		tree = (int*) malloc((n + 10) * sizeof(int));
		for(int i = 0; i < n + 10; i++) 
			tree[i] = 0;
	}
	
	~BIT() {
		free(tree);
	}
	
	void range_sum(int i,int j,int k = 1) {
		add(i, k);
		add(j + 1, -k);
	}
	
	int query(int i) {
		int s = 0;
		while(i >= 1) {
			s += tree[i];
			i -= i & -i;
		}
		return s;
	}

};

char T[MAXLEN];
int D[MAXLEN];
vector<int> A[MAXLEN];
vector<pii> queries[MAXLEN];
int res[MAXLEN];

int main() {
	int x,q,len,freq,n;
	scanf("%s",T);
	n=strlen(T);
	build_machine(T);
	queue<int> Q;
	for(x=1;x<size;x++) 
		D[states[x].link]++;
	for(x=1;x<size;x++) {
		if(D[x] == 0)
			Q.push(x);
	}
	while(!Q.empty()) {
		x=Q.front();
		Q.pop();
		int link = states[x].link;
		states[link].freq+=states[x].freq;
		D[link]--;
		if(!D[link]) 
			Q.push(link);
		A[states[x].freq].push_back(x);
	}
	scanf("%d",&q);
	for(x=0;x<q;x++) {
		scanf("%d %d",&len,&freq);
		queries[freq].push_back(mp(x,len));
	}
	BIT bit(n);
	for(x=1;x<=n;x++) {
		
		for(auto p:queries[x]) 
			res[p.first]-=bit.query(p.second);
		
		for(auto p: A[x]) {
			int link = states[p].link;
			bit.range_sum(states[link].len + 1, states[p].len);
		}
		
		for(auto p:queries[x]) 
			res[p.first]+=bit.query(p.second);
	}
	for(x=0;x<q;x++)
		printf("%d\n",res[x]);
	return 0;
}

