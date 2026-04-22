# [25276. Sperhling](https://www.acmicpc.net/problem/25276)

## 문제
On her spare time Caitlin loves to do speed typing. Unfortunately Caitlyn was never good at spelling. So what often happens is that Catelin makes a mistake spelling a word, and has to go back and fix her typo. One word in particular that Caitlynn has a hard time spelling is the word 
mischievous
. Catelyn usually spells it 
mischevious
 instead. In order to fix this typo, Caytlin needs to do 12 key presses.




Katelin thinks that no matter how much time she puts into speed typing, she will always make mistakes. But maybe she can get better at quickly fixing her mistakes. Katelyn would like you to help her with this.


Suppose that Caytlyn has just written the word $S_1$, but that she should have written $S_2$. Assume that the cursor is initially at the end of $S_1$, and that after fixing the typo, Caitlin needs to place the cursor at the end of $S_2$. Output the fewest number of key presses needed to make $S_1$ into $S_2$.


The keys you are allowed to use are




the left and right arrow keys.


the back space key.


the keys $
a
, \ldots, 
z
$.




You are not allowed to press back space or the left arrow key when the cursor is all the way to the left. You are also not allowed to press the right arrow key when the cursor is all the way to the right.

## 예제 입력 1
```
mischevious
mischievous
```

## 예제 출력 1
```
12
```

## 예제 입력 2
```
cerstermergerd
customer
```

## 예제 출력 2
```
20
```

## 예제 입력 3
```
caitlin
caitlynn
```

## 예제 출력 3
```
5
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 2024 KB | 0 ms | 210 B | 3년 전 |
