from cs50 import SQL
from sys import argv
import csv


db = SQL("sqlite:///students.db")


if len(argv) != 2:
    print("Usage: program.py file.csv")
    exit(1)


with open(argv[1]) as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        name = row['name']
        name = name.split(' ')
        birth = int(row['birth'])
        if len(name) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       name[0], name[1], name[2], row['house'], birth)
        else:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       name[0], None, name[1], row['house'], birth)