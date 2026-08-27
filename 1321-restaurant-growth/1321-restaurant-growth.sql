with t as (
    select visited_on, sum(amount) as amount from Customer
    group by visited_on
)

select visited_on, 
(
    sum(amount) over (order by visited_on rows between 6 preceding and current row)
) as amount,
(
    round(avg(amount) over (order by visited_on rows between 6 preceding and current row),2)
) as average_amount
from t limit 1000 offset 6;