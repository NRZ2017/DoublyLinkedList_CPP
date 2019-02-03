#include "List.h"

int main()
{
	List<int> nums;
	nums.AddLast(3);
	nums.AddLast(4);
	nums.AddLast(5);
	nums.RemoveEnd();
	nums.RemoveFront();
	nums.AddFirst(35);

	system("PAUSE");
}