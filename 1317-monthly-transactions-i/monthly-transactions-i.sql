# Write your MySQL query statement below
select (DATE_FORMAT(trans_date, '%Y-%m')) as month, 
country, 
(count((DATE_FORMAT(trans_date, '%Y-%m')))) as trans_count, 
sum(if(state='approved',1,0)) as approved_count, 
sum(amount) as trans_total_amount, 
sum(if(state='approved', amount, 0)) as approved_total_amount
from Transactions

group by (DATE_FORMAT(trans_date, '%Y-%m')), country