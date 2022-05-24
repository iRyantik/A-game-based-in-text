#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include "hello.h"



using namespace std;



//Route functions declaration//

int dragon_test();
int checklife(int life);
int check_win(round r);
//Route functions//





/*************declare a save function to save the game status *****************************/
void save(vector <round> status) {
    ofstream fout("last.txt");
    for (int i = 0; i < status.size(); i++) {
        fout << status[i].event << "\t" << status[i].choice << "\t" << status[i].companion << "\t";
        fout << status[i].armour << "\t" << status[i].holy << "\t";
        fout << status[i].life << "\t" << status[i].recognition << "\t"<<status[i].function << "\n";

    }
    fout.close();
}


//Route functions declaration//
int step1_1(vector<round>& status);
int step2_1(vector<round>& status);
int step2_2(vector<round>& status);
int step3(vector<round>& status);
int step4(vector<round>& status);
int step5(vector<round>& status);
int step6(vector<round>& status);
int step7(vector<round>& status);
int dragon_test();
int checklife(int life);
int check_win(round r);
//Route functions//



/****************************************well paved road************************************************/
int castle(vector<round>& status) {
    cout<<" this is the last round of the game. \033[1;31mYou cannot quit.\033[0m\n";
    cout<<"Press any key to continue.\n";
    string s;cin>>s;
    round r = status.back();r.event++;
    srand(time(NULL));
    cout<<"You have entered the castle of Humblemann,";
    if ((rand()%100)>50){
        cout<<" where you took the legendary armour of the last valiant warrior, since there is nobody else.\n";
        r.armour ++;
    }
    else{
        cout<<" which nothing is found.\n";
    }
    save(status);
    cout<<"The demon lord suddenly appears. The last battle begins...\n\n";
    check_win(r);
    return 0;
}
int grad(vector<round>& status) {
    round r = status.back();int x=r.choice;
    cout<<" this is the last round of the game. \033[1;31mYou cannot quit.\033[0m\n";
    cout << "After the graduation ceremony, Bubble appeared, asking:\n";
    cout << "Bubble: Congradulations. Do you want more preparation before the Last Battle?\nYour choice:\n";
    cout << "[1]I am so satisfied with the life now and no more expedition please.\n";
    cout << "[2]I want to pay a visit to the Royal Collection of Arsenals\n";
    cout << "[3]Please give me some time in Schwarz Volcano\n[4]the castle of Humblemann\n\n";
    cout << "[0]save & exit the game" << endl;
    cout << "Your choice:"; int n; cin >> n;
    r.choice = n;
    switch (n) {
    case 1:
    {cout << "Bubble gets furious because of your incorrect choice.\n";
    cout << "She took away you 1 life and send you directly to the last battle.\n";
    //take away 1 life, send to checklife&check_win
    r.life--; status.push_back(r);
    break; }

    case 2:
    {if (x == 2) {
        cout << "Welcome to the Royal Collection of Arsenals\n";
        srand(time(NULL));
        int parameter = rand() % 100;
        if (parameter < 60) {
            r.armour++;
        }
    }//random to get an armour with probability 60%
    else {
        cout << "You are not permitted to visit the Royal Collection of Arsenals\n";
    }break; }
    case 3:// the condition of making the armour is to do internship in the shop
    {if (x == 3) {
        cout << "You have successfully made an armour to defeat the demon lord.\n";
        cout << "Unfortuately due to extreme heat, you have lost 1 life.\n";
        r.armour++; r.life--;
    }
    else {
        cout << "You have made your way to the volcano.\nUnfortuately due to extreme heat, you have lost 1 life.\n";
        r.life--;
    } break; }
    cout << "After all preparations, you are involved in the last battle...\n";
    }status.push_back(r);
    save(status);
    return check_win(status.back());
}
int apprentice(vector<round>& status) {
    round r = status.back(); r.event++; int n; r.function=21;
    cout << "Your choice:apprentice adventurer in jungle\n";
    cout << "This capstone course requires 2 people in opposite sex to form a team.\n";
    cout << "Choose one of them:\n[1]Harold, healer\n[2]Shefferold, swordsman\n[3]Kingston, knight\n[4]Morrison, magician\n\n";
    cout << "Your choice:";
    cin >> n; r.choice = n;
    cout << "You fell in love with your partner in the journey.\n\n";
    cout << "However, you saw an envoy from the deomon lord meeting with Harold and Shefferold \n";
    cout << "when you pretended to sleep in midnight.\n\n";
    cout << "You realised that the friendship with them would not last long as in opposite factions.\n";
    cout << "Therefore, if you fell in love with Kingston or Morrison, you would accompany him/her to the Last Battle\n\n";

    if ((n == 3) or (n == 4)) {
        cout << "You have earned a valuable companion.\n\n";
        r.companion++;
    }
    if ((n == 1) or (n == 2)) {
        cout << "sorry for delivering a bad news to you. \n\n";
    }
    cout << "\x1B[34mThroughout the camp, the camp leader emphasized the lost treasure of the last valiant warrior,\n";
    cout << "including his impenetrable armour which would not decay nor be destroyed by the demon King, \n";
    cout << "inside the Castle of Humblemann\x1B[0m \n";
    cout<<"\n\nDo you want to save and quit? Press [0] to quit the game.\n\n";
    status.push_back(r);save(status);
    cin>>n;if (n==0){
        return 1;
    }
    grad(status);

    return 0;
}

