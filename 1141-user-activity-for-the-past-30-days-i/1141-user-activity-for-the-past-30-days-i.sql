select activity_date as day, count(distinct user_id) as active_users 
from Activity
where activity_date between DATE('2019-06-28') and DATE('2019-07-28')
group by activity_date; 