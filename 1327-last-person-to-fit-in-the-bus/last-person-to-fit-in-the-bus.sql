# Write your MySQL query statement below
select person_name 
from (
    select turn, person_name, weight,
        sum(weight) over (order by turn) as cumulative_weight
    from Queue
) as new_table
where cumulative_weight <= 1000
order by cumulative_weight desc
limit 1;