int dept_war(vector<round>& status) {int n;
    cout << "Your choice:Department of war\n\n";
    cout << "The Department head appreciates yout effort and efficiency so much\n";
    cout << "that he promised you a free visit to the Royal Collection of Arsenals\n\n";
    round r = status.back();r.function=22;
    r.event++;
    r.choice = 2;
    cout<<"\n\nDo you want to save and quit? Press [0] to quit the game.\n\n";
    status.push_back(r);save(status);
    cin>>n;if (n==0){
        return 1;
    }
    grad(status);return 0;
}
int shop(vector<round>& status) {int n;
    cout << "Your choice: A shop worker\n";
    cout << "Your experience in the capital facilitates your relationship with city dwellers,\n";
    cout << "\x1B[33mincluding the best armour maker.\x1B[0m\n\n";
    cout << "\x1B[31m";
    cout << "You have learnt that the best armour can be formulated in the Scharz Volcano, the Mother of Earth.\n";
    cout << "Note that the Mother of Earth is so hot that costs you 1 life if you choose to pay a visit.\n";
    cout << "Your hard work in memorizing the formula gives you confidence doing so after graduation\n\x1B[0m\n";
    round r = status.back();
    r.event++;r.function=23;
    r.choice = 3;
    cout<<"\n\nDo you want to save and quit? Press [0] to quit the game.\n\n";
    status.push_back(r);save(status);
    cin>>n;if (n==0){
        return 1;
    }
    grad(status);return 0;
}


int math(vector<round>& status) {int n;round r = status.back();
    r.event++;r.choice = 1;r.function=24;
    cout << "Dragon:\nGreetings, guys.\nLet's have a math test during class.";
    cout << "If you can answer at least 2 questions correctly,\n";
    cout << "\tI will give you my special ability to fight the demon lord.\n";
    cout<<"\n\nDo you want to save and quit before the test? Press [0] to quit the game.\n\n";
    
    status.push_back(r);save(status);
    cin>>n;if (n==0){
        return 1;
    }if (dragon_test() > 1) {
        cout << "Congratulations,you get his blessings'n";r.recognition++;
    }
    else {
        cout << "test failed\n";
    }
     r = status.back();
    r.event++;r.choice = 1;r.function=241;
    
    cout<<"\n\nDo you want to save and quit after the test? Press [0] to quit the game.\n\n";
    
    status.push_back(r);save(status);
    cin>>n;if (n==0){
        return 1;
    }
    
    grad(status);return 0;
}
int not_math(vector<round>& status) {
    cout << "You have enjoyed most of the time of your school life.\nHowever, capstone is one of the graduation requirements\n";
    cout << "Choose one of the internship opportunities provided:\n";
    cout << "[1]apprentice adventurer in jungle\n[2]Department of war\n";
    cout << "[3]a small-sized random shop in the Kingdom of Ionia\n\n";
    cout<< "any other integer for save and quit the game.\n\n";
    round r = status.back(); r.event++;r.function=25;cin>>r.choice;status.push_back(r);save(status);
    int n=r.choice;
    if (n == 1) {
        apprentice(status);
    }   if (n == 2) {
        dept_war(status);
    }   if (n == 3) {
        shop(status);
    }
    else{
        return 1;
    }

    return 0;
}


