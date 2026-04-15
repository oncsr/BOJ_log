# [Diamond V] Pride and Prejudice and Zombies - 4464 

[문제 링크](https://www.acmicpc.net/problem/4464) 

### 성능 요약

메모리: 2036 KB, 시간: 136 ms

### 분류

수학, 문자열, 브루트포스 알고리즘, 정수론, 소수 판정, 소인수분해, 폴라드 로, 밀러–라빈 소수 판별법

### 제출 일자

2024년 8월 8일 02:54:08

### 문제 설명

<p>Pride and Prejudice and Zombies, by Jane Austen and Seth Grahame-Smith, spices up the famous 1813 satire about marriage and social convention with intercalary appearances by zombies, skunks, ghouls, chipmunks and ninjas. Most literary critics praised PPZ (as it’s known on Facebook) as “clever”, “insightful”, holding “indomitable appeal”, although Macy Halford of The New Yorker condemned Mr. Grahame-Smith’s retelling as “awful”, and “one hundred per cent terrible”. </p>

<p>Here’s a little known fact: the book’s release was delayed by some 8 years due to several heated disagreements between Mr. Grahame-Smith and the editors at Quirk Books, the small publishing house in Philadelphia that eventually published the novel. The most impassioned of the arguments centered on the controversial “Vampire Number” chapter, where Mrs. Bennett — desperate to rally the English countryside’s interest in matrimony — contrives a social event where 50 men and 50 women draw slips of paper from a large, feathery hat. “It is an axiom generally acknowledged, that a single man in possession of the complementary multiplicand, must be in want of a wife”, says Mrs. Bennett in announcing the event. On each slip of paper is a single three-digit number. The goal of the event was for each of the women to find the man whose three-digit number, when multiplied by her own, produced a six-digit number that reproduced the digits of the two “multiplicands” (Mrs. Bennett’s word) with the correct “distribution” (also her word) in some order. </p>

<p>Mr. Grahame-Smith insisted the chapter was vital to the story arc, whereas Quirk Books considered it forced, obscure, boring, and unnecessarily intellectual. Furthermore, Quirk Books was initially contemplating a limited New England release and argued that no one outside of the Pacific Northwest understood math. Mr. Grahame-Smith eventually conceded this to be true, and agreed to cut the chapter. The chapter’s existence only surfaced recently in a follow-up article in The New Yorker where Ms. Halford noted the novel would have “benefitted substantially” had it been included. </p>

<p>Vampire Numbers</p>

<p>It is generally acknowledged that Vampire numbers are positive integers with an even number — we’ll say 2n — of digits where the 2n digits can be distributed across two n-digit numbers such that their product equals the original 2n-digit number. None of the three numbers can include leading zeroes, and neither of the two n-digit numbers can have consecutive zeroes anywhere. </p>

<p>For examples:</p>

<ul>
	<li>125460 = 204 x 615 (so 125460 is a Vampire number).</li>
	<li>16758243290880 = 1982736 x 8452080 (so 16758243290880 is a Vampire number).</li>
	<li>353 has an odd number of digits, so it can’t be a Vampire number by definition.</li>
	<li>3421 can’t be subdivided properly, so it’s not a Vampire number either.</li>
</ul>

<p>Write a program that reads in a series of numbers (each at most 18 digits) and prints whether or not that number is a Vampire number. </p>

### 입력 

 <p>There will be an arbitrary number of inputs, one per line, with no leading zeroes or extraneous whitespace. Each number will have at most 18 digits. End of input is marked by a single 0 on its own line, for which no output should be produced. </p>

### 출력 

 <p>For each input, print the number, followed by a colon, followed by a space, followed by “yes” if the number is a Vampire number or “no” if it is not. </p>

