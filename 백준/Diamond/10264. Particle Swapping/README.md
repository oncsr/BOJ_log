# [10264. Particle Swapping](https://www.acmicpc.net/problem/10264)

## 문제
The research team of prof. Feynmansson is preparing a new groundbreaking experiment in particle physics. On a special plate they have prepared a system consisting of a number of nodes connected via wires
2
. In the beginning of the experiment a pair of particles appears at two different nodes of the system: one normal particle of matter appears at some node A, and one corresponding particle of antimatter appears at some node B. The goal of the experiment is to swap these particles, i.e., to arrive at a state where the normal particle is at node B and the antiparticle is at node A. This state should be reached by a sequence of moves, where each move consists of transmitting one of the particles from its current location to a neighbouring node via a wire.


As you probably remember from popular science TV programmes, playing with matter and antimatter is usually not that safe. In particular, if particles of matter and antimatter get too close to each other, they will annihilate each other blowing up the whole experiment. Therefore, the research team would like to swap the locations of the particles in such a manner that the minimum Euclidean distance between them during the experiment is as large as possible. This minimum distance is called the safeness of the experiment. For simplicity, we assume that while a particle is transmitted via a wire we do not consider its location; in other words, the only risky moments during the experiment are when both particles are at some nodes. You may assume that it is always possible to swap the particles with positive safeness, that is, so that the particles are never placed at the same node during swapping.


Another catch is that the physicists do not know precisely where the particles will appear. They have made a list of potential pairs of initial locations (A, B), and for each of them they would like to know the maximum possible safeness of swapping the particles. Help them in this task.


2
The wires may cross each other on the plate.

## 예제 입력 1
```
6
0 0
-1 3
-1 0
-1 -3
3 0
0 1
6
1 2
2 3
3 4
4 1
1 5
5 6
5
6 5
2 4
2 6
3 6
4 6
```

## 예제 출력 1
```
1.00000000
3.16227766
2.23606798
1.41421356
3.16227766
```

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Diamond 4 | Java 15 / 수정 | 495744 KB | 3840 ms | 5400 B | 1달 전 |
