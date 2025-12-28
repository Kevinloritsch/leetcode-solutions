-- Last updated: 12/27/2025, 3:44:26 PM
SELECT person_name FROM
(
    SELECT person_name, turn, SUM(weight) OVER (ORDER BY turn) AS cum_weight
    FROM Queue
) as q
WHERE cum_weight <= 1000
ORDER BY turn desc
LIMIT 1;