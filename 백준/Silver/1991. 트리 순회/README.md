# [1991. 트리 순회](https://www.acmicpc.net/problem/1991)

## 문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.




예를 들어 위와 같은 이진 트리가 입력되면,




전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)


중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)


후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)




가 된다.

## 예제 입력 1
```
7
A B C
B D .
C E F
E . .
F . G
D . .
G . .
```

## 예제 출력 1
```
ABDCEFG
DBAECFG
DBEGFCA
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Silver 1 | C++17 / 수정 | 2020 KB | 0 ms | 451 B | 2년 전 |
