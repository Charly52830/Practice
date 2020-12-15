#include <math.h>
#include <string.h>
#include <algorithm>
#include <cassert>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); i ++)
#define forr(i, n) for(int i = int(n); ~i; i --)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i ++)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int const N = 100010;
int dp[N],G[N],A[N],B[N];


int const oo = 1e9;
int const mod = 1e9 + 7;


/**
 * Definición de Segment Tree para distintas preguntas comunes.
 * range minimum query: 
 *  SegmentTree<int> st(v, min_function);
 *
 * range maximum query:
 *  SegmentTree<int> st(v, max_function);
 *
 * range sum query:
 *  SegmentTree<int> st(v, sum_function);
 *
 * range gcd/lcm query:
 *  SegmentTree<int> st(v, gcd_function);
 *
 * range sum query con n elementos iniciados en 0:
 *  SegmentTree<int> st(n, sum_function, 0);
 * 
 * actualizar arreglo sustituyendo el valor del índice i con el valor:
 *  st.update(i, val, false);
 *
 * actualizar arreglo sumando el valor del índice i con el valor val:
 *  st.update(i, val, true);
 *
 * Se puede formar cualquier otro Segment Tree con funciones específicas y
 * valores por defecto específicos.
 *
 * Las funciones deben regresar el tipo de dato del que se declaró el Segment Tree.
 * Las funciones deben recibir 2 parámetros del tipo de dato del que se declaró
 * el Segment Tree.
 */

int min_function(int a,int b) {
	return min(a,b);
}

int max_function(int a,int b) {
	return max(a,b);
}

int sum_function(int a,int b) {
	return a+b;
}

int gcd_function(int a, int b) {
	return !b ? a : gcd_function(b, a % b);
}

template <typename T>
class SegmentTree {

	/**
	 * Segment tree que soporta operaciones de preguntas en rangos y update de un
	 * solo valor.
	 *
	 * Construcción: O(n log n)
	 * Actualización: O(log n)
	 * Pregunta: O(log n)
	 * Memoria: O(2n)
	 * n: tamaño del arreglo
	 */
	
	T (*func) (T,T);
	T *tree;
	int n;
	
	public:
	
	/**
	 * Constructor que crea un Segment Tree a partir de un arreglo.
	 *
	 * v: arreglo del que se construye el segment tree.
	 * custom_function: función con la que trabaja el segment tree.
	 */
	SegmentTree(vector<T> & v, T (*custom_function) (T,T)) {
		n = v.size();
		func = custom_function;
		tree = new T[2 * n];
		for(int i = 0; i < n; i++) 
			tree[i + n] = v[i];
		for(int i = n - 1; i > 0; i--)
			tree[i] = func(tree[i * 2], tree[i * 2 + 1]);
	}
	
	/**
	 * Constructor que crea un Segment Tree vacío, es decir, trabaja sobre un 
	 * arreglo inexistente cuyos valores son puestos por default.
	 *
	 * size: tamaño del arreglo.
	 * custom_function: función con la que trabaja el segment tree.
	 * default_value: valor por defecto de los elementos del arreglo.
	 */
	SegmentTree(int size, T (*custom_function) (T,T), T default_value = 0) {
		n = size;
		func = custom_function;
		tree = new T[2 * n];
		for(int i = 0; i < n; i++) 
			tree[i + n] = default_value;
		for(int i = n - 1; i > 0; i--)
			tree[i] = func(tree[i * 2], tree[i * 2 + 1]);
	}
	
	/**
	 * Pregunta del arreglo en el rango de i a j evaluando con la función asignada
	 * Indexado desde 0 y los segmentos son cerrados (la pregunta incluye a los
	 * indices i y j).
	 *
	 * i: indice inferior.
	 * j: indice superior.
	 */
	T query(int i, int j) {
		T ans;
		bool b = 0;
		i += n, j += n;
		while(i <= j) {
			if(i & 1) ans = b ? func(ans, tree[i ++]) : tree[i ++], b = 1;
			if(!(j & 1)) ans = b ? func(ans, tree[j --]) : tree[j --], b = 1;
			i >>= 1, j >>= 1;
		}
		return ans;
	}
	
	/**
	 * Función para actualizar un solo elemento del arreglo.
	 * Indexado desde 0.
	 *
	 * i: indice del arreglo a actualizar
	 * val: valor con el que se va a actualizar el arreglo en la posición i
	 * add: si add es false, el arreglo en la posición i se sustituirá con el nuevo
	 *	valor, si es true, en arreglo en la posición i será sumado al valor actual.
	 */
	void update(int i, T val, bool add = false) {
		i += n;
		if(add) tree[i] += val;
		else tree[i] = val;
		for(i >>= 1; i > 0; i >>= 1)
			tree[i] = func(tree[2 * i], tree[2 * i + 1]);
	}
	
};

int main() {
	FASTIO
	int n,ans=0,ma;
	cin>>n;
	forn(i,n){
	    cin>>G[i]>>A[i]>>B[i];
	}
	
	vector<int> v(n + 1, 0);
	SegmentTree<int> st(v, max_function);
	
	forr(i,n-1){
	    int low = min(i + A[i], n), up = min(n,i + B[i]);
	    ma = st.query(low, up);
        st.update(i, G[i] + ma);
        ans=max(ans, G[i] + ma);
	}
	cout<<ans<<endl;
	return 0;
}

