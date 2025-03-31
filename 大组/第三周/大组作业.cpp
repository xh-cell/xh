#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZES 3
#define SMALL_DATA_SIZE 100
#define SMALL_DATA_REPEAT 100000

// 插入排序
void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 归并排序
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 快速排序（递归版）
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 计数排序
void countSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < n; i++) count[arr[i]]++;
    int index = 0;
    for (int i = 0; i <= max; i++) while (count[i]--) arr[index++] = i;
    free(count);
}

// 生成测试数据并写入文件
void generateData(const char *filename, int size) {
    FILE *file = fopen(filename, "w");
    if (!file) return;
    srand(time(NULL));
    for (int i = 0; i < size; i++) fprintf(file, "%d\n", rand() % 10000);
    fclose(file);
}

// 读取数据文件
void readData(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "r");
    if (!file) return;
    for (int i = 0; i < size; i++) fscanf(file, "%d", &arr[i]);
    fclose(file);
}

int main() {
    int sizes[DATA_SIZES] = {10000, 50000, 200000};
    char filename[] = "data.txt";
    for (int i = 0; i < DATA_SIZES; i++) {
        generateData(filename, sizes[i]);
        int *arr = (int *)malloc(sizes[i] * sizeof(int));
        readData(filename, arr, sizes[i]);
        clock_t start = clock();
        quickSort(arr, 0, sizes[i] - 1);
        clock_t end = clock();
        printf("QuickSort on %d elements: %lf seconds\n", sizes[i], (double)(end - start) / CLOCKS_PER_SEC);
        free(arr);
    }
    return 0;
}

//第一题 
#include <stdio.h>
// 交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 排序函数
void sortArray(int *nums, int numsSize) {
    int p0 = 0;
    int p2 = numsSize - 1;
    int i = 0;
    while (i <= p2) {
        if (nums[i] == 0) {
            swap(&nums[i], &nums[p0]);
            p0++;
            i++;
        } else if (nums[i] == 2) {
            swap(&nums[i], &nums[p2]);
            p2--;
        } else {
            i++;
        }
    }
}

//第二题
#include <stdio.h>

// 交换函数
void swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 划分函数
int partition(int *nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap2(&nums[i], &nums[j]);
        }
    }
    swap2(&nums[i + 1], &nums[right]);
    return i + 1;
}

// 查找第k小元素函数
int findKthSmallest(int *nums, int left, int right, int k) {
    int pivotIndex = partition(nums, left, right);
    if (pivotIndex == k) {
        return nums[pivotIndex];
    } else if (pivotIndex > k) {
        return findKthSmallest(nums, left, pivotIndex - 1, k);
    } else {
        return findKthSmallest(nums, pivotIndex + 1, right, k);
    }
}
