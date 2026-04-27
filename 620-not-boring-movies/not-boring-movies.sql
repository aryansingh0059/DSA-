select id,movie,description,rating from cinema c
where c.id % 2 = 1
and c.description != 'boring'
order by c.rating desc;