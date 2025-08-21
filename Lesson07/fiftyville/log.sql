-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Get crime scene report
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time 
-- – each of their interview transcripts mentions the bakery.
SELECT *
FROM crime_scene_reports
WHERE street = 'Humphrey Street'
    AND year = 2024
    AND month = 7
    AND day = 28;
-- Find interview transcripts
SELECT *
FROM interviews
WHERE year = 2024
    AND month = 7
    AND day = 28
    AND transcript LIKE '%bakery%';
-- Find suspicious license plate
SELECT *
FROM bakery_security_logs
WHERE year = 2024
    AND month = 7
    AND day = 28
    AND hour = 10
    AND (
        minute BETWEEN 4 AND 26
    )
    AND activity = 'exit';
-- Find suspect based on license
SELECT *
FROM people
WHERE license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2024
            AND month = 7
            AND day = 28
            AND hour = 10
            AND (
                minute BETWEEN 4 AND 26
            )
            AND activity = 'exit'
    );
-- Find suspicious account number
SELECT *
FROM atm_transactions
WHERE year = 2024
    AND month = 7
    AND day = 28
    AND atm_location LIKE '%Leggett%'
    AND transaction_type = 'withdraw';
-- Find suspect based on account number
SELECT person_id
FROM bank_accounts
WHERE account_number IN (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2024
            AND month = 7
            AND day = 28
            AND atm_location LIKE '%Leggett%'
            AND transaction_type = 'withdraw'
    );
-- Find suspect based on account
SELECT *
FROM people
WHERE id IN (
        SELECT person_id
        FROM bank_accounts
        WHERE account_number IN (
                SELECT account_number
                FROM atm_transactions
                WHERE year = 2024
                    AND month = 7
                    AND day = 28
                    AND atm_location LIKE '%Leggett%'
                    AND transaction_type = 'withdraw'
            )
    );
-- Find Fiftyville airport id
SELECT *
FROM airports
WHERE city = 'Fiftyville';
-- Find earliest plane
SELECT *
FROM flights
WHERE origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    AND year = 2024
    AND month = 7
    AND day = 29
ORDER BY hour,
    minute
LIMIT 1;
-- Find escape destination
SELECT city
FROM airports
WHERE id IN (
        SELECT destination_airport_id
        FROM flights
        WHERE origin_airport_id = (
                SELECT id
                FROM airports
                WHERE city = 'Fiftyville'
            )
            AND year = 2024
            AND month = 7
            AND day = 29
        ORDER BY hour,
            minute
        LIMIT 1
    );
-- FIND passengers information
SELECT passport_number
FROM passengers
WHERE flight_id = (
        SELECT id
        FROM flights
        WHERE origin_airport_id = (
                SELECT id
                FROM airports
                WHERE city = 'Fiftyville'
            )
            AND year = 2024
            AND month = 7
            AND day = 29
        ORDER BY hour,
            minute
        LIMIT 1
    );
-- FIND suspect based on flight
SELECT *
FROM people
WHERE passport_number IN (
        SELECT passport_number
        FROM passengers
        WHERE flight_id = (
                SELECT id
                FROM flights
                WHERE origin_airport_id = (
                        SELECT id
                        FROM airports
                        WHERE city = 'Fiftyville'
                    )
                    AND year = 2024
                    AND month = 7
                    AND day = 29
                ORDER BY hour,
                    minute
                LIMIT 1
            )
    );
-- Find suspicious phone number based on phone call
SELECT caller
FROM phone_calls
WHERE year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60;
-- Find suspect based on phone number
SELECT *
FROM people
WHERE phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE year = 2024
            AND month = 7
            AND day = 28
            AND duration < 60
    );
-- Find suspect based on all
SELECT name
FROM people
WHERE phone_number IN (
        SELECT caller
        FROM phone_calls
        WHERE year = 2024
            AND month = 7
            AND day = 28
            AND duration < 60
    )
    AND passport_number IN (
        SELECT passport_number
        FROM passengers
        WHERE flight_id = (
                SELECT id
                FROM flights
                WHERE origin_airport_id = (
                        SELECT id
                        FROM airports
                        WHERE city = 'Fiftyville'
                    )
                    AND year = 2024
                    AND month = 7
                    AND day = 29
                ORDER BY hour,
                    minute
                LIMIT 1
            )
    )
    AND id IN (
        SELECT person_id
        FROM bank_accounts
        WHERE account_number IN (
                SELECT account_number
                FROM atm_transactions
                WHERE year = 2024
                    AND month = 7
                    AND day = 28
                    AND atm_location LIKE '%Leggett%'
                    AND transaction_type = 'withdraw'
            )
    )
    AND license_plate IN (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2024
            AND month = 7
            AND day = 28
            AND hour = 10
            AND (
                minute BETWEEN 4 AND 26
            )
            AND activity = 'exit'
    );
-- Find ACCOMPLICE
SELECT name
FROM people
WHERE phone_number IN (
        SELECT receiver
        FROM phone_calls
        WHERE year = 2024
            AND month = 7
            AND day = 28
            AND duration < 60
            AND caller IN (
                SELECT phone_number
                FROM people
                WHERE phone_number IN (
                        SELECT caller
                        FROM phone_calls
                        WHERE year = 2024
                            AND month = 7
                            AND day = 28
                            AND duration < 60
                    )
                    AND passport_number IN (
                        SELECT passport_number
                        FROM passengers
                        WHERE flight_id = (
                                SELECT id
                                FROM flights
                                WHERE origin_airport_id = (
                                        SELECT id
                                        FROM airports
                                        WHERE city = 'Fiftyville'
                                    )
                                    AND year = 2024
                                    AND month = 7
                                    AND day = 29
                                ORDER BY hour,
                                    minute
                                LIMIT 1
                            )
                    )
                    AND id IN (
                        SELECT person_id
                        FROM bank_accounts
                        WHERE account_number IN (
                                SELECT account_number
                                FROM atm_transactions
                                WHERE year = 2024
                                    AND month = 7
                                    AND day = 28
                                    AND atm_location LIKE '%Leggett%'
                                    AND transaction_type = 'withdraw'
                            )
                    )
                    AND license_plate IN (
                        SELECT license_plate
                        FROM bakery_security_logs
                        WHERE year = 2024
                            AND month = 7
                            AND day = 28
                            AND hour = 10
                            AND (
                                minute BETWEEN 4 AND 26
                            )
                            AND activity = 'exit'
                    )
            )
    );