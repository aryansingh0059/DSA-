select customer_id, count(visit_id) as count_no_trans
from (
    select customer_id, visit_id 
    from Visits
    where visit_id not in (select visit_id from Transactions)
) t
group by customer_id