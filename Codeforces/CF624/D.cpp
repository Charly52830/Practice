//https://codeforces.com/contest/1311/problem/D
#include<iostream>
#define N 100010
using namespace std;

int main() {
	int t, a, b, c, m, x, y;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &a, &b, &c);
		m = 3 * N;
		int res_a, res_b, res_c;
		for(x = 1; x < N; x++) {
			int a1, b1, c1;
			int m1 = abs(a - x), m2, m3;
			a1 = x;
			//Sumamos costo de convertir a en x
			for(y = x; y < N; y += x) {
				//Probamos cada múltiplo de x
				m2 = abs(b - y);
				b1 = y;
				int multiplo_arriba = c + (y - c % y);
				if(c >= y) {
					int multiplo_abajo = c - c % y;
					if(abs(multiplo_arriba - c) < abs(multiplo_abajo - c)) {
						m3 = abs(multiplo_arriba - c);
						c1 = multiplo_arriba;
					}
					else {
						m3 = abs(multiplo_abajo - c);
						c1 = multiplo_abajo;
					}
				}
				else {
					m3 = abs(multiplo_arriba - c);
					c1 = multiplo_arriba;
				}
				if(m1 + m2 + m3 < m) {
					m = m1 + m2 + m3;
					res_a = a1;
					res_b = b1;
					res_c = c1;
				}
			}
		}
		printf("%d\n%d %d %d\n", m, res_a, res_b, res_c);
	}
	return 0;
}
