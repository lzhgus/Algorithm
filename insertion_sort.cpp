/* 插入排序
   1.新建一个空列表，用于保存已排序的有序数列
   2.从原数列中取一个数， 将其插入“有序数列”中，使其仍旧保持有序状态。
   3.重复2号步骤， 直到原序列为空。
   时间复杂度 O(n^2).
*/

#include <iostream>
using namespace std;

void insertion_sort(int a[], int length)
{
  int temp;
  for(int index = 1; index < length; index++)
  {
    temp = a[index];
    int position = index;
    while(position >= 0 && a[position - 1] > temp)
    {
      a[position] = a[position - 1];
      position--;
    }
    a[position] = temp;
  }
}

int main()
{
  int a[] = {10, 3, 8, 5, 7, 3, 0};
  insertion_sort(a, 7);
  for(int i = 0; i < 7; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}
