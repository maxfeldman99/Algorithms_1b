#include <iostream>
#include <time.h>


using namespace std;

int min_max_element_in_array(int *arr, int size) {
	int min, max;

	int count = 0;
	min = max = arr[0];
	for (int i = 0; i < size; i++) {
		count++;
		if (arr[i] < min) {
			min = arr[i];


		}
		else {
			count++;
			if (arr[i] > max) {
				max = arr[i];

			}
		}
	}

	return count;
}

void shuffleArray(int *arr, int size) {  // for second method
	int j;
	int temp;
	for (int i = 0; i < size; i++)
	{
		j = rand() % (i + 1);
		//swap//
		temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;


	}
}

void assignArr_method_2(int arr_size, int run_times) {
	int *arr;
	int finalCount = 0;
	arr = new int[arr_size];
	srand((unsigned)time(0));
	for (int i = 0; i < arr_size; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < run_times; i++) {
		shuffleArray(arr, arr_size);
		finalCount = finalCount + min_max_element_in_array(arr, arr_size);

	}
	delete(arr);
	cout << "number of avg comparisons (  Permutations ) : " << finalCount / run_times << endl;


}

void assignArr_method_1(int arr_size, int run_times) {
	int *arr;
	int finalCount = 0;
	arr = new int[arr_size];
	srand((unsigned)time(0));
	for (int i = 0; i < run_times; i++) {
		for (int j = 0; j <arr_size; j++) {
			arr[j] = rand() % arr_size + 1;

		}
		finalCount = finalCount + min_max_element_in_array(arr, arr_size);
	}
	delete(arr);
	cout << "number of avg comparisons  (random arrays) : " << finalCount / run_times << endl;



}

void main() {
	assignArr_method_1(1000, 100000);
	assignArr_method_2(1000, 100000);
	system("pause");
}