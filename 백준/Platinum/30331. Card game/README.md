# [30331. Card game](https://www.acmicpc.net/problem/30331)

## 문제
Adam and Bill are playing cards. There are K cards in the deck, numbered 1 to K. The game consists of N rounds, during which each player is trying to score points. The winner is the one who has the most points at the end of the game.


Before each round, the deck is shuffled. During the first round players draw one card each. Then Bill shows his card, and Adam, knowing both cards, decides what action to take:




show his card;


keep his card.




If Adam decides to show his card the round is won by the player who has the higher card. The number of points won is equal to the product of the numbers written on the cards.


For example, if Adam’s card shows 7 and Bill’s card shows 10, Bill wins this round and gets 70 points. The loser does not get any points for the round. Cards are then returned to the deck and shuffled, and the round ends.


If Adam decides to keep his card, Bill’s card is returned to the deck and the deck is shuffled. In the next round (if any are left) Bill will draw a new card while Adam will use the card he has decided to keep.


The game continues in this way. Bill always shows his card while Adam can choose what to do. The game ends after N rounds are played and both players sum their points up.


Let’s take an example when N = 4 and K = 10. The game could go like this:




In the first round, Bill gets a card with 2, while Adam – 6. Adam decides to show his card. Since his card is greater, he gets 6 · 2 = 12 points for this round.


In the second round, Bill gets a 9, Adam – 3. This time Adam decides to keep his card. No one gets any points for this round.


In the third round, Bill gets a 5, Adam still has his old card – 3. This time, Adam decides to show his card. Bill gets 5 · 3 = 15 points.


In the fourth round, Adam gets 8, o Bill – 4. Adam opens his card and gets 8 · 4 = 32 points.


Since N = 4, the game ends here. Adam has 12 + 32 = 44 points, Bill – 15 points. Adam wins the game by 29 points.




Adam wants to win this game by as large margin as possible. Your task is to help him. Write a program that would play this game and make decisions for Adam. It has to make sure that Adam wins and try to win by as large margin as possible.

## 제출 정보
| 난이도 | 언어 | 메모리 | 시간 | 코드 길이 | 제출 일자 |
|--------|------|--------|------|-----------|-----------|
| Platinum 2 | C++17 / 수정 | 119208 KB | 60 ms | 139 B | 1년 전 |
