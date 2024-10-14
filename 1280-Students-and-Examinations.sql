# Write your MySQL query statement below
select s.student_id,s.student_name,s3.subject_name,count(ss.student_id) as attended_exams from Students s 
cross join Subjects s3 
left join Examinations ss on s.student_id = ss.student_id 
    and s3.subject_name = ss.subject_name
group by s.student_id, s.student_name, s3.subject_name 
ORDER BY s.student_id, s.student_name, s3.subject_name ;