# [20026. Fix Wiring](https://www.acmicpc.net/problem/20026)

## 문제
You are in the spaceship 
The Skeld
 with your fellow crewmates. However, while checking the central power system, 

you found out that one crucial wiring installation of the central power system has been sabotaged. To prevent an engine failure, you should quickly fix the installation.


The installation consists of $N$ nodes and $M=\frac{N(N-1)}{2}$ wires. All possible pairs of distinct nodes in the installation are connected with a wire. Originally, each of the $M$ wires had exactly one tag attached to it. Each tag has a positive integer value, and different tags may have the same value. However, due to the sabotage, all the tags were removed from the wires and left on the floor. Fortunately, you gathered all $M$ tags from the ground. Now, in order to fix the installation, you have to trigger the reboot sequence by re-attaching all the tags back to the wires twice.


For an installation where all wires have a tag on them, let's define 
the cost of an installation 
as the cost of its minimum spanning tree, that is, the minimum cost of a subset of wires such that all nodes are connected using only the given subset of wires. Here, the cost of the set of wires is defined as the sum of the tag values of all wires in the set.


The reboot sequence is triggered in two steps:

First, you should attach the tags to 
minimize
 the cost of the installation.

Then, after detaching all tags, you should attach the tags to 
maximize
 the cost of the installation.


Please compute the cost of each installation.

## 예제 입력 1
```
4
5 3 8 8 5 9
```

## 예제 출력 1
```
13 16
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Gold 3 | Java 11 / 수정 | 16976 KB | 168 ms | 1475 B | 1년 전 |
