# [6951. Packet Routing](https://www.acmicpc.net/problem/6951)

## 문제
The date is October 29th, 1969. Today, scientists at UCLA made history by exchanging data between two computers over a network. The transmission wasn't very spectacular: only the first two letters of the word 
login
 were received before the system crashed. Nevertheless, the researchers are beginning to design larger computer networks and they need your help.


A computer network is a collection of $N$ $(2 \le N \le 100)$ computers and $W$ wires. The computers are identified by the numbers $1, 2, \dots, N$. Each wire connects exactly two computers, allowing packets of data to flow in both directions between the computers. The wires are placed so that it is possible to send packets (directly or indirectly by passing through other computers) between every pair of computers. In fact, the placement of the wires has been optimized so that there is exactly one path between every pair of computers. If the packet travels along several wires to get from the source computer to the destination computer, the time needed for the packet to travel along this path is the sum of the times required for the packet to travel along each individual wire. You are to write a program that computes the amount of time needed for a packet to travel between a given pair of distinct computers.

## 예제 입력 1
```
3 2 3
1 2 100
2 3 150
2 1
2 3
1 3
```

## 예제 출력 1
```
100
150
250
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 5 | C++17 / 수정 | 2024 KB | 4 ms | 735 B | 1년 전 |
