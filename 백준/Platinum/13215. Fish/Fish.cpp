#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set os;
void os_erase(ll val) {
	auto it = os.find_by_order(os.order_of_key(val));
	if (*it == val) os.erase(it);
}

ll A[200001]{}, S[200001]{};
int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, K;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) cin >> A[i], S[i] = S[i - 1] + A[i], os.insert(S[i]);

	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += N - os.order_of_key(K) - (i-1);
		K += A[i];
		os_erase(S[i]);
	}
	cout << ans;

}