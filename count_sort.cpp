/*
  计数排序
  计数排序是一种稳定的排序算法，使用格外的数组count。 期中第i个元素就是待排序数组A中值等于i的元素的个数。
  然后根据数组count来将A中的元素排到正确的位置。 和桶排序类似。
  当输入元素是n个从0到k的整数是， 时间复杂度是O(n+k),是排序0到100之间最好的算法。
  1. 找出待排序列的数组中最大和最小的元素
  2. 统计数组中每个值为i的元素出现的个数， 存入数组c的第i项
  3. 对所有的计数累加（从cc中的第一个元素开始， 每一项和前一项相加）
  4. 反向填充目标数组， 将每个元素i放到新数组的第c（i）项， 每放一个元素c（i）-1
  
*/

#include <iostream>
using namespace std;

void count_sort(int a[])
{
  int len = sizeof(a)/sizeof(int);
  int temp[len];
  int max = a[0], min = a[0];
  for(int i : a){
    if(i > max){
      max = i;
    }
    if(i < min){
      min = i;
    }
  }
  // 这里k的大小是要排序的数组中，元素大小的极值差+1
  int k = max - min + 1;
  int count[k];
  
  for(int i = 0; i < len; i++) // 计算每个元素在序列中出现的次数
  {
    count[a[i]-min]++;
  }
  
  for(int i = 1; i < k; i++) // 计算位置信息
  {
    count[i] = count[i] + count[i-1];
  }
  
  memcpy(temp, a, sizeof(temp));
  
  for(int i = len - 1; i >= 0; i--) 
  {
    a[--count[temp[i]]] = temp[i];
  }
}

int main()
{
  int array[] = {10, 9, 8, 7, 6, 5, 4};
  count_sort(array, 0, 7, 11);
  for(int i = 0; i < 7; i++)
    {
      cout << array[i] << " ";
    }
  return 0;
}  

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
