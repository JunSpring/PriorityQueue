#include <iostream>
#include "MaxPriorityQueue.h" // ��������� include��
using namespace std;

int main()
{
	int n = 20; // heap�� ũ�⸦ �����Ű���� �Ʒ� �ڵ�鿡�� ������ ����

	MaxPriorityQueue Q; // MaxPriorityQueue��ü�� Q��� �̸����� ������

	cout << "Insert: " << '\n';				
	for (int i = 0; i < 20; i++)
		Q.Insert(i + 1); // 1���� 20���� heap�� �߰���
	Q.Output(); // heap�� �����					

	cout << "Delete: " << '\n';
	Q.Delete(8);	// 8��° index�� ���� ������					
	Q.Output();		// heap�� �����

	cout << "Sort: " << '\n';				
	int size = Q.GetSize(); // heap�� size�� �޾ƿ�
	for (int k = 0; k < size; k++)
	{
		int max = Q.ExtractMax(); // heap�� �ִ밪�� �޾ƿ��� ������
		cout << max << ',';
	}
	cout << '\n';

	return 0;
}