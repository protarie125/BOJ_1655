#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto maxq = priority_queue<int>{};
	auto minq = priority_queue<int, vi, greater<int>>{};

	int n;
	cin >> n;

	while (0 < (n--)) {
		int x;
		cin >> x;

		if (maxq.size() == minq.size()) {
			maxq.push(x);
		}
		else {
			minq.push(x);
		}

		if (!maxq.empty() && !minq.empty() &&
			maxq.top() > minq.top()) {
			auto f = maxq.top();
			maxq.pop();

			auto g = minq.top();
			minq.pop();

			maxq.push(g);
			minq.push(f);
		}

		cout << maxq.top() << '\n';
	}

	return 0;
}