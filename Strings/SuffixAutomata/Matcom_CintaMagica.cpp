//https://matcomgrader.com/problem/9521/la-cinta-magica/
//Status: Runtime error
#include <stack>
#include <map>
#include <iostream>

using namespace std;

struct state {
	int len, link, index;
	map<char,int> transitions;
};

class SuffixAutomata {
	
	private:
	
	state* states;
	int size, last;
	
	void init_automata(int N) {
		states = (state*) malloc(2 * N * sizeof(state));
		for(int i = 0; i < 2 * N; i++) {
			state tmp_state;
			states[i]=tmp_state;
		}
		last = 0;
		size = 1;
		states[0].link = -1;
		states[0].len = 0;
		states[0].index = 0;
	}
	
	void add_char(char c, int index) {
		int cur = size++;
		states[cur].len = states[last].len + 1;
		states[cur].index = index;
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
				states[clone].index = states[q].index;
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
	
	SuffixAutomata(string str, bool reverse) {
		init_automata(str.size());
		if(!reverse) {
			for(int x = 0; x < str.size(); x++)
				add_char(str[x], x);
		}
		else {
			for(int x = str.size() - 1; x >= 0; x--)
				add_char(str[x], x);
		}
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
	
	int get_index(int i) {
		return states[i].index;
	}
	
};

string T,s;
stack<int> stac;

int main() {
	cin>>T;
	SuffixAutomata sa(T,false);
	SuffixAutomata sa_rev(T,true);
	int n, ans=0;
	cin>>n;
	while(n--) {
		cin>>s;
		while(!stac.empty())
			stac.pop();
		int i,j,cur=0;
		for(i=cur=0;i<s.size() && sa.has_transition(cur,s[i]);i++) {
			cur = sa.next_state(cur,s[i]);
			stac.push(cur);
		}
		if(i == s.size()) {
			ans++;
		}
		else {
			bool bul=0;
			//////	Runtime error ocurre aquí
			cur = 0;
			for(j=s.size() - 1;j >= 0 && sa_rev.has_transition(cur,s[j]);j--) {
				cur = sa_rev.next_state(cur,s[j]);
				if(j<=i && !stac.empty()) {
					int x = stac.top();
					stac.pop();
					if(sa.get_index(x) < sa_rev.get_index(cur)) {
						bul = 1;
						break;
					}
				}
			}
			//////
			ans+=bul;
		}
	}
	cout<<ans<<endl;
	return 0;
}

