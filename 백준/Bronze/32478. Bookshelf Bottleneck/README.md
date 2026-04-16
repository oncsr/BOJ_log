# [32478. Bookshelf Bottleneck](https://www.acmicpc.net/problem/32478)

## 문제
Brianna is a bookworm. At home, she has a big bookshelf with all her favourite books. She has a large collection ranging from detective novels and science-fiction novels to biographies.


Recently, Brianna has expanded her collection with $n$ graphic novels. However, the new books currently lie around everywhere and form huge stacks on the floor. In the meantime, one of the shelf boards has collected dust and random household utensils that do not belong there. The new books just lying around have become too much to bear, and Brianna finally decided to put them on this shelf board. To do so, she first has to make room on it.




Figure B.1: Visualization of Sample Input 3.


Brianna wants to arrange the books in a single horizontal line without stacking multiple books on top of each other. While the shelf is wide enough to hold all books without problems, it takes time to make room on the shelf. Therefore, Brianna wants to minimize the width of the part of the shelf that she needs to clear.


Each book can be described as a cuboid with three side lengths $l$, $w$, and $h$. Since the room above the shelf board is limited by the next shelf board above it, she can only fit a book vertically if its vertical side length is at most the distance $H$ between the two shelf boards. Brianna may rotate each book in three-dimensional space as she wants. It is guaranteed that the shelf is deep enough so that the books will not fall off, no matter the orientation. However, all books must stand properly on the shelf board, meaning that every book touches the shelf board along an entire face and not just by an edge.


What is the minimum width of shelf Brianna's books need?

## 예제 입력 1
```
1 3
10 2 5
```

## 예제 출력 1
```
5
```

## 예제 입력 2
```
1 3
10 4 5
```

## 예제 출력 2
```
impossible
```

## 예제 입력 3
```
2 10
10 2 10
2 3 4
```

## 예제 출력 3
```
4
```

## 예제 입력 4
```
3 1000000000
1000000000 1000000000 1000000000
1000000000 1000000000 1000000000
1000000000 1000000000 1000000000
```

## 예제 출력 4
```
3000000000
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Bronze 2 | C++17 / 수정 | 2020 KB | 32 ms | 495 B | 1년 전 |
