#include "MaxPriorityQueue.h" // 헤더파일 include

// 두 변수의 값을 바꾸는 함수
void exchange(int& num1, int& num2) // 참조에 의한 호출
{
	// 임시변수를 선언 후 교환
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

// 생성자
MaxPriorityQueue::MaxPriorityQueue()
{
	for (int i = 0; i < 20; i++)
		heap[i] = 0;	// heap 초기화
	heapSize = 0;		// heapSize 초기화
}

// heap에 숫자를 추가하고 Max Heap을 유지하는 함수
void MaxPriorityQueue::Insert(int num)
{
	MaxPriorityQueue::MaxHeapInsert(num);
}

// 현재 heap을 요소를 출력하는 함수
void MaxPriorityQueue::Output()
{
	for (int i = 0; i < heapSize; i++) // heapSize만큼 반복
		cout << heap[i] << ",";
	cout << endl;
}

// 특정 index의 요소를 삭제하고 Max Heap을 유지하는 함수
void MaxPriorityQueue::Delete(int index)
{
	MaxPriorityQueue::MaxHeapDelete(index);
}

// 현재 heap의 size를 return하는 함수
int MaxPriorityQueue::GetSize()
{
	return heapSize;
}

// heap의 맨 위를 return하고 Max Heap을 유지
int MaxPriorityQueue::ExtractMax()
{
	int max = heap[0];
	heap[0] = heap[--heapSize];
	MaxPriorityQueue::MaxHeapify(0);
	return max;
}

// i번째 노드의 왼쪽 자식 노드를 return
int MaxPriorityQueue::LEFT(int i)
{
	return 2 * i + 1;
}

// i번째 노드의 오른쪽 자식 노드를 return
int MaxPriorityQueue::RIGHT(int i)
{
	return 2 * i + 2;
}

// i번째 노드의 부모 노드를 return
int MaxPriorityQueue::PARENT(int i)
{
	return (i - 1) / 2;
}

// 특정 노드를 Max Heap에 맞는 위치로 이동
void MaxPriorityQueue::MaxHeapify(int i)
{
	int l = LEFT(i);	// 왼쪽 자식 노드 index
	int r = RIGHT(i);	// 오른쪽 자식 노드 index

	// i번째 노드, l번째 노드와 r번째 노드 중 가장 큰 값의 노드 index를 구함
	int largest;
	if (l <= heapSize - 1 && heap[l] > heap[i])
		largest = l;
	else
		largest = i;
	if (r <= heapSize - 1 && heap[r] > heap[largest])
		largest = r;

	// 가장 큰 값의 노드 index가 l이나 r이면
	if (largest != i)
	{
		exchange(heap[i], heap[largest]);		// 교환함
		MaxPriorityQueue::MaxHeapify(largest);	// 교환된 자식 노드의 index로 재귀함수를 실행함
	}
}

// i번째 노드의 값을 key로 변경 후 Max Heap에 맞는 위치로 이동하는 함수
void MaxPriorityQueue::HeapIncreaseKey(int i, int key)
{
	heap[i] = key;
	while (i > 0 && heap[MaxPriorityQueue::PARENT(i)] < heap[i])
	{
		exchange(heap[i], heap[MaxPriorityQueue::PARENT(i)]);
		i = PARENT(i);
	}
}

// key를 Max Heap에 추가 후 Max Heap 유지하는 함수
void MaxPriorityQueue::MaxHeapInsert(int key)
{
	heap[heapSize++] = INT_MIN;
	HeapIncreaseKey(heapSize - 1, key);
}

// i번째 노드를 삭제 후 Max Heap 유지하는 함수
void MaxPriorityQueue::MaxHeapDelete(int i)
{
	heap[i] = heap[--heapSize];
	MaxPriorityQueue::MaxHeapify(i);
}