# cash: minimum number of coins

while True:
    try:
        amount = float(input("Change owed: "))
        if amount >= 0:
            break
    except:
        pass

# dollars to cents (avoid floating problems)
cents = round(amount * 100)

coins = 0

# greedy approach
for coin in [25, 10, 5, 1]:
    while cents >= coin:
        cents -= coin
        coins += 1

print(coins)
