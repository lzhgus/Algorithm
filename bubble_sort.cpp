/*
  冒泡算法
  1.从列表的第一个数字到倒数第二个数字，逐个检查， 若某一位子上的数字大于它的下一位， 则他和他的下一位交换。
  2.重复1步骤，直到再也不能交换。
  冒泡排序的平均时间复杂度和插入排序一样，O(n^2), 但是是原地排序， 不需要额外的存储空间。
*/

#include <iostream>
using namespace std;
const int SIZE = 8;
viod bubble_sort(int a[], int n)
{
  int i, j, temp;
  for(i = 0; i < n-1; i++){
    for(j = 0; j < n-1; j++)
    {
      if(a[j] > a[j+1])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}
int main()
{
  int a[SIZE] = {1, 5, 3, 9, 6, 0 , 5, 2, 8};
  int i;
  bubble_sort(a, SIZE);
  for(i = 0; i < SIZE; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}
