"""
    REWORK 12/21/2025
    Author : Terence Michale
    Date : 12/12/2025
    6-4 Milestone: Moving Between Rooms

    This is a simplified version of a text-based adventure game.
    Players can move between rooms using commands.

    1. Move commands: go South, go North, go East, go West
    2. Add to Inventory: get item name
    3. Exit game: exit
"""

# Create a dictionary linking rooms to each other so the player can move between them
rooms = {
    "start": "public complaints desk",
    "end": "elections oversight department",
    "public complaints desk":
        {"north": "workers' compensation archive",
         "south": "city records office",
         "east": "mayor's private office",
         "west": "audit & finance department",
         "item": ""},
    "workers' compensation archive":
        {"south": "public complaints desk",
         "east": "mayor's private office",
         "item": "meeting minutes"},
    "city records office":
        {"north": "public complaints desk",
         "east": "consumer protections unit",
         "item": "voters registration log"},
    "mayor's private office":
        {"north": "employee break room",
         "south": "elections oversight department",
         "west": "public complaints desk",
         "item": "election projection"},
    "audit & finance department":
        {"east": "public complaints desk",
         "item": "internal financial audit findings"},
    "employee break room":
        {"south": "mayor's private office",
         "west": "workers' compensation archive",
         "item": "blueberry muffin"},
    "elections oversight department":
        {"north": "mayor's private office",
         "item": ""},
    "consumer protections unit":
        {"west": "city records office",
         "item": "city officials misconduct complaints"},
}

items_collected = []
user_move = []
restart_game = True
current_room = rooms["start"]

while current_room != "exit" and len(items_collected) < 6:
    if restart_game:
        restart_game = False
        print("Welcome to Exposé!")
        print("\nCollect 6 items to win the game, or the city falls to a corrupt mayor!")
        # Set and output the current room the player is in

        print(f"\nYou are in {current_room.title()}")

        items_available = [
            data["item"].title()
            for name, data in rooms.items()
            if isinstance(data, dict) and data.get("item")
        ]

        print("Items to be collected:")
        for x in items_available:
            print(f" - {x}")

        print("\n1. Move commands: go South, go North, go East, go West")
        print("2. Add to Inventory: get item name")
        print("3. Exit game: exit")

    print("Backpack:")
    for x in items_collected:
        print(f" - {x}")
    print("-------------------------------------")
    user_move = input("Enter your move:\n").lower().split(maxsplit=1)

    if len(user_move) == 0:
        print("Invalid command!")
        continue

    if user_move[0] == "exit":
        current_room = "exit"
        continue

    if len(user_move) < 2:
        if user_move[0].lower() == "go":
            print("\nGo where? (north/south/east/west)")
        elif user_move[0].lower() == "get":
            print("\nGet what?")
        else:
            print("Invalid command!")
        continue

    # Decision branching to handle different commands
    if user_move[0].lower() == "go":
        # Player decides to move to a direction
        if user_move[1].lower() in rooms[current_room]:
            # Player enters a valid "move" command, use the dictionary to move them to the new room
            current_room = rooms[current_room][user_move[1].lower()]

            if current_room == rooms["end"]:
                print("\nMAYOR FOUND! You lost")

                while True:
                    print("\nPlay again? (Y/N)")
                    user_move = input().lower()

                    if user_move == "y":
                        restart_game = True
                        items_collected = []
                        current_room = rooms["start"]
                        break
                    elif user_move == "n":
                        current_room = "exit"
                        break
                    else:
                        print("Invalid command!")


                continue

            print(f"\nYou entered {current_room.title()}")
            item = rooms[current_room]["item"]
            if item and item.title() in items_collected:
                print(f"\nYou already collected {item.title()}")
            elif item:
                print(f"Item available: {item.title()}")
            else:
                print("No item in this room.")
        else:
            # There is no such direction or a case where the direction exists
            print("Not a valid direction!")
    elif user_move[0].lower() == "get":
        item = rooms[current_room]["item"]

        if not item:
            print("No item in this room.")
            continue

        if user_move[1].lower() == item.lower():
            if item.title() in items_collected:
                print(f"\nYou already collected {item.title()}")
            else:
                items_collected.append(item.title())
                print(f"\nCollected: {item.title()}")
        else:
            print(f"Cannot get {user_move[1].title()}")
            print(f"Item available: {item.title()}")
    else:
        # Player enters an invalid command, provide an error message for input validation
        print("Invalid command!")
else:
    if current_room == "exit":
        print("\nYou EXITED the game. Thanks for playing!")
    else:
        print("\nYOU WON! You found aLL SIX ITEMS!: ", items_collected)