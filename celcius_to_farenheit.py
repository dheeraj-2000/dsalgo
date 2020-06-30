print("press(1) for celsius to fahrenheit")
print("press(2) for fahrenheit to celsius")
print("enter the choice:")

choice=int(input())

if(choice==1):
    print("Enter the celcius value: ")
    celsius=input()

    fahrenheit=(celsius*1.8+32)
    print("Celcius to forenheit is: ",fahrenheit)

if(choice==2):
        print("Enter the Forenheit  value: ")
    fahrenheit=input()
    celsius=((fahrenheit-32)/1.8)
    print("Forenheit to Celcius: ",celsius)
