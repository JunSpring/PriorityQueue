#include "MaxPriorityQueue.h" // ������� include

// �� ������ ���� �ٲٴ� �Լ�
void exchange(int& num1, int& num2) // ������ ���� ȣ��
{
	// �ӽú����� ���� �� ��ȯ
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

// ������
MaxPriorityQueue::MaxPriorityQueue()
{
	for (int i = 0; i < 20; i++)
		heap[i] = 0;	// heap �ʱ�ȭ
	heapSize = 0;		// heapSize �ʱ�ȭ
}

// heap�� ���ڸ� �߰��ϰ� Max Heap�� �����ϴ� �Լ�
void MaxPriorityQueue::Insert(int num)
{
	MaxPriorityQueue::MaxHeapInsert(num);
}

// ���� heap�� ��Ҹ� ����ϴ� �Լ�
void MaxPriorityQueue::Output()
{
	for (int i = 0; i < heapSize; i++) // heapSize��ŭ �ݺ�
		cout << heap[i] << ",";
	cout << endl;
}

// Ư�� index�� ��Ҹ� �����ϰ� Max Heap�� �����ϴ� �Լ�
void MaxPriorityQueue::Delete(int index)
{
	MaxPriorityQueue::MaxHeapDelete(index);
}

// ���� heap�� size�� return�ϴ� �Լ�
int MaxPriorityQueue::GetSize()
{
	return heapSize;
}

// heap�� �� ���� return�ϰ� Max Heap�� ����
int MaxPriorityQueue::ExtractMax()
{
	int max = heap[0];
	heap[0] = heap[--heapSize];
	MaxPriorityQueue::MaxHeapify(0);
	return max;
}

// i��° ����� ���� �ڽ� ��带 return
int MaxPriorityQueue::LEFT(int i)
{
	return 2 * i + 1;
}

// i��° ����� ������ �ڽ� ��带 return
int MaxPriorityQueue::RIGHT(int i)
{
	return 2 * i + 2;
}

// i��° ����� �θ� ��带 return
int MaxPriorityQueue::PARENT(int i)
{
	return (i - 1) / 2;
}

// Ư�� ��带 Max Heap�� �´� ��ġ�� �̵�
void MaxPriorityQueue::MaxHeapify(int i)
{
	int l = LEFT(i);	// ���� �ڽ� ��� index
	int r = RIGHT(i);	// ������ �ڽ� ��� index

	// i��° ���, l��° ���� r��° ��� �� ���� ū ���� ��� index�� ����
	int largest;
	if (l <= heapSize - 1 && heap[l] > heap[i])
		largest = l;
	else
		largest = i;
	if (r <= heapSize - 1 && heap[r] > heap[largest])
		largest = r;

	// ���� ū ���� ��� index�� l�̳� r�̸�
	if (largest != i)
	{
		exchange(heap[i], heap[largest]);		// ��ȯ��
		MaxPriorityQueue::MaxHeapify(largest);	// ��ȯ�� �ڽ� ����� index�� ����Լ��� ������
	}
}

// i��° ����� ���� key�� ���� �� Max Heap�� �´� ��ġ�� �̵��ϴ� �Լ�
void MaxPriorityQueue::HeapIncreaseKey(int i, int key)
{
	heap[i] = key;
	while (i > 0 && heap[MaxPriorityQueue::PARENT(i)] < heap[i])
	{
		exchange(heap[i], heap[MaxPriorityQueue::PARENT(i)]);
		i = PARENT(i);
	}
}

// key�� Max Heap�� �߰� �� Max Heap �����ϴ� �Լ�
void MaxPriorityQueue::MaxHeapInsert(int key)
{
	heap[heapSize++] = INT_MIN;
	HeapIncreaseKey(heapSize - 1, key);
}

// i��° ��带 ���� �� Max Heap �����ϴ� �Լ�
void MaxPriorityQueue::MaxHeapDelete(int i)
{
	heap[i] = heap[--heapSize];
	MaxPriorityQueue::MaxHeapify(i);
}