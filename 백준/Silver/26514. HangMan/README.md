# [26514. HangMan](https://www.acmicpc.net/problem/26514)

## 문제
In the classic blackboard game HangMan you are given a word and attempt to guess the word by choosing a series of letters. In this program, you must determine if the provided letters are contained in the word prior to a body figure being drawn. One body part is added for each letter not contained in the word. The body figure below consists of the head shown by the letter "O", two body parts "|", 2 arms shown by equal signs "=", 2 hands shown by asterisks "*", and legs shown using a forward slash "/"and a back slash "\", 9 parts in all, drawn in order, top to bottom - from left to right, as shown below. Once all the letters of the word are found, the game ends and no further letters are read. The game also ends once the figure is completed. If no body parts are drawn, print the word “SAFE”.



  O
*=|=*
  |
 / \

## 예제 입력 1
```
4
APLUS 8 A S E U G P I J
UIL 9 A B C D E F G H J
SALTLICK 9 E F G H I J K M N
GOOGLE 4 G O L E
```

## 예제 출력 1
```
APLUS
  O
+=|

UIL
  O
+=|=+
  |
 / \

SALTLICK
  O
+=|=+
  |

GOOGLE
SAFE
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 3 | C++17 / 수정 | 2024 KB | 0 ms | 926 B | 3년 전 |
