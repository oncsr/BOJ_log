# [26047. Journals](https://www.acmicpc.net/problem/26047)

## 문제
There is a stack of journals on Cimrman’s desk. The journals are printed in Cimrman’s own printing house. Each journal front cover is charged slightly positively and the back cover is charged slightly negatively. Different charges of the front and back cover help the journals to stick better to each other when they are stacked in a single stack one upon another. When two adjacent journals in the stack are positioned in such a way that either their front covers or their back covers touch each other, the repulsion between the same charges in both covers makes the stack more prone to collapse.


Cimrman wants his stack to be arranged in such a way that no two adjacent journals in the stack produce the repulsion.


To set the stack into appropriate order he can repeat a single operation consisting of three moves. In the first move (which may be empty), Cimrman puts aside some number of journals from the top of the stack without changing their order. Next, he takes a pile of one or more journals from the new top of the stack, flips this pile over, and puts it back on the stack. Finally, he moves back onto the stack the journals removed from the stack in the first step. Again, no change of the journal order appears in this move.


Obviously, Cimrman wants to perform as few operations as possible. The number of journals moved or flipped in one operation is not important, the journals paper is light enough.

## 예제 입력 1
```
+-+-+--+-+
```

## 예제 출력 1
```
1
```

## 예제 입력 2
```
+--++-
```

## 예제 출력 2
```
1
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 2 | C++17 / 수정 | 2020 KB | 4 ms | 238 B | 2년 전 |
