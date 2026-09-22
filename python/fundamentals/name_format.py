# Read a person's name in one line and assign to list person_name
# Input stripped of whitespace and formatted to title case
person_name = input(f"{'2.12 LAB: Name format':<22}\n" +
"=" * 22 + "\n\n" +
"What is your full name?\n\n").strip().title().split()

# Assign firstInitial from list person_name[0]
firstInitial = person_name[0][0] + "."

# Initialize middleInitial
middleInitial = ""


if len(person_name) < 3:
    # User Input (index): firstName (0) lastName (1)
    lastName = person_name[1]
else:
    # User Input (index): firstName (0) middleName (1 ... -2) lastName (-1)
    lastName = person_name[-1]
    middleInitial = person_name[1][0] + "."

# Output: lastName, firstInitial.middleInitial. or lastName, firstInitial.
print("=" * 22
+ "\n\nFormatted Name:"
+ f"\n\n{lastName}, {firstInitial}{middleInitial}")