select score, (select count(distinct score) from scores s2 where s2.score >= s1.score) as "Rank"
from scores s1
order by score desc;