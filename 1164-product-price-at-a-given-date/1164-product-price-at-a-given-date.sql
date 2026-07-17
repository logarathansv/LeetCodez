WITH ranked_prices AS (
    SELECT
        product_id,
        new_price,
        ROW_NUMBER() OVER (
            PARTITION BY product_id
            ORDER BY change_date DESC
        ) AS rn
    FROM Products
    WHERE change_date <= '2019-08-16'
)
SELECT
    product_id,
    new_price AS price
FROM ranked_prices
WHERE rn = 1
UNION
select product_id, 10 as price
from Products 
where product_id not in 
(select product_id from Products where change_date < '2019-08-17')
group by product_id;