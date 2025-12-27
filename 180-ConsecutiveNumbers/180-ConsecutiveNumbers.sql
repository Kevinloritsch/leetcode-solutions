-- Last updated: 12/27/2025, 3:44:58 PM
SELECT DISTINCT first.num AS ConsecutiveNums FROM Logs AS first
JOIN Logs as second ON first.id+1=second.id AND first.num=second.num
JOIN Logs as third ON second.id+1=third.id AND second.num=third.num
;
