# AUTHOR_NAME: Terence Michale
# 3.15 LAB: Seasons

valid_months = {"January": {31: "Winter"},
                "February": {29: "Winter"},
                "March": {19: "Winter", 31: "Spring"},
                "April": {30: "Spring"},
                "May": {31: "Spring"},
                "June": {20: "Spring", 30: "Summer"},
                "July": {31: "Summer"},
                "August": {31: "Summer"},
                "September": {21: "Summer", 30: "Autumn"},
                "October": {31: "Autumn"},
                "November": {30: "Autumn"},
                "December": {20: "Autumn", 31: "Winter"}}

input_month = input().strip().title()
input_day = input()

season = ""

if input_month in valid_months:

    if input_day.isdigit():
        input_day = int(input_day)

        if input_day > 0 and input_day <= min(valid_months[input_month]):
            min_season = min(valid_months[input_month])
            season = valid_months[input_month][min_season]

            print(season)
        elif input_day > 0 and input_day <= max(valid_months[input_month]):
            max_season = max(valid_months[input_month])
            season = valid_months[input_month][max_season]

            print(season)
        else:
            print("Invalid")

    else:
        print("Invalid")

else:
    print("Invalid")