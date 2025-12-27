-- Last updated: 12/27/2025, 3:44:56 PM
SELECT
  w1.id
FROM Weather AS w1
JOIN Weather AS w2
  ON DATEDIFF(w1.recordDate, w2.recordDate) = 1
WHERE
  w1.temperature > w2.temperature;
