#pragma once //�ߺ� include ����

#include <iostream> // �б� �� ���⿡ ���� �������
#include <climits>	// INT_MIN�� �ҷ����� ���� �������
using namespace std; 

// Ŭ���� ����
class MaxPriorityQueue
{
public:
	// functions
	MaxPriorityQueue();		// heap�� heapSize�� �ʱ�ȭ
	void Insert(int num);	// ���� ���� �� Max Heap ����
	void Output();			// ���� heap�� ���
	void Delete(int index); // Ư�� index ��Ҹ� �� �ڷ� ���� �� Max Heap ����
	int GetSize();			// ���� heap size�� ����
	int ExtractMax();		// �ִ밪�� �����ϰ� Max Heap ����

private:
	// variables
	int heap[20];	// main������ n�� �����Ͽ� �迭�� ����� �ڵ尡 �����Ƿ�
					// �������� ������ ũ�⸦ �����Ͽ� �迭 ����
	int heapSize;	// Heap Size

	// functions
	int LEFT(int i);						// i��° ����� ���� �ڽ� ����� index ����
	int RIGHT(int i);						// i��° ����� ���� �ڽ� ����� index ����
	int PARENT(int i);						// i��° ����� �θ� ����� index ����
	void MaxHeapify(int i);					// Ư�� ��带 Max Heap�� �´� ��ġ�� �̵�
	void HeapIncreaseKey(int i, int key);	// i��° ����� ���� key�� ���� �� Max Heap�� �´� ��ġ�� �̵�
	void MaxHeapInsert(int key);			// key�� Max Heap�� �߰� �� Max Heap ����
	void MaxHeapDelete(int i);				// i��° ��带 ���� �� Max Heap ����
};