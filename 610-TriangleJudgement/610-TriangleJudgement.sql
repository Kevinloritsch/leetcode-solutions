-- Last updated: 12/27/2025, 3:44:43 PM
SELECT x, y, z,
    CASE
    WHEN x+y > z AND x+z>y AND y+z>x
    THEN 'Yes'
    ELSE 'No'
    END
AS triangle
FROM Triangle;