from cs50 import get_int


digits = 0
credit = get_int("Number:")
credit1 = credit

# count amount of digits
while credit1 > 0:
    digits = digits+1
    credit1 = credit1//10
print(f"{digits}")
# getting first two digits of cc
credit = int(str(credit)[:2])
print(f"{credit}")
# luhns algorithim
a = 0
for i in range(digits):
    digit = credit1 % 10
    if (i % 2 == 0):
        digit *= 2
        if digit > 9:
            digit -= 9
        a += digit
        credit1 /= 10
a %= 10
print(f"{a}")
# checking which type of card else invalid
if (digits == 15 and (credit == 34 or credit == 37) and a == 0):
    print("AMEX")
elif (digits == 16 and credit > 50 and credit < 56 and a == 0):
    print("MASTERCARD")
elif ((digits == 13 or digits == 16) and int(str(credit)[:1]) == 4 and a == 0):
    print("VISA")
else:
    print("INVALID")