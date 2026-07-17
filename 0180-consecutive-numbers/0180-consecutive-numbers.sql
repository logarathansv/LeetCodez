with wind as(
    select num, lead(num, 1) over (order by id) as num1, 
    lead(num, 2) over (order by id) as num2
    from Logs
) 
select distinct num as ConsecutiveNums from wind where num = num1 and num = num2;