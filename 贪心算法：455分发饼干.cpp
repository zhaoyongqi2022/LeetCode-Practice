#include <iostream>
using namespace std;

#include<vector>
#include<algorithm>


int cookiesDistribution(vector<int>& g, vector<int>& s) {
	//�ȶ�����ı��ɺͺ��������������
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());

	//��������Ĵ�С
	int gLength = g.size();
	int sLength = s.size();

	//��ʼ����������
	int count = 0;

	////����1

	////���forѭ�����Ʊ���
	//for (int i = sLength - 1; i >= 0; i--) {
	//	//�ڲ�forѭ�����ƺ���
	//	for (int j = gLength - 1; j >= 0; j--) {
	//		if (s[i] >= g[j]) {
	//			//��������֮�����+1
	//			count++;
	//			//�´α���ʱ�ӵ�ǰλ�õ�ǰһ����ʼ����
	//			gLength=j;
	//			break;
	//		}
	//	}
	//}

	//����2
	int index = sLength - 1;
	for (int i = gLength - 1; i >= 0; i--) {
		if (index >= 0 && s[index] >= g[i]) {
			count++;
			index--;
		}
	}
	//�ڷ���2�У��ȱ����˺��ӣ���Ȧ�������ɣ�ÿ����������������-1���������򵥡�
	//���ɣ��������ɲ�û��������һ��forѭ��������ֱ�Ӳ����Լ��ķ�ʽ�����ǳ��õļ���
	return count;
}



//int main()
//{
//	vector<int> g = { 1, 2, 7, 10 };
//	vector<int> s = { 1,3,5,9, };
//	int result = cookiesDistribution(g, s);
//
//
//	system("pause");
//	return 0;
//}