#include <vector>

using namespace std;

void Reverse(vector<int> &v) {

	int begin = 0, end = v.size() - 1, tmp;

	while (begin < end) {
		tmp = v[begin];
		v[begin] = v[end];
		v[end] = tmp;
		begin++;
		end--;
	}
}
