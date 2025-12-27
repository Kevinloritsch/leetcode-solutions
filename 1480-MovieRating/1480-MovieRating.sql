-- Last updated: 12/27/2025, 3:44:22 PM
    (SELECT U.name AS results FROM Users as U,
        Movies as M, MovieRating as MR
        WHERE MR.movie_id = M.movie_id AND U.user_id = MR.user_id
        GROUP BY U.user_id, U.name
        ORDER BY COUNT(*) DESC, U.name ASC LIMIT 1)
    UNION ALL
    (SELECT M.title AS results FROM Movies as M,
        MovieRating as MR
        WHERE MR.movie_id = M.movie_id
        AND YEAR(created_at) = 2020 and MONTH(created_at) = 02
        GROUP BY M.title
        ORDER BY AVG(MR.rating) DESC, M.title ASC LIMIT 1);