#include "List.h"

int main()
{
	List<int> nums;

	/*while (true)
	{
		nums.AddFirst(1);
		nums.RemoveFront();
	}*/


	nums.AddLast(3);
	nums.AddLast(4);
	nums.AddLast(5);
	nums.RemoveEnd();
	nums.RemoveFront();
	nums.AddFirst(35);
	;

	system("PAUSE");
}