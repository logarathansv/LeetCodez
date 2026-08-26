(select u.name as results from Users u
join MovieRating mr on mr.user_id = u.user_id 
group by u.user_id order by count(*) desc,name limit 1)
union all
(select m.title as results from Movies m
join MovieRating mr on mr.movie_id = m.movie_id 
where 
EXTRACT(YEAR_MONTH FROM mr.created_at) = 202002
group by m.movie_id order by avg(rating) desc, title limit 1) ;