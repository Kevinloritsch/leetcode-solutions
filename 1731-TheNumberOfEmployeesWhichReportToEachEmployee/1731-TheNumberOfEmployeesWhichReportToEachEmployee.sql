-- Last updated: 12/27/2025, 3:44:17 PM
SELECT manager.employee_id, manager.name, COUNT(employee.name) AS reports_count, ROUND(AVG(employee.age)) AS average_age
FROM Employees as manager
JOIN Employees as employee
ON employee.reports_to=manager.employee_id
GROUP BY manager.employee_id, manager.name
ORDER BY employee_id
;