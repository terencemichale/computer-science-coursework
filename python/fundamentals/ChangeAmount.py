# AUTHOR_NAME: Terence Michale
# 3.16 LAB: Exact change

# Get total change amount as an integer input
change_amount = int(input())

if change_amount > 0:
    # Change amount can be broken down into coins

    # Floor division 100 to get number of dollars, then minus that amount
    dollars = change_amount // 100
    change_amount = change_amount - (dollars * 100)

    # Output dollar(s)
    if dollars == 1:
        print(dollars, "Dollar")
    elif dollars > 1:
        print(dollars, "Dollars")

    # Floor division 25 to get number of quarters, then minus that amount
    quarters = change_amount // 25
    change_amount = change_amount - (quarters * 25)

    # Output quarter(s)
    if quarters == 1:
        print(quarters, "Quarter")
    elif quarters > 1:
        print(quarters, "Quarters")

    # Floor division 10 to get number of dimes, then minus that amount
    dimes = change_amount // 10
    change_amount = change_amount - (dimes * 10)

    # Output dime(s)
    if dimes == 1:
        print(dimes, "Dime")
    elif dimes > 1:
        print(dimes, "Dimes")

    # Floor division 5 to get number of nickles, then minus that amount
    nickels = change_amount // 5
    change_amount = change_amount - (nickels * 5)

    # Output nickel(s)
    if nickels == 1:
        print(nickels, "Nickel")
    elif nickels > 1:
        print(nickels, "Nickels")

    # Floor division 1 to get number of penn(ies), then minus that amount
    pennies = change_amount // 1
    if pennies == 1:
        print(pennies, "Penny")
    elif pennies > 1:
        print(pennies, "Pennies")

else:

    # Change amount cannot be broken down into coins
    print("No change")