# Write your MySQL query statement belelow

WITH RANK_SCORE AS(
    SELECT 
    score,
    DENSE_RANK() OVER(ORDER BY score DESC) AS ranking
FROM Scores
)
SELECT 
    score, 
    ranking AS 'rank'
FROM RANK_SCORE
ORDER BY score DESC;