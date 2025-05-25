//uva12532
#include<iostream>
#include<cmath>
using namespace std;

int tree[1000001] = {1}, ll[1000001] = {1}, rr[1000001] = {1};

int ask(int l, int r, int pos){
	if (l == rr[pos] && r == ll[pos]) return tree[pos];
	else if (l > ll[pos * 2]) return ask(l, r, pos * 2 + 1);
	else if (r <= ll[pos * 2]) return ask(l, r, pos * 2);
	else return ask(l, ll[pos * 2], pos * 2) * ask(rr[pos * 2 + 1], r, pos * 2 + 1);
}

int main(){
	int i, N, K, count, ans, para[2];
	char instruct;
	while (cin >> N){
		cin >> K;
		int layer = (int)(log(N)/log(2)+1);
		if (pow(2,layer-1) < N) layer++;
		for (i = pow(2, layer - 1); i < pow(2, layer - 1) + N; i++){
			cin >> tree[i];
			if (tree[i] > 0) tree[i] = 1;
			else if (tree[i] < 0) tree[i] = -1;
			else tree[i] = 0;
			ll[i] = i - pow(2, layer - 1) + 1;
			rr[i] = i - pow(2, layer - 1) + 1;
		}
		for (i = pow(2, layer - 1) + N; i < pow(2, layer); i++){
			tree[i] = 1;
			ll[i] = i - pow(2, layer - 1) + 1;
			rr[i] = i - pow(2, layer - 1) + 1;
		}
		for (i = pow(2, layer - 1) - 1; i >= 1; i--){
			tree[i] = tree[i * 2] * tree[i * 2 + 1];
			ll[i] = ll[i * 2 + 1];
			rr[i] = rr[i * 2];
		}

		while (K--){
			cin >> instruct >> para[0] >> para[1];
			if (instruct == 'C'){
				if (para[1] > 0) tree[(int)pow(2, layer - 1) + para[0] - 1] = 1;
				else if (para[1] < 0) tree[(int)pow(2, layer - 1) + para[0] - 1] = -1;
				else tree[(int)pow(2, layer - 1) + para[0] - 1] = 0;

				for (i = ((int)pow(2, layer - 1) + para[0] - 1) / 2; i >= 1; i /= 2){
					tree[i] = tree[i * 2] * tree[i * 2 + 1];
				}
			}
			else {
				ans = ask(para[0], para[1], 1);
				if (ans > 0) cout << '+';
				else if (ans < 0) cout << '-';
				else cout << '0';
			}
		}
		cout << endl;
	}
	return 0;
}