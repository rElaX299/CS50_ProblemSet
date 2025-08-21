-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Get crime scene report
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time 
-- – each of their interview transcripts mentions the bakery.
SELECT * FROM crime_scene_reports 
WHERE street = 'Humphrey Street'
AND year = 2024 AND month = 7 AND day = 28;

-- Find interview transcripts
SELECT * FROM interviews 
WHERE year = 2024 AND month = 7 AND day = 28
AND transcript LIKE '%bakery%';

-- Find 
SELECT * FROM bakery_security_logs
WHERE year = 2024 AND month = 7 AND day = 28
AND hour = 10 AND (minute > 4 AND minute < 26);