-- Last updated: 12/27/2025, 3:44:14 PM
SELECT employee_id, department_id
FROM Employee
WHERE primary_flag='Y' 
OR
employee_id IN (
    SELECT employee_id FROM Employee
    GROUP BY (employee_id)
    HAVING COUNT(*)=1
);