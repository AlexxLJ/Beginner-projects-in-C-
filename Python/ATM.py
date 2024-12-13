balance = 1000

print("\t.:MENU.:")
print("1. Deposit money into the savings account.")
print("2. Withdraw money from savings account.")
print("3. Show available money.")
print("4. Exit.")

opcion = int(input("Select a menu option:  "))

print() 

if opcion == 1:
    extra = float(input("How much money do you want to input -> "))
    balance += extra
    print(f"Money in the account: {balance}")
elif opcion == 2:
    retirar = float(input("How much money do you want to withdraw -> "))
    if retirar>balance:
        print("You do not have that amount of money")
    else:
        balance -= retirar
        print(f"Money in the account: {balance}")
elif opcion == 3:
    print(f"Money in the account: {balance}")
elif opcion == 4:
    print("Thank you for using this bank ATM")
else:
    print("Error you got the wrong menu option")
