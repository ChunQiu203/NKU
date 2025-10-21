#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
void QSLastBase(int low, int high, int arr[])
{
	if (low >= high)
		return;
	int i = low;
	int j = high;
	//基准为最后一位数
	int base = arr[high];
	while (i < j)
	{
		while (arr[i] <= base && i < j) {
			i++;
		}
		while (arr[j] >= base && i < j) {
			j--;
		}
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[high], arr[i]);
	QSLastBase(low, i - 1, arr);
	QSLastBase(i + 1, high, arr);
}
void QSFirstBase(int low, int high, int arr[])
{
	if (low >= high)
		return;
	int i = low;
	int j = high;
	//基准为第一个数
	int base = arr[low];
	while (i < j)
	{
		while (arr[j] >= base && i < j) {
			j--;
		}
		while (arr[i] <= base && i < j) {
			i++;
		}
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[low], arr[i]);
	QSFirstBase(low, i - 1, arr);
	QSFirstBase(i + 1, high, arr);
}
void QSRandomBase(int low, int high, int arr[])
{
	if (low >= high)
		return;
	int i = low;
	int j = high;
	//基准为随机数
	int index = (rand() % (high - low + 1)) + low;
	int base = arr[index];
	swap(arr[index], arr[low]);
	while (i < j)
	{
		while (arr[j] >= base && i < j) {
			j--;
		}
		while (arr[i] <= base && i < j) {
			i++;
		}
		if (i < j)
		{
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[low], arr[i]);
	QSRandomBase(low, i - 1, arr);
	QSRandomBase(i + 1, high, arr);
}
int main()
{
	int a[10] = {3, 5, 8, 1, 2, 9, 4, 7, 6};
	QSLastBase(0, 8, a);
	for (int i = 0; i < 9; i++) {
		cout << a[i] << " ";
	}
	return 0;
}