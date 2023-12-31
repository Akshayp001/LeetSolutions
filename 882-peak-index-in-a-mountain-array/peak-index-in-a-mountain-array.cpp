class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (mid > 0 && mid < arr.size() - 1) {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                    return mid;
                } else if (arr[mid] < arr[mid + 1]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            } else {
               
                if (mid == 0) {
                    if (arr[mid] > arr[mid + 1]) {
                        return mid;
                    } else {
                        s = mid + 1;
                    }
                } else { 
                    if (arr[mid] > arr[mid - 1]) {
                        return mid;
                    } else {
                        e = mid - 1;
                    }
                }
            }
        }
        return -1; 
    }
};
