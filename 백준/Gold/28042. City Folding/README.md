# [28042. City Folding](https://www.acmicpc.net/problem/28042)

## 문제
Joe’s bedroom is so dirty that the germs have developed civilization! They have communities and cities everywhere, and the bedroom is their world: Joe’s shoes are giant caves, his fishbowl is an ocean, his moldy pizza boxes are jungles, etc.


One of the biggest germ metropolis, Long City, is built on a long strip of paper left on the floor. It’s an awkward city layout, so the inhabitants decided to go three-dimensional: they will fold the strip several times and turn it into a stack! This way, transportation across the city will be much easier, by moving up and down across layers.


Specifically, the germs will repeat the following procedure $N$ times:




find the exact middle of the current strip;


then either fold the left side on top of the right side, or vice versa.




The result will be a stack of $2^N$ paper layers.


Amelia is a powerful and wealthy amoeba who inhabits Long City, and like everyone else, she’s looking forward to the folding. However, she has a particular preference: after the folding process is complete, she would like her home to end up in the $H$-th layer from the ground, because $H$ is her lucky number. To achieve this, Amelia can influence the folding process: at each of the $N$ steps, she can decide whether to fold the left side over the right side, or vice versa.


Now she needs your help to decide the exact sequence of folds to perform. According to Amelia, if you were to divide Long City into $2^N$ sections of equal length, her home would be on the $P$-th section from left to right. Given $N$, $P$, and $H$, find the answer she wants.


The figure below illustrates the first sample. Amelia’s home is on the fourth section of the strip, and after the three shown folds it ends up in the seventh layer from the ground.

## 예제 입력 1
```
3 4 7
```

## 예제 출력 1
```
LRL
```

## 예제 입력 2
```
4 16 16
```

## 예제 출력 2
```
LLLR
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 1 | C++17 / 수정 | 2020 KB | 0 ms | 948 B | 2년 전 |
