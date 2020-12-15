#include<bits/stdc++.h>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i ++)
#define forr(i, n) for(int i = int(n); ~i; i --)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i ++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int const oo = 1e9;
int const mod = 1e9 + 7;
int const N = 200010;

map<string, int> mapa;
map<int, string> padres;
vector<string> words;
int cnt;

vector<int> v[N];
bool V[N];

class DisjointSet {
	private:
	int *A,*S;
	int C;

	public:
	
	DisjointSet(int n) {
		A=(int*)malloc(n*sizeof(int));
		S=(int*)malloc(n*sizeof(int));
		for(int x=0;x<n;x++) {
			A[x]=x;
			S[x]=1;
		}
		C=n;
	}
	
	int padre(int x) {
		if(x!=A[x])
			A[x]=padre(A[x]);
		return A[x];
	}
	
	void unir(int i,int j) {
		int a=padre(i);
		int b=padre(j);
		if(a==b)
			return;
		C--;
		if(S[a]<S[b])
			swap(a,b);
		S[a]+=S[b];
		A[b]=a;
	}
		
	int getComponentes() {
		return C;
	}
	
	int getTam(int x) {
		return S[x];
	}
		
};

string BFS(int start, DisjointSet & ds) {
	queue<int> q;
	q.push(start);
	
	string ans = words[start];
	
	while(!q.empty()) {
		int n = q.front();
		q.pop();
		if(V[n])
			continue;
		
		V[n] = 1;
		
		if(words[n].size() < ans.size() || words[n].size() == ans.size() && words[n] < ans)
			ans = words[n];
		
		ds.unir(start, n);
		for(int k : v[n]) {
			q.push(k);
		}
	}
	return ans;
}

vector<string> split(string s, char sep) {
	vector<string> tokens;
	string token;
	istringstream token_stream(s);
	while(getline(token_stream, token, sep)) 
		tokens.push_back(token);
	return tokens;
}

int main() {
    FASTIO
    int m;
    cin>>m;
    forn(i, m) {
    	string a, b;
    	int x, y;
    	cin>>a>>b;
    	if(!mapa.count(a)) {
    		words.pb(a);
    		mapa[a]=words.size() - 1;
    	}
    	if(!mapa.count(b)) {
    		words.pb(b);
    		mapa[b]=words.size() - 1;
    	}
    	x = mapa[a], y=mapa[b];
    	v[x].pb(y);
    	v[y].pb(x);
    }
    
    int n = words.size();
 	DisjointSet ds(n);
 	
    forn(i, n) {
    	if(!V[i]) {
    		string ss = BFS(i, ds);
    		int padre = ds.padre(i);
    		padres[padre] = ss;
    	}
    }
    
    string s;
    getline(cin, s);
    getline(cin, s);
    vector<string> palabras = split(s, ' ');
    bool bul = 0;
    for(string q : palabras) {
    	if(bul)
    		cout << " ";
    	bul = 1;
    	if(!mapa.count(q)) {
    		cout << q;
    	}
    	else {
    		int index = mapa[q];
    		int padre = ds.padre(index);
    		cout << padres[padre];
    	}
    }
    cout << endl;
    return 0;
}
