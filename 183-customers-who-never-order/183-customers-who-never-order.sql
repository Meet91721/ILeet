/* Write your PL/SQL query statement below */
-- select name as customers from customers minus (select name from customers where id =any (select customerid from orders));
-- (select name as customers from customers) minus
-- (select name from customers
-- where id = any (select customerid from orders));
select name as customers from customers
where id not in (select customerid from orders);
