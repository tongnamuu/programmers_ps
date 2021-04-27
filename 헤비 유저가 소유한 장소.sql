SELECT A.ID, A.NAME, A.HOST_ID
FROM (
        SELECT HOST_ID, COUNT(HOST_ID) as cnt
        FROM PLACES 
        GROUP BY HOST_ID
    ) AS B, PLACES AS A
WHERE
    A.HOST_ID = B.HOST_ID and B.cnt >= 2
ORDER BY A.ID
