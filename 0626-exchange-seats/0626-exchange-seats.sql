select id-1 as id, student from Seat
where id%2 =0
UNION
select case when id+1 in (select id from Seat)
then id+1
else id 
end, 
student from Seat
where id%2 =1 
order by id;