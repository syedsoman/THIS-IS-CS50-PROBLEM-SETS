# credit card checker using Luhn

num = input("Number: ")

# reverse for easier processing
rev = num[::-1]
total = 0

for i, d in enumerate(rev):
    n = int(d)
    if i % 2 == 1:
        n *= 2
        if n > 9:
            n -= 9
    total += n

if total % 10 != 0:
    print("INVALID")
else:
    # card type check
    if num.startswith("4") and len(num) in [13, 16]:
        print("VISA")
    elif num[:2] in ["34", "37"] and len(num) == 15:
        print("AMEX")
    elif num[:2] in ["51", "52", "53", "54", "55"] and len(num) == 16:
        print("MASTERCARD")
    else:
        print("INVALID")
