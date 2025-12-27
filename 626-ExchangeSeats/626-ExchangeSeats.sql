-- Last updated: 12/27/2025, 3:44:44 PM
SELECT
CASE
    WHEN id%2=1 AND id=(select max(id) from Seat) THEN id
    WHEN id%2=0 THEN id-1
    WHEN id%2=1 THEN id+1
END
AS id, student
FROM Seat
ORDER BY id
;
