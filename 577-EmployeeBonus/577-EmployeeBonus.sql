-- Last updated: 12/27/2025, 3:44:47 PM
SELECT Employee.name, Bonus.bonus FROM Employee
LEFT JOIN Bonus
ON Employee.empId=Bonus.empId
WHERE Bonus.bonus < 1000 OR Bonus.bonus IS NULL
;