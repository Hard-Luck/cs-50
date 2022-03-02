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
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15 and minute < 25));
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

--check which suspects passport number was on the flight
SELECT * from people where passport_number in(
SELECT passport_number from passengers where flight_id = 36);
-- checking call logs for < 1 min calls
SELECT * from phone_calls join people
on phone_calls.caller = people.phone_number
where caller in(
SELECT phone_number from people where license_plate in(
SELECT license_plate FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15 and minute <= 25)) and day = 28) and duration < 60;

--look at ATM on legget street
SELECT * from people
  JOIN bank_accounts on bank_accounts.person_id = people.id
 WHERE (account_number in (
SELECT account_number from atm_transactions
 WHERE atm_location LIKE "leggett street"
   AND day = 28)
AND name in (SELECT name from people where license_plate in(
SELECT license_plate FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15 and minute <= 25))));
--BRUCE DIANA IMAN LUCA
--BRUCE and DIANA only 2 to make calls
-- DIANA wasnt on the flight

-- Who did bruce call?
SELECT name from 
SELECT receiver from phone_calls join people
on phone_calls.caller = people.phone_number
where caller in(
SELECT phone_number from people where license_plate in(
SELECT license_plate FROM bakery_security_logs
WHERE (day = 28 and month = 7 and hour = 10 and minute > 15 and minute <= 25)) and day = 28)
  AND duration < 60
  AND name = "Bruce";