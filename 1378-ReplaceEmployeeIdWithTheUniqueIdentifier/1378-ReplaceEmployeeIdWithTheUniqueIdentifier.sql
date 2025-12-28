-- Last updated: 12/27/2025, 3:44:21 PM
SELECT EmployeeUNI.unique_id, Employees.name FROM EmployeeUNI
RIGHT JOIN Employees
ON
Employees.id=EmployeeUNI.id
; 