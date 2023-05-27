#include <iostream>
#include "MaxPriorityQueue.h" // 헤더파일을 include함
using namespace std;

int main()
{
	int n = 20; // heap의 크기를 저장시키지만 아래 코드들에서 쓰이지 않음

	MaxPriorityQueue Q; // MaxPriorityQueue객체를 Q라는 이름으로 생성함

	cout << "Insert: " << '\n';				
	for (int i = 0; i < 20; i++)
		Q.Insert(i + 1); // 1부터 20까지 heap에 추가함
	Q.Output(); // heap을 출력함					

	cout << "Delete: " << '\n';
	Q.Delete(8);	// 8번째 index의 값을 삭제함					
	Q.Output();		// heap을 출력함

	cout << "Sort: " << '\n';				
	int size = Q.GetSize(); // heap의 size을 받아옴
	for (int k = 0; k < size; k++)
	{
		int max = Q.ExtractMax(); // heap의 최대값을 받아오고 삭제함
		cout << max << ',';
	}
	cout << '\n';

	return 0;
}