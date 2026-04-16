# [3157. osmo](https://www.acmicpc.net/problem/3157)

## 문제
Word search is a very popular enigmatic game that consists of a table with letters arranged in N rows and N columns and a list of words we have to search for. 


To solve an instance of word search we, for each word from the list, find all appearances of that word in the table and cross out all the letters forming that particular appearance. The word can start anywhere and lay in any of the eight directions (up, down, left, right and the four diagonal directions). 


Reading all non-crossed letters in row-major order (up to down and in each row from left to right) gives the solution of the word search puzzle. 


Write a program that will find the solution of the given puzzle.

## 예제 입력 1
```
2
ab
cd
1
ad
```

## 예제 출력 1
```
bc
```

## 예제 입력 2
```
5
patka
guska
macka
klopa
krava
4
patka
guska
macka
krava
```

## 예제 출력 2
```
klopa
```

## 예제 입력 3
```
4
rast
plso
tajv
pnez
6
rast
alan
nt
past
taj
bonus
```

## 예제 출력 3
```
povez
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | Java 11 / 수정 | 39548 KB | 328 ms | 1471 B | 1년 전 |
