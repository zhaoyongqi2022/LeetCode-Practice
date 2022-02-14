#include <iostream>
using namespace std;

#include<vector>


vector<int> path;
vector<vector<int>> result;

void backtracking(int n, int k, int startIndex) {
	if (path.size() == k) {
		result.push_back(path);
		return;
	}

	for (int i = startIndex; i <= n; i++) { //��֦������������forѭ���ı������������forѭ����ʼλ��֮���Ԫ�ظ���������������Ҫ��Ԫ�ظ�����û�б�Ҫ�ٽ��б�����
		// 1.��ѡ�������path.size()
		// 2.����Ҫ��Ԫ�ظ�����k-path.size()
		// 3.forѭ���������Դ�n-(k-path.size())+1��ʼ���� �������+1�����Լ��ٸ��������ԣ�
		path.push_back(i);
		backtracking(n, k, i + 1);
		path.pop_back();
	}
}

//int main()
//{
//	int n = 4;
//	int k = 2;
//	int startIndex = 0;
//	backtracking(n, k, startIndex);
//	system("pause");
//	return 0;
//}