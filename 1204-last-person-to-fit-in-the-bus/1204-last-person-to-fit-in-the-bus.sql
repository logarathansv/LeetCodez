with tot as(
    select person_name, person_id, turn, sum(Weight) over(order by turn) as total
    from Queue
)
select person_name from tot 
where total <= 1000
order by total desc limit 1;