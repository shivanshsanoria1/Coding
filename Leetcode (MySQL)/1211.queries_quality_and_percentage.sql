# Write your MySQL query statement below
select query_name,
round(avg(rating/position), 2) as quality,
round(100*avg(if(rating < 3, 1, 0)), 2) as poor_query_percentage
from Queries
group by query_name;