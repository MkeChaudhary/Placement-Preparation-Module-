#include <stdio.h>
 
// Function to find the total number of times the array is rotated
int findRotationCount(int nums[], int n)
{
    // search space is nums[low…high]
    int low = 0, high = n - 1;
 
    // loop till the search space is exhausted
    while (low <= high)
    {
        // if the search space is already sorted, we have
        // found the minimum element (at index `low`)
        if (nums[low] <= nums[high]) {
            return low;
        }
 
        int mid = (low + high) / 2;
 
        // find the next and previous element of the `mid` element
        // (in a circular manner)
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;
 
        // if the `mid` element is less than both its next and previous
        // neighbor, it is the array's minimum element
 
        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
            return mid;
        }
 
        // if nums[mid…high] is sorted, and `mid` is not the minimum element,
        // then the pivot element cannot be present in nums[mid…high],
        // discard nums[mid…high] and search in the left half
 
        else if (nums[mid] <= nums[high]) {
            high = mid - 1;
        }
 
        // if nums[low…mid] is sorted, then the pivot element cannot be present in it;
        // discard nums[low…mid] and search in the right half
 
        else if (nums[mid] >= nums[low]) {
            low = mid + 1;
        }
    }
 
    // invalid input
    return -1;
}
 
int main(void)
{
    int nums[] = { 8, 9, 10, 2, 5, 6 };
    int n = sizeof(nums) / sizeof(nums[0]);
 
    int count = findRotationCount(nums, n);
    printf("Array is rotated %d times", count);
 
    return 0;
}





















// #include<bits/stdc++.h>
// using namespace std;

// int bs(int arr[], int n)
// {
//     int start=0;
//     int end=n-1;
//     //int res;
//     while (start<=end)
//     {
//         int mid = start+(end-start)/2;

//         int next = (mid+1)%n;
//         int prev = (mid+n-1)%n;

//         // if(k==arr[mid])
//         // {
//         //     res = mid;
//         //     start = mid+1;
//         // }
//         // else if(k < arr[mid])
//         // {
//         //     end = mid-1; 
//         // }
//         // else if(k > arr[mid] )
//         // {
//         //     start = mid+1;
//         // }
//         // other


//         //osm
//         if(arr[mid] <= arr[next] && arr[mid] <= arr[prev])
//         {
//             return mid;
//         }


//         if(arr[start] <= arr[mid])
//         {
//             start = mid +1;
//         }
//         else if (arr[mid] <= arr[mid])
//         {
//             end = mid-1;
//         }
        

//     }
//     return -1;
// }


// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n;i++)
//     {
//         cin>>arr[i];
//     }

//     int res = bs(arr, n);
//     cout<<res;

// }