/* 桶排序
   1. 设置一个定量的数组作为空桶子
   2. 寻访序列， 并且把项目一个一个放到对应的桶子去。
   3. 对每个不是空的桶子进行排序。
   4. 从不是空的桶子里把项目再放回原来的序列中。
   
   时间复杂度O(n)
*/

#include <iostream>
#include <cstring>
using namespace std;

void bucket_sort(int a[], int from, int len, int max)
{
  int temp[len];   // 待排序列 
  int count[max];  // 桶
  
  for(int i = 0; i < len; i++)  // 计算每个元素在序列中出现的次数
  {
    count[a[from+i]]++;
  }
  
  // 比如说 待排 2 8 9 4 2 3   则 count[2] = 2
  
  for(int i = 1; i < max; i++) // 计算位置信息
  {
    count[i] = count[i] + count[i-1];  // 意思为有多少个数是小于或者等于i的
  }
  
  memcpy(temp, a, sizeof(temp));
  
  for(int k = len-1; k >= 0; k--) // 为了保持稳定性从最后一个开始
  {
    a[--count[temp[k]]] = temp[k]; // position + 1 = count
  }
}

int main()
{
  int array[] = {10, 9, 8, 7, 6, 5, 4};
  bucket_sort(array, 0, 7, 11);
  for(int i = 0; i < 7; i++)
    {
      cout << array[i] << " ";
    }
  return 0;
}  















