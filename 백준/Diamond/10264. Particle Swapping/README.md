# 10264 - Particle Swapping

[문제 링크](https://www.acmicpc.net/problem/10264)

| 난이도 | 시간 제한 | 메모리 제한 |
|--------|----------|------------|
| Diamond 4 | 5 초 | 256 MB |

## 알고리즘 분류
- 자료 구조
- 그래프 이론
- 트리
- 이분 탐색
- 분리 집합
- 최소 스패닝 트리
- 최소 공통 조상
- 병렬 이분 탐색

## 제출 결과
| 메모리 | 시간 | 언어 | 코드 길이 | 제출 일자 |
|--------|------|------|----------|----------|
| 495744 KB | 3840 ms | Java 15 | 5400 B | 2026년 3월 12일 05:56:08 |

## 문제 설명
![](/upload/images2/particles.png)The research team of prof. Feynmansson is preparing a new groundbreaking experiment in particle physics. On a special plate they have prepared a system consisting of a number of nodes connected via wires<sup>2</sup>. In the beginning of the experiment a pair of particles appears at two different nodes of the system: one normal particle of matter appears at some node A, and one corresponding particle of antimatter appears at some node B. The goal of the experiment is to swap these particles, i.e., to arrive at a state where the normal particle is at node B and the antiparticle is at node A. This state should be reached by a sequence of moves, where each move consists of transmitting one of the particles from its current location to a neighbouring node via a wire.

As you probably remember from popular science TV programmes, playing with matter and antimatter is usually not that safe. In particular, if particles of matter and antimatter get too close to each other, they will annihilate each other blowing up the whole experiment. Therefore, the research team would like to swap the locations of the particles in such a manner that the minimum Euclidean distance between them during the experiment is as large as possible. This minimum distance is called the safeness of the experiment. For simplicity, we assume that while a particle is transmitted via a wire we do not consider its location; in other words, the only risky moments during the experiment are when both particles are at some nodes. You may assume that it is always possible to swap the particles with positive safeness, that is, so that the particles are never placed at the same node during swapping.

Another catch is that the physicists do not know precisely where the particles will appear. They have made a list of potential pairs of initial locations (A, B), and for each of them they would like to know the maximum possible safeness of swapping the particles. Help them in this task.

<sup>2</sup>The wires may cross each other on the plate.

## 입력
The first line of the input contains a single integer n (1 ≤ n ≤ 500), denoting the number of nodes in the system. Then follow n lines, each containing two integers x, y (−10 000 ≤ x, y ≤ 10 000); the numbers in the i-th line denote the coordinates on the plate of the i-th node. No two nodes are located at the same point.

The next line of the input contains a single integer m (0 ≤ m ≤ 2 000), denoting the number of wires in the system. Then follow m lines; each line contains a description of a wire as a pair of integers a, b (1 ≤ a, b ≤ n, a ≠ b), denoting the indices of the nodes that are connected by the wire. You may assume that no two nodes are connected by more than one wire, and no wire connects a node with itself.

The next line of the input contains a single integer ℓ (1 ≤ ℓ ≤ \(\begin{pmatrix}  n  \\  2  \end{pmatrix}\)), denoting the length of the list of potential initial positions prepared by the physicists. Then follow ℓ lines, each containing two integers a, b (1 ≤ a, b ≤ n, a ≠ b), denoting the indices of the initial nodes A and B, respectively.

## 출력
Output exactly ℓ lines. The i-th line of the output should contain a single floating point number, being the maximum possible safeness for the i-th pair of initial positions listed by the physicists. Absolute or relative errors of value at most 10<sup>-6</sup> will be tolerated.
