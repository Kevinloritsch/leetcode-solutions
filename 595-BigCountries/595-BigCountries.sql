-- Last updated: 12/27/2025, 3:44:45 PM
SELECT
name, population, area
FROM World
WHERE
area >= 3000000 
OR
population >= 25000000;