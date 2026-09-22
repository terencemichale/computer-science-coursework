from  datetime import datetime

"""2-3 Assignment: PyCharm Introduction

Program to greet the user with their calculated birth year.

This script prompts the user to enter their name. Then, prompt the user to 
enter their age. The script calculates and displays their birth year.

This assignment tests taking user input, manipulate data and output in format.
Example:
    Run the script from the command line:

        $ python NameAge.py
        What is your name? Alex
        How old are you? 30
        Hello Alex! You were born in 1995

Attributes:
    name (str): The user's name input by the user.
    age (int): The user's age input by the user.
    birth_year (int): The user's birth year calculated based on current year.
        Calculated dynamically using the current year extracted from system
        date time.
        
Todo:
    * Submit a Microsoft Word document of 2 to 3 paragraphs explaining some of 
        the features of PyCharm and why they can be useful.

.. _Google Python Style Guide:
   https://google.github.io/styleguide/pyguide.html

"""

# Prompt the user to enter their name.
name = input("What is your name? ").strip().title()

# Prompt the user to enter their age.
age = input("How old are you? ")

# Additional (optional) logic to make sure user does not enter:
# alphabets or negative numbers
while not age.isdecimal():
    age = input("How old are you in digits? ")

# Calculate the year the user was born based on their age.
birth_year = datetime.now().year - int(age)

# Display a greeting message that includes the user's name and birth year.
print(f"Hello {name}! You were born in {birth_year}.")
