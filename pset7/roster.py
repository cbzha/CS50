from cs50 import SQL
from sys import argv


db = SQL("sqlite:///students.db")


if len(argv) != 2:
    print("Usage: program.py file.csv")
    exit(1)

list = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", argv[1])

for student in list:
    if student['middle'] != None:
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")