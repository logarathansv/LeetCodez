# Write your MySQL query statement below
select machine_id, (
    select round(avg(t1.timestamp) - avg(t2.timestamp),3) as processing_time
    from Activity t1, Activity t2 where t1.activity_type in (
        select activity_type from Activity where activity_type='end' and t1.machine_id = a.machine_id
    )
    and t2.activity_type in (
        select activity_type from Activity where activity_type='start' and t2.machine_id = a.machine_id
    )
)
as processing_time
from Activity a
group by a.machine_id;
