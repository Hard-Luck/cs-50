-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Check description from scrime scene reports for 28th July
SELECT description FROM crime_scene_reports
       WHERE (day = 28 and month = 7) ;
--10:15 am all 3 witnesses mention the

--Check bakery security logs for 10:15 on 28th July
SELECT * FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15)
LIMIT 1;

--check interviews
SELECT transcript FROM interviews where day = 28 and month = 7;

--Check name against license plates
SELECT * from people where license_plate in(
SELECT license_plate FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15 and minute <= 25));
--Suspects, Vanessa, Barry, Iman, Sofia, Luca Diana, Kelsey, Bruce

--Check suspects passport numbers agianst flight records
SELECT * from passengers where passport_number in(
SELECT passport_number from people where license_plate in(
SELECT license_plate FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15 and minute <= 25)));

--check flights, check flight ID against date
SELECT * from flights where id in(
SELECT flight_id from passengers where passport_number in(
SELECT passport_number from people where license_plate in(
SELECT license_plate FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15 and minute <= 25)))
AND day = 29 and month = 7)
ORDER BY hour
LIMIT 1;
-- 2 options, the witness suggested the theif would take the earlier flight

--destination airport 4
SELECT * from airports where id = 4;
-- New York City


select * from phone_calls where caller in(
SELECT phone_number from people where license_plate in(
SELECT license_plate FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15)
LIMIT 1)
AND day = 28);
--3 calls made, 1 on the day check number against receiver
SELECT
select receiver from phone_calls where caller in(
SELECT phone_number from people where license_plate in(
SELECT license_plate FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15)
LIMIT 1)
AND day = 28);