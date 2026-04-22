# [6474. Palindromes](https://www.acmicpc.net/problem/6474)

## 문제
A regular palindrome is a string of numbers or letters that is the same forward as backward.  For example, the string "ABCDEDCBA" is a palindrome because it is the same when the string is read from left to right as when the string is read from right to left. 


A mirrored string is a string for which when each of the elements of the string is changed to its reverse (if it has a reverse) and the string is read backwards the result is the same as the original string. For example, the string "3AIAE" is a mirrored string because "A" and "I" are their own reverses, and "3" and "E" are each others' reverses. 


A mirrored palindrome is a string that meets the criteria of a regular palindrome and the criteria of a mirrored string.  The string "ATOYOTA" is a mirrored palindrome because if the string is read backwards, the string is the same as the original and because if each of the characters is replaced by its reverse and the result is read backwards, the result is the same as the original string.  Of course, "A", "T", "O", and "Y" are all their own reverses. 


A list of all valid characters and their reverses is as follows. 



Character  Reverse   Character  Reverse   Character  Reverse 
    A         A          M         M          Y         Y 
    B                    N                    Z         5 
    C                    O         O          1         1 
    D                    P                    2         S 
    E         3          Q                    3         E 
    F                    R                    4 
    G                    S         2          5         Z 
    H         H          T         T          6 
    I         I          U         U          7 
    J         L          V         V          8         8 
    K                    W         W          9 
    L         J          X         X 



* Note that 0 (zero) and O (the letter) are considered the same character and therefore ONLY the letter "O" is a valid character.

## 예제 입력 1
```
NOTAPALINDROME
ISAPALINILAPASI
A3MEA
ATOYOTA
```

## 예제 출력 1
```
NOTAPALINDROME -- is not a palindrome.

ISAPALINILAPASI -- is a palindrome.

A3MEA -- is a mirrored string.

ATOYOTA -- is a mirrored palindrome.
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 5 | C++17 / 수정 | 2028 KB | 0 ms | 872 B | 3년 전 |
