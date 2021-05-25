MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 300,
    "milk": 200,
    "coffee": 100,
}
userChoice = input("What would you like? (espresso, latte, cappuccino): ")
while userChoice != "off":
    if userChoice == "report":
        print('water: ' + str(resources['water']))
        print('milk: ' + str(resources['milk']))
        print('coffee: ' + str(resources['coffee']))
    elif userChoice == 'espresso':
        if resources['water']<MENU['espresso']['ingredients']['water'] or resources['coffee']<MENU['espresso']['ingredients']['coffee']:
            print('Sorry not enough ingredients')
        else:
            print('Insert coins')
    elif userChoice == 'latte':
        if resources['water']<MENU['espresso']['ingredients']['water'] or resources['milk']<MENU['espresso']['ingredients']['milk'] or resources['coffee']<MENU['espresso']['ingredients']['coffee']:
            print('Sorry not enough ingredients')
        else:
            print('Insert coins')
    elif userChoice == 'cappuccino':
        if resources['water']<MENU['espresso']['ingredients']['water'] or resources['milk']<MENU['espresso']['ingredients']['milk'] or resources['coffee']<MENU['espresso']['ingredients']['coffee']:
            print('Sorry not enough ingredients')
        else:
            print('Insert coins')
    userChoice = input("What would you like? (expresso, latte, cappuccino): ")

else:
    exit('turning off')