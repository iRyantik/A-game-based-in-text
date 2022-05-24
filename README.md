# Project plan: Title of the game:Ionia

Introduction:
Ionia is an one-player adventure game(AVG) based on a fusion of the theme of typical Japanese brave adventure light novels and the playing method of Dungeons & Dragons (DND) background.We make reference to some books and novels for designing characters . Technically, the game runs as a linear narrative text adventure game with randomly generated events.<br/>
Game rules:
You were reincarnated as a warrior in Another world called  Ionia, and the people of the village saw you as the savior of the evil Lord.Embark on the journey! Read the following instructions before choosing any of the path in front of you:<br/><br/>

*run this C++ game in terminal
*Only one player can enter Ionia in each game,each game you have 2 lives, meaning that the second death implies game over;<br/>
*start from the beginning or the last saved session;<br/>Once the game ends, you have to start a new game;<br/>
*Your adventure will begin with 3 random events selected independently from 3 events.After that, you will have to choose the paths in the main route until save and quit by typing the character '0' when appropriate. Then next time you can resume your game at suitable points. Eventually you will end up with the battle with the demon lord, which is the last main route event.;<br/>
*use keyboard to control your decision (select a/b/c/d/1/2/3/4/0 by typing the respective characters required in each question), so that your story can proceed;<br/>
*your selection of a,b,c or d will determine the chance of winning, or game over;<br/>
****Do not input invalid input as it may crash the program***<br>
*The game is saved in last.txt. The game checks if it has the past save when running the game. If you're entering a game for the first time,data.txt will be made to record the game.Otherwise, the game will continue from the last checkpoint.;<br/>


## How to win:<br/>
You have possess at least two items of the conditions 1~3 (should be confidential to player)::<br/>

## 1.main route part:<br/>
	*Companion:you succeed to have magician/knight as companion from several Heros system provided;
	*Armor:you succeed to get Heimerdinger’s appreciation and equipped by Hextech Armor; 
<br/><br/>
## 2. random events part:<br/>
	*sacred sword;
	*sacred potion;
<br/><br/>
## 3. hidden quest (choose math course in the Ionia Academy)<br/>
*the recognition of the sacred dragon (successfully answer two questions about calculus)<br/><br/>

### Features implemented:<br/>
- _Some of the printed text in the terminal are coloured_
- _Classical fantasy adventure theme_
- _Autosave game status_
- _No non-standard libaries are used_
- _Some random events_
- _Show your accomplishments after playing_
### Coding requirements 1 to 5:<br/><br/>

1.Generation of random game sets or events<br/><br/>

Firstly, we use struct to initialize the status of player, where initially he has 2 lives and other items 0. As he encounters more events, the game status varies.<br>Moreover, we use rand() function in the library #<cstdlib> for generating random numbers after the command "srand(time(NULL))" from #<ctime>, <br/>
to confirm it is nearly a random number. This helps us to determine the occurance of a series of events, like whether you can get a certain item or a random event would happen, for instance, it determines whether the player could get the sacred potion or the sacred sword.<br/><br/>

2. Data structures for storing game status<br/><br/>
This game is operated by a,b,c,d,0,1,2,3,4 on the keyboard. So there is a data structure whose members are characters. Each character in corresponds to a command line. The game uses struct to store and access the game status of the player in each round, ie, the number of lives, items currently have, names of companions and the current situation.
	
	
<br/><br/>
	
3. Dynamic memory management<br/><br/>
We use vectors to store the events encountered in a game set.After inputting the choice, the game status would be stored temporaily by a vector, working as a 2-D array, with type "round", which is previously declared in struct, by the push_back() command . <br/><br/>
	
4. File input/output (e.g., for loading/saving game status)<br/><br/>

output:
> We use the file stream module to get it. Include the library #<fstream>,open the file “last.txt” . The choices in the game will be recorded to the archive using the >> operator in the save function, with each round per line. Each integer in the round struct is separated by a \tab character.The command line file.close() executes in the save function. Also, when the game ends, last.txt would be replaced by a single Null character '\0' so that the next game must be a fresh start.<br/><br/><br/>
	
input:
> We use two input files: last.txt and math_test.txt. last.txt records the game status, so we read the file and recover as a vector, then resume the game in the function resume_last(). Moreover, the math test is stored in math_test.txt. The terminal will print appropriately and mechanically the content of the test line by line when certain function calls.
<br/><br/>	
	
5.Program codes in multiple files<br/><br/>
Since the game is made up of events and routes, we split the code in 2 main routes to help facilitate group work and readibility. Most of the codes are in main.cpp.
A route is situated in hello.cpp, with the header file hello.h in the same directory.<br/><br/>
	
	
# A quick start to the game:<br/><br/>
Step 1: **Download the file and go to the respective directory in the Linux terminal by cd command**<br/>
Step 2: Type ***make main***<br/>
Step 3: Type ***./main***<br/>
Step 4: Enjoy the game! ***Save and quit if needed by typing the character zero.*** ___Do not type invalid input!___<br/>