int school(vector<round>& status) {
    round r = status.back(); r.event++;r.function=26;
    cout << "\x1B[32mYour choice: the Academy of Ionia\x1B[0m\n";
    cout << "There are 4 subjects that you can major in. Pick 1 of them: \n";
    cout << "[1]Physical sciences\n[2]math\n[3]magic\n[4]sword skills\n";
    cout<<"\nPress any other integer to save and quit the game.\n\n";
    int choice;cin >> choice; 
    r.choice = choice; status.push_back(r);save(status);
  if (choice==2){
      if (math(status)==1){
          return 1;
      }
  }
  if ((choice==1)||(choice==4)||(choice==3)){
      if (not_math(status)==1){
          return 1;
      }
  }
  else{
      return 1;
  }
    return 0;
}
int lake_god_1_2(vector<round>& status) {round r = status.back(); r.event++;r.function=27;
    cout << "After meeting the middle-aged, suddenly,\n";
    cout << "the water in the lake goddness appeared out of the swirling revolving water\n";
    cout << "Lake goddness:\nDear warrior, the bravest man in Inoia, I am Bubble, the lake goddness,\n";
    cout << "which has the command of time and space.\n";
    cout << "As a diety, I cannot interferene politics in Ionia directly.\n";
    cout << "A solid, firm armour is a must in order to resist the fierece attack from the demon lord.\n";
    cout << " In order to fight the demon lord, I can teleport you to one of the following three places:\n\n";
    cout << "[1]the Academy of Inoia, learing skills and techniques.\n";
    cout << "After recieving a full degree training, you will be resumed in the current time to continue your journey\n";
    cout << "[2]the castle finding a merchant to trade an armour\n";
    cout << "[0]save & exit the geme"<<endl;
                                        

    int choice;
    cin >> choice;
    r.choice=choice;status.push_back(r);save(status);//save the choice of the game
    switch (choice) {
    case 1:
        {if (school(status)==1){
            return 1;//call the school function and catch if the user wants to quit the game
        };
        break;}
    case 2:
        {if (castle(status)==1){
            return 1;//call the castle function and catch if the user wants to quit the game
        };
        break;}
    default:
        return 1;

    }
    return 0;
}


