#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  // ここにプログラムを追記
  // (ここで"試合結果の表"の2次元配列を宣言)

  vector<vector<char>> data(N,vector<char>(N,'-'));

  for (int i = 0; i < M; i++) {
    A.at(i)--; B.at(i)--; // 配列が0からN-1の箱に1からnまでの試合数の要素が入ってるため、それぞれ-1する
    data.at(A.at(i)).at(B.at(i)) = 'o';
    data.at(B.at(i)).at(A.at(i)) = 'x';
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
        cout << data.at(i).at(j);
        if (j == N - 1)
        {
            cout << endl;
        }
        else {
            cout << " ";
        }
    }
  }
}
