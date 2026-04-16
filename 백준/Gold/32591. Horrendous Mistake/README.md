# [32591. Horrendous Mistake](https://www.acmicpc.net/problem/32591)

## 문제
While looking through the Grand Archive of Problematic Code, you found this horrendous mistake in one of the code snippets. In this code, they tried to calculate the sum of an array, but got indices and values mixed up. The code of this 
sum
 function is shown in Figure H.1.











long long sum(vector<int> a) {
    long long ans = 0;
    for (int x : a)
        ans += a[x];
    return ans;
}







def sum(a: list[int]) -> int:
    ans = 0
    for x in a:
        ans += a[x]
    return ans











long sum(int[] a) {
    long ans = 0;
    for (int x : a)
        ans += a[x];
    return ans;
}







fun sum(a: List<Int>): Long {
    var ans = 0L
    for (x in a)
        ans += a[x]
    return ans
}










Figure H.1: The function 
sum
 intends to calculate the sum of an array, but 
x
 refers to a value in the array, instead of an index. The code is shown in C++ and Python in the top row, and Java and Kotlin in the bottom row.


You wonder how this function behaves exactly, and decide to thoroughly test it. Starting with some initial array, you apply a sequence of updates. For each update, you change one of the values of the array. You wonder what the value of the function is after each update.

## 예제 입력 1
```
5
0 0 3 2 0
4
1 1
0 4
3 4
1 4
```

## 예제 출력 1
```
6
10
9
8
```

## 예제 입력 2
```
5
4 2 2 4 2
3
0 1
4 3
2 3
```

## 예제 출력 2
```
10
13
16
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | C++17 / 수정 | 5028 KB | 116 ms | 488 B | 1년 전 |