int say_sorry_1_1_1(vector<round>& status) {
    round r = status.back(); r.event++;r.function=28;
    cout << "Your choice: say sorry";
    cout << " You:\nSorry, Ma'am. You always look young and beautiful and strong as ever before.\n";
    cout << "Could you be my guide to defeat the demon lord?\n";
    cout << "the lady:\nYou may need the sacred sword or sacred potion to defeat the demon lord.\n:";
    cout << "Sorry but I refuse to go with you. That's all I can help you. Bye.\n\n";
    status.push_back(r);save(status);
    if(lake_god_1_2(status)==1){
        return 1;
    }
    return 0;
}
int apologize_1_1_2(vector<round> status) {
    round r = status.back(); r.event++;r.function=29;
    cout << "Your choice: apologize\n";
    cout << "You prostrated to apologize, pleading for the middle-aged lady to accept.\n";
    cout << "You:\nI give my deepest apology for the misconduct that hurt you.\n";
    cout << "The middle-aged lady was delighted and accepted your apology.\n";
    int prev_choice = r.choice;
    switch (prev_choice) {
    case 1:
        cout << "Knight ";
        break;
    case 2:
        cout << "Magician ";
        break;
    }
    cout << "wants to be your partner. Would you accept it?\n[1] agree\n[2] disagree\n";
   cout<<" Press any other integer to quit the game.You will choose companion when when resume.\n\n";
    cout << "Your choice: ";
     int n;cin >> n;
    if (n == 1) {
        r.companion++;
    }
    else if (n!=2){
        return 1;
    }
    status.push_back(r);
    save(status);
    if(lake_god_1_2(status)==1){return 1;}
    return 0;
}
int Approach_her_1_1(vector<round>& status) {
    round r = status.back(); r.event++;r.function=210;
    cout << "Your choice: Approach her\n";
    cout << "When you were approaching her, you see her wiping her sword \n";
    cout << "and moaned \"Sword O Sword, we are now 40 years old and without a husband nor boyfriend\"\nWhat a pity!" << endl;
    cout << "You appear when she spoke out her age. She got angry, roaring";
    cout<<"\"how dare you sneaking around and knowing my age\"\n";
    cout << "You now have 2 options:\n[1]say sorry\n[2]prostrate to apologize\n";
    cout << "[0]save & exit the game" << endl;
    cout << "Your choice:\n"; int n; cin >> n;
    r.choice = n; 
    status.push_back(r); save(status);
    switch (n) {
    case 1:
    {if(say_sorry_1_1_1(status)==1){
        return 1;
    };
    break; }
    case 2:
    {if(apologize_1_1_2(status)==1){
        return 1;
    };
    break; }
    default:
        return 1;
    }
    return 0;
}

int hide(vector<round>& status) {
    round r = status.back(); r.event++;r.function=211;int n;
    cout << "Your choice: hide\n";
    cout << "Unfortuately you were captured by a magic sensor from a went-by middle-aged magician for security purposes\n ";
    cout << "magician: Why are you sneaking around here? You so suspicious, huh?\nYou now have 2 options: \n\n";
    cout << "[1]say sorry\n[2]prostrate to apologize\n";
    cout << "[0]save & exit the game" << endl;
    cout << "Your choice:";
    cin >> n; r.choice = n; status.push_back(r); save(status);
    cout << "\n\n";
    switch (n) {
    case 1:
        say_sorry_1_1_1(status);
        break;
    case 2:
        apologize_1_1_2(status);
        break;
    default:
    {return 1;
    break; }
    }
    return 0;
}


int lake_1(vector<round>& status) {
    int n; round r = status.back(); r.event++;
    cout << "Your choice:\nleft\n";
    cout << "As you are wandering, you heard some human voices behind the bushes.\n";
    cout << "A oval blue lake behind was surrounded by mountains dressed in fog.\n";
    cout << "You peeped through the leaves and saw a middle-aged woman.\n";
    cout << "Do you want to approach her or continue hiding in the bushes?\n";
    cout << "Choose\n[1] for Approach her\n[2] for Hide\n";
    cout << "[0]save & exit the game" << endl;
    cout << "Your choice:";
    cin >> n; r.choice = n; status.push_back(r); save(status);
    switch (n) {
    case 1:
        Approach_her_1_1(status);
        break;
    case 2:
        hide(status);
        break;
    default:
        return 1;

    }
    return 0;
}





int hello(vector<round>& status)
{
    int n; round r = status.back(); r.event++;r.function=100;
    cout << "Your choice: well-paved road.\n";
    cout << "There is a junction in the end of the path. Would you want to go to the left or right?\n";
    cout << "Choose\n[1] for left\n[2] for right\n";
    cout << "[0]save & exit the game" << endl;
    cout << "Your choice:";
    cin >> n; r.choice = n; status.push_back(r); save(status);
    switch (n) {
    case 1:
        lake_1(status);
        break;
    case 2:
        castle(status);
        break;
    default:
    return 1;

    }
    return 0;
}


