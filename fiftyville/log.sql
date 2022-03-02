-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check description from scrime scene reports for 28th July
SELECT description FROM crime_scene_reports
       WHERE (day = 28 and month = 7) ;
--10:15 am all 3 witnesses mention the

--Check bakery security logs for 10:15 on 28th July
SELECT * FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10);