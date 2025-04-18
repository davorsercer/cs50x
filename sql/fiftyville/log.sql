-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 1. Query clues: July 28, 2024, Humphrey Street, theft.
-- Query to see structure and data of crime_scene_reports table:
-- SELECT * FROM crime_scene_reports LIMIT 10;
/* Query to find 2nd clues:
SELECT *
  FROM crime_scene_reports
 WHERE year = 2024 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

New clues are:
- the interviews(table), bakery(transcripts) and 10:15am(time). */


-- 2. Query clues: the interviews(table), bakery(transcripts) and 10:15am(time).
-- Query to see structure and data of interviews table.
-- SELECT * FROM interviews LIMIT 10;
/* Query to find 3rd clues.
SELECT *
  FROM interviews
 WHERE year = 2024 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

New clues are:
- within 10 min, bakery parking lot and drive away,
- recognized earlier this morning, ATM on Leggett Street, withdrawing some money,
- called someone, earliest flightout of Fiftyville tomorrow, flight ticket. */


-- 3. Query clues: within 10 min, bakery parking lot and drive away.
-- Query to see structure and data of bakery_security_logs table.
-- SELECT * FROM bakery_security_logs LIMIT 10;
/* Query to find license_plate.
SELECT *
  FROM bakery_security_logs
 WHERE year = 2024 AND month = 7 AND day = 28 AND activity = 'exit'
   AND hour = 10 and minute >= 15 and minute <= 25;

New clues are 8 license_plate. */


-- 4. Query clues: recognized earlier this morning, ATM on Leggett Street, withdrawing some money.
-- Query to see structure and data of atm_transactions table.
-- SELECT * FROM atm_transactions LIMIT 10;
/* Query to find account_number.
SELECT *
  FROM atm_transactions
 WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'
   AND transaction_type = 'withdraw';

New clues are 8 account_number. */


-- 5. Query clues: 8 bank_accounts.
-- Query to see structure and data of bank_accounts table.
-- SELECT * FROM bank_accounts LIMIT 10;
/* Query to find person_id.
SELECT *
  FROM bank_accounts
 WHERE account_number IN
       (SELECT account_number
          FROM atm_transactions
         WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'
           AND transaction_type = 'withdraw');

New clues are 8 person_id which are ids in people table. */


-- 6. Query clue: called someone, less then a minute call.
-- Query to see structure and data of phone_calls table.
-- SELECT * FROM phone_calls LIMIT 10;
/* Query to find calls.
SELECT *
  FROM phone_calls
 WHERE year = 2024 AND month = 7 AND day = 28 AND duration <= 60;

New clues are 10 calls. */


-- 7. Query clue: earliest flightout of Fiftyville tomorrow.
-- Query to see structure and data of airports table.
-- SELECT * FROM airports LIMIT 10;
/* Query to find airport.
SELECT *
  FROM airports
 WHERE city = 'Fiftyville';

New clues are one airport: CSF, Fiftyville Regional Airport. */


-- 8. Query clue: earliest flightout of Fiftyville tomorrow.
-- Query to see structure and data of flights table.
-- SELECT * FROM flights LIMIT 10;
/* Query to find earliest flightout of Fiftyville tomorrow and destination_airport_id.
SELECT *
  FROM flights
 WHERE year = 2024 AND month = 7 AND day = 29 AND origin_airport_id IN
       (SELECT id
          FROM airports
        WHERE city = 'Fiftyville')
 ORDER BY hour
 LIMIT 1;

New clues are earliest flightout of Fiftyville tomorrow and destination_airport_id */


/* 9. Query to find The city the thief ESCAPED TO:
SELECT city
  FROM airports
 WHERE id IN
       (SELECT destination_airport_id
          FROM flights
         WHERE year = 2024 AND month = 7 AND day = 29 AND origin_airport_id IN
               (SELECT id
                  FROM airports
                 WHERE city = 'Fiftyville')
 ORDER BY hour
 LIMIT 1);

The city the thief ESCAPED TO: New York City */


-- 10. Query clue: earliest flightout of Fiftyville tomorrow, flight ticket.
-- Query to see structure and data of passengers table.
-- SELECT * FROM passengers LIMIT 10;
/* Query to find earliest flightout of Fiftyville tomorrow and destination_airport_id.
SELECT *
  FROM passengers
 WHERE flight_id IN
       (SELECT id
          FROM flights
         WHERE year = 2024 AND month = 7 AND day = 29 AND origin_airport_id IN
               (SELECT id
                  FROM airports
                 WHERE city = 'Fiftyville')
         ORDER BY hour
         LIMIT 1);

New clues are 7 passport_numbers */


/* 11. The THIEF is:
SELECT *
  FROM people
 WHERE license_plate IN
       (SELECT license_plate
          FROM bakery_security_logs
         WHERE year = 2024 AND month = 7 AND day = 28 AND activity = 'exit'
           AND hour = 10 and minute >= 15 and minute <= 25)
   AND id IN
       (SELECT person_id
          FROM bank_accounts
         WHERE account_number IN
               (SELECT account_number
                  FROM atm_transactions
                 WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'
                   AND transaction_type = 'withdraw'))
   AND phone_number IN
       (SELECT caller
          FROM phone_calls
         WHERE year = 2024 AND month = 7 AND day = 28 AND duration <= 60)
   AND passport_number IN
       (SELECT passport_number
          FROM passengers
         WHERE flight_id IN
               (SELECT id
                  FROM flights
                 WHERE year = 2024 AND month = 7 AND day = 29 AND origin_airport_id IN
                       (SELECT id
                          FROM airports
                         WHERE city = 'Fiftyville')
                 ORDER BY hour
                 LIMIT 1));
*/


/* 12. The ACCOMPLICE is:
SELECT name
  FROM people
 WHERE phone_number IN
       (
SELECT receiver
  FROM phone_calls
 WHERE year = 2024 AND month = 7 AND day = 28 AND duration <= 60 AND caller IN
       (
SELECT phone_number
  FROM people
 WHERE license_plate IN
       (SELECT license_plate
          FROM bakery_security_logs
         WHERE year = 2024 AND month = 7 AND day = 28 AND activity = 'exit'
           AND hour = 10 and minute >= 15 and minute <= 25)
   AND id IN
       (SELECT person_id
          FROM bank_accounts
         WHERE account_number IN
               (SELECT account_number
                  FROM atm_transactions
                 WHERE year = 2024 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street'
                   AND transaction_type = 'withdraw'))
   AND phone_number IN
       (SELECT caller
          FROM phone_calls
         WHERE year = 2024 AND month = 7 AND day = 28 AND duration <= 60)
   AND passport_number IN
       (SELECT passport_number
          FROM passengers
         WHERE flight_id IN
               (SELECT id
                  FROM flights
                 WHERE year = 2024 AND month = 7 AND day = 29 AND origin_airport_id IN
                       (SELECT id
                          FROM airports
                         WHERE city = 'Fiftyville')
                 ORDER BY hour
                 LIMIT 1))));
*/
