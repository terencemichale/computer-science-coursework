import random

valid_game = True
lower = 0
upper = 0
while valid_game:


    try:
        lower = int(input("Enter lower bound: "))
        upper = int(input("Enter the upper bound: "))
    except ValueError:
        print("\nSorry, I didn't understand that.\n")
        continue

    if lower > upper:
        print("The lower bound must be less than the upper bound.\n")
        continue

    random_number = random.randint(lower, upper)

    print(f"\nGreat, now guess a number between {lower} and {upper}: ", end = "")
    guess = int(input())

    while guess != random_number:

        if guess in range(lower,upper+1) and guess > random_number:
            print("Nope, too high.")
        elif guess in range(lower,upper+1) and guess < random_number:
            print("Nope, too low.")
        else:
            print(f"Nope, guess a number between {lower} and {upper}.")

        guess = int(input("\nGuess another number: "))
    else:
        print("You got it!")


        while valid_game:
            try:
                play_again = input("\nWould you like to play again? (y/n): ")
            except ValueError:
                print("\nSorry, I didn't understand that.\n")
                continue

            if play_again == "y":
                print("\nGreat, now playing again!")
                break
            elif play_again == "n":
                print("Goodbye!")
                valid_game = False
            else:
                print("Sorry, I didn't understand that.")
                continue

