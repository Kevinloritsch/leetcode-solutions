-- Last updated: 12/27/2025, 3:44:12 PM
SELECT employee_id FROM Employees

WHERE salary < 30000

AND manager_id IS NOT NULL
AND manager_id NOT IN (
    select employee_id FROM Employees
)
ORDER BY employee_id
;