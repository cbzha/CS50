# test if a credit card number is visa, american express , mastercard or invalid
# Hans Peter Luhn' Algorithm
from cs50 import get_int

# @Carlos Bruno
countdigits = 0
checksum = 0
num = 0
firstdigits = 0
firstdigit = 0
count = 0

number = get_int("type the number of the credit card: ")
num = number

# count the algarisms
while (num != 0):
    num = num//10
    count += 1

# if is american express 15 digits
if count == 15:
    # gets first digts for checking for matching patterns
    #str(number)
    firstdigits = number // 10000000000000

    first = number % 10

    sec = number % 100
    sec = sec // 10

    third = number % 1000
    third = third // 100

    four = number % 10000
    four = four // 1000

    fifth = number % 100000
    fifth = fifth // 10000

    sixth = number % 1000000
    sixth = sixth // 100000

    seventh = number % 10000000
    seventh = seventh // 1000000

    eigth = number % 100000000
    eigth = eigth // 10000000

    ninth = number % 1000000000
    ninth = ninth // 100000000

    tenth = number % 10000000000
    tenth = tenth // 1000000000

    elv = number % 100000000000
    elv = elv // 10000000000

    twelth = number % 1000000000000
    twelth = twelth // 100000000000

    thirteen = number % 10000000000000
    thirteen = thirteen // 1000000000000

    fourteen = number % 100000000000000
    fourteen = fourteen // 10000000000000

    fifteenth = number % 1000000000000000
    fifteenth = fifteenth // 100000000000000

    a = (sec * 2) // 10 + ((sec * 2) % 10)
    b = (four * 2) // 10 + ((four * 2) % 10)
    c = (sixth * 2) // 10 + ((sixth * 2) % 10)
    d = (eigth * 2) // 10 + ((eigth * 2) % 10)
    e = (tenth * 2) // 10 + ((tenth * 2) % 10)
    f = (twelth * 2) // 10 + ((twelth * 2) % 10)
    g = (fourteen * 2) // 10 + ((fourteen * 2) % 10)

    checksum = a + b + c + d + e + f + g
    checksum = checksum + first + third + fifth + seventh + ninth + elv + thirteen + fifteenth
    checksum = checksum % 10


if count == 16:
    firstdigits = number // 100000000000000
    firstdigit = number // 1000000000000000
    # get last digit
    first = number % 10
    # get second to last digit
    sec = number % 100
    sec = sec // 10

    third = number % 1000
    third = third // 100

    four = number % 10000
    four = four // 1000

    fifth = number % 100000
    fifth = fifth // 10000

    sixth = number % 1000000
    sixth = sixth // 100000

    seventh = number % 10000000
    seventh = seventh // 1000000

    eigth = number % 100000000
    eigth = eigth // 10000000

    ninth = number % 1000000000
    ninth = ninth // 100000000

    tenth = number % 10000000000
    tenth = tenth // 1000000000

    elv = number % 100000000000
    elv = elv // 10000000000

    twelth = number % 1000000000000
    twelth = twelth // 100000000000

    thirteen = number % 10000000000000
    thirteen = thirteen // 1000000000000

    fourteen = number % 100000000000000
    fourteen = fourteen // 10000000000000

    fifteenth = number % 1000000000000000
    fifteenth = fifteenth // 100000000000000

    sixteen = number % 10000000000000000
    sixteen = sixteen // 1000000000000000

    a = (sec * 2) // 10 + ((sec * 2) % 10)
    b = (four * 2) // 10 + ((four * 2) % 10)
    c = (sixth * 2) // 10 + ((sixth * 2) % 10)
    d = (eigth * 2) // 10 + ((eigth * 2) % 10)
    e = (tenth * 2) // 10 + ((tenth * 2) % 10)
    f = (twelth * 2) // 10 + ((twelth * 2) % 10)
    g = (fourteen * 2) // 10 + ((fourteen * 2) % 10)
    h = (sixteen * 2) // 10 + ((sixteen * 2) % 10)

    # algorithm's checksum
    checksum = a + b + c + d + e + f + g + h
    checksum = checksum + first + third + fifth + seventh + ninth + elv + thirteen + fifteenth
    # get cheksum's last digit
    checksum = checksum % 10

if count == 13:
    firstdigits = number // 1000000000000
    first = number % 10

    sec = number % 100
    sec = sec // 10

    third = number % 1000
    third = third // 100

    four = number % 10000
    four = four // 1000

    fifth = number % 100000
    fifth = fifth // 10000

    sixth = number % 1000000
    sixth = sixth // 100000

    seventh = number % 10000000
    seventh = seventh // 1000000

    eigth = number % 100000000
    eigth = eigth // 10000000

    ninth = number % 1000000000
    ninth = ninth // 100000000

    tenth = number % 10000000000
    tenth = tenth // 1000000000

    elv = number % 100000000000
    elv = elv // 10000000000

    twelth = number % 1000000000000
    twelth = twelth // 100000000000

    thirteen = number % 10000000000000
    thirteen = thirteen // 1000000000000

    # get the sum of product's digits
    a = (sec * 2) // 10 + ((sec * 2) % 10)
    b = (four * 2) // 10 + ((four * 2) % 10)
    c = (sixth * 2) // 10 + ((sixth * 2) % 10)
    d = (eigth * 2) // 10 + ((eigth * 2) % 10)
    e = (tenth * 2) // 10 + ((tenth * 2) % 10)
    f = (twelth * 2) // 10 + ((twelth * 2) % 10)

    checksum = a + b + c + d + e + f
    checksum = checksum + first + third + fifth + seventh + ninth + elv + thirteen

    # get the last cheksum digit
    checksum = checksum % 10

if checksum == 0 and count == 16 and (firstdigits == 51 or firstdigits == 52 or firstdigits == 53 or firstdigits == 54 or firstdigits == 55):
    print("MASTERCARD")
elif checksum == 0 and count == 15 and (firstdigits == 34 or firstdigits == 37):
    print("AMEX")
elif checksum == 0 and (count == 13 or count == 16) and firstdigit == 4:
    print("VISA")
else:
    print("INVALID")
