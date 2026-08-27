select id, sum(friends) as num from (
select
requester_id as id, count(accepter_id) as friends from RequestAccepted
group by requester_id
union all
select
accepter_id as id, count(requester_id) as friends from RequestAccepted
group by accepter_id
) t
group by id order by num desc LIMIT 1;