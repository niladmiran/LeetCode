//
// Created by jacob on 2021/3/26.
//

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/

bool isBadVersion(int version){
    return true;
}


int firstBadVersion(int left, int right){
    if (left == right)   return left;
    int mid = left + (right - left) / 2;
    if (isBadVersion(mid))
        return firstBadVersion(left, mid);
    else
        return firstBadVersion(mid + 1, right);
}

int firstBadVersion(int n) {
    return firstBadVersion(0, n);
}