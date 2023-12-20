Welcome to My Mastermind
Task
The task is to create a problem that implements the mastermind game The game goes as such , you have a 4 digit code that is generated randomly or given through the command with 10 attempts at default. The user has to guess the code the numbers present in the code as well as their correction possition , if the possition isn't correction but the number is present in the code it shows up as a missplaced pieces , otherwise it is a wellplaced pieces

Description
I used the getopt function to handle the arguments from the command line and built a function that generates a random code if one is not provided. I have a for loop that iterates through the number of attemps the user has whether from input or default A function that a receives the user inputs using read then compares the user input code to the mastermind code It checks for well placed pieces which area pieces that are present in the code and in the correct possition and it also checks for missplaced pieces which are pieces that are present in the code but not in the correct possition It displays this after every attempt and if the code you enter is correct it displays Congrats you did it and ends the game

Installation
No extra steps needed to install works using C and bash which is nearly univerisal for all computing needs

Usage
You can use the program by simply executing it but you have the option to enter 1 or 2 commandline arguments which determine the code or the attempts respectivly You would need to use $./my_mastermind -c"1234" -t"10" with the values being interchangable depending what your desired outcome

./my_project argument1 argument2
The Core Team
Made at Qwasar SV -- Software Engineering School <img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'>
