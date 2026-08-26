select "Low Salary" as category, count(*) as accounts_count from Accounts 
where income < 20000
UNION
select "Average Salary" as category, count(*) as accounts_count from Accounts 
where income BETWEEN 20000 AND 50000
UNION
select "High Salary" as category, count(*) as accounts_count from Accounts 
where income > 50000;