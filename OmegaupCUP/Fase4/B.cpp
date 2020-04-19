//https://omegaup.com/arena/omegacup4/practice/#problems/atsa-xor-i
#include<vector>
#include<iostream>
#define N 20010
#define pb push_back
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

int next_bit(vl &A, vl &A_, int m) {
	for(int i=m-1;i>=0;i--) {
		bool bul=0;
		for(auto x:A) {
			if(x & (1LL<<i)) {
				bul = 1;
				break;
			}
		}
		bool bul2 = 0;
		for(auto x:A_) {
			if(!(x & (1LL<<i))) {
				bul2=1;
				break;
			}
		}
		if(bul && bul2)
			return i;
	}
	return 0;
}

ll solve(vl &A, vl &A_, int m) {
	if(A.size() * A_.size() <= 1000000) {
		ll ans=0;
		for(auto i:A) {
			for(auto j:A_) 
				ans=max(ans,i^j);
		}
		return ans;
	}
	else {
		int i=next_bit(A,A_,m);
		int j=next_bit(A_,A,m);
		if(i>j) {
			{
				vl B,B_;
				swap(A,B);
				swap(A_,B_);
				for(auto x:B) {
					if(x & (1LL<<i))
						A.pb(x);
				}
				for(auto x:B_) {
					if(!(x & (1LL<<i)))
						A_.push_back(x);
				}
			}
			return solve(A,A_,i);
		}
		else if(i<j) {
			{
				vl B,B_;
				swap(A,B);
				swap(A_,B_);
				for(auto x:B) {
					if(!(x & (1LL<<i)))
						A_.pb(x);
				}
				for(auto x:B_) {
					if(x & (1LL<<i))
						A.pb(x);
				}
			}
			return solve(A,A_,i);
		}
		else {
			vl B,B_;
			{
				vl C,C_;
				swap(C,A);
				swap(C_,A_);
				for(auto x:C) {
					if(x & (1LL<<i))
						A.pb(x);
					else
						B_.pb(x);
				}
				for(auto x:C_) {
					if(x & (1LL<<i))
						B.pb(x);
					else
						A_.pb(x);
				}
			}
			return max(solve(A,A_,i), solve(B,B_,i));
		}
	}
}

int last_bit(ll k) {
	int ans=0;
	while(k) {
		k>>=1;
		ans++;
	}
	return ans-1;
}

ll S[N];

int main() {
	int n;
	cin>>n;
	ll M=0LL;
	for(int x=0;x<n;x++) cin>>S[x],M=max(M,S[x]);
	int m=last_bit(M);
	vl A,A_;
	for(int x=0;x<n;x++) {
		if(S[x] & (1LL<<m))
			A.pb(S[x]);
		else
			A_.pb(S[x]);
	}
	cout<<solve(A,A_,m)<<endl;
	return 0;
}
