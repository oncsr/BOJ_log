# [Diamond V] Software Package Manager - 25078 

[문제 링크](https://www.acmicpc.net/problem/25078) 

### 성능 요약

메모리: 16732 KB, 시간: 284 ms

### 분류

자료 구조, 트리, 세그먼트 트리, 느리게 갱신되는 세그먼트 트리, 오일러 경로 테크닉, Heavy-light 분할

### 제출 일자

2022년 10월 11일 22:54:49

### 문제 설명

<p>You'd like to design a package manager on your own, and thus you'd like to resolve the dependency problem among packages. If package $A$ depends on package $B$, then we must install package $B$ before package $A$. Likewise, if we'd like to remove package $B$, we also need to remove package $A$. You know the dependency relations among the packages, and you may assume all packages other than package $0$ will rely on exactly one package (package $0$ does not rely on any other packages). There are no cycles in the dependency relation (like $A_1$ depends on $A_2$, $A_2$ depends on $A_3$, …, $A_{m_1}$ depends on $A_m$ but $A_m$ depends on $A_1$), and of course no package depends on itself.</p>

<p>Now you'd like to know how many packages have their status changed upon installing or uninstalling a given package. Notice installing an installed package or uninstalling an uninstalled package will not change the status of any package.</p>

### 입력 

 <p>The first line of the input is an integer $n$ representing the number of packages. The packages are numbered beginning with $0$.</p>

<p>The next line has $n-1$ integers separated by a single space, representing the package that package $1, 2, \dots, n-2, n-1$ depends on.</p>

<p>The next line contains an integer $q$ representing the number of queries. In the following $q$ lines, each line contains a query of form <code>install x</code> or <code>uninstall x</code> representing installing or uninstalling package $x$. You need to maintain the status of each package. Initially, all packages are uninstalled. You need to output how many packages will change the status after the step, and then apply the (un)installation.</p>

### 출력 

 <p>The output consists of $q$ lines. The $i$-th line is an integer representing the number of packages whose status change at step $i$.</p>

