
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include "hello.h"

using namespace std;




//Route functions declaration//
int step1_1(vector<round> &status);
int step2_1(vector<round> &status);
int step2_2(vector<round> &status);
int step3(vector<round>& status);
int step4(vector<round>& status);
int step5(vector<round>& status);
int step6(vector<round>& status);
int step7(vector<round>& status);
int dragon_test();
int checklife(int life);
int check_win(round r);
//Route functions//


/*************************rugged road**************************************************************************/
int step1_1(vector<round>& status) {
    round r = status.back();
    r.event++;
    char s1_1;
    cout << " You walk on the road to the city and soon arrive at Piltover..." << endl;
    cout << "Suddenly a carriage speeds by, threatening to hit the maiden by the wayside. You choose to...\n\n" << endl;
    cout << "a:It's none of my business to turn a blind eye" << endl;
    cout << "b:Come to the girl's aid" << endl;
    cout << "0:save & exit the game" << endl;
    cin >> s1_1;
    r.function = 111;
    if (s1_1 == 'a') {
        r.choice = 1;
        status.push_back(r); save(status);
        if (step2_1(status) == 1) {
            return 1;
        };
    }
    if (s1_1 == 'b') {
        r.choice = 2;
        status.push_back(r); save(status);
        if (step2_2(status) == 1) {
            return 1;
        };
    }
    else {
        return 1;
    }
    return 0;
}
int step2_1(vector <round>& status) {
    char s2_1;
    round r = status.back(); r.event++;
    cout << "You go ahead and see the Overlord" << endl;
    cout << "The Lord meets you and recommends some companions to you. They are  a seemingly reliable swordsman, and a stuffy female knight..." << endl;
    cout << "a:Swordsmen" << endl;
    cout << "b:The prim lady knight" << endl;
    cout << "0:save & exit the game" << endl;
    cin >> s2_1;
    r.function = 121;
    if (s2_1 == 'a') {
        cout << "'Warm-hearted warrior, at your service.' You successfully recruited him" << endl;
        r.choice = 1;
        status.push_back(r);
        save(status);
        if (step3(status) == 1) {
            return 1;
        };
    }
    if (s2_1 == 'b') {
        cout << "'Honored warrior, it's my pleasure to serve you.' You successfully recruited him" << endl;
        //win_companion//
        //so Companion index +1//
        r.choice = 2; r.companion++;
        status.push_back(r);
        save(status);
        if (step3(status) == 1) {
            return 1;
        };
    }
    else {
        return 1;
    }return 0;
}
int  step2_2(vector <round>& status) {
    char s2_2; round r = status.back(); r.event++;
    cout << "You managed to stop the carriage and save the girl. It looks like a noble carriage. Someone got out of it..." << endl;
    cout << "I am sorry, my fair lady, and this brave gentleman.’The owner of the carriage was a young magician..." << endl;
    cout << "’You say that you are one of the brave men who went to fight against the devil.\nVery well, I will take you to the Lord of the cityand help you to collect your companions, ‘ said the young gentleman" << endl;
    cout << "'Sure'You are led to the Lord" << endl;
    cout << " The Lord meets you and recommends some companions to you.\nThey are the mage you have just met, a seemingly reliable swordsman, and a stuffy female knight..." << endl;
    cout << " Choose a companion and persuade him to fight with you" << endl;
    cout << "a:Young wizard you met" << endl;
    cout << "b:The prim lady knight" << endl;
    cout << "c:Swordsmen" << endl;
    cout << "0:save & exit the game" << endl;
    cin >> s2_2;
    r.function = 122;
    if (s2_2 == 'a') {
        cout << "'Warm-hearted warrior, at your service.' You successfully recruited him" << endl;
        //win_companion//
        //so Companion index +1//
        r.companion++;
        status.push_back(r); save(status);
        if (step3(status) == 1) {
            return 1;
        };


    }
    if (s2_2 == 'b') {
        cout << "'The stodgy lady knight saw you saving lives in the street, and it seems she's not happy that you risked running into a nobleman to save a commoner. She turned you down" << endl;
        status.push_back(r); save(status);
        if (step3(status) == 1) {
            return 1;
        };
    }
    if (s2_2 == 'c') {
        cout << "'Warm-hearted warrior, at your service.' You successfully recruited him" << endl;
        status.push_back(r); save(status);
        if (step3(status) == 1) {
            return 1;
        };
    }
    else {
        return 1;
    }
     return 0;
}
int step3(vector <round>& status) {
    char s3; round r = status.back(); r.event++;
    cout << " 'Dear gallant, Professor Hermordinger is forging Hex armor, and it would be a great help if he would lend it to you. You can visit him.‘ " << endl;
    cout << "You choose to visit him..." << endl;
    cout << "’You're a brave young man. I'd be happy to help you. But the armor hasn't been assembled yet, and I'm having some technical problems. Would you like to help me‘, said Professor Hermordinger" << endl;
    cout << " The truth is that Hex is a dangerous technology, and professor Hermordinger is asking you to help him conduct human experiments on companion you've just recruited... Are you going to say yes?" << endl;
    cout << "\na.Yes\n";
    cout << "b.No\n";
    cout << "0:save & exit the game" << endl;
    cin >> s3;
    r.function = 13;
    if (s3 == 'a') {
        status.push_back(r); save(status);
        if (step4(status) == 1) {
            return 1;
        };
    }
    if (s3 == 'b') {
        status.push_back(r); save(status);
        if (step5(status) == 1) {
            return 1;
        };
    }
    else {
        return 1;
    }
    return 0;
}
int step4(vector <round>& status) {
    round r = status.back(); r.event++;
    r.function = 14;
    srand(time(NULL));
    int s4 = 0 % 10; //for testing only
    if (s4 > 4) {
        cout << "Unfortuately you companion has died.\n";
        if (r.companion > 0)
        {
            r.companion--;
        }status.push_back(r); save(status);
        if (step5(status) == 1) {
            return 1;
        };
        //if you have correct companion,champion died and no hex armor //
        //so Companion index -1//

    }
    else {
        r.armour++; status.push_back(r); save(status);
        cout << "You have successfully got the hex armour.\n";
        if (step5(status) == 1) {
            return 1;
        };
        //champion live and you get hex armor//
        //so Armor index +1//

    }return 0;
}

int step5(vector <round>& status) {
    char s5; round r = status.back(); r.event++;
    cout << "You choose to leave Piltover.." << endl;
    cout << "You have discovered a passage to the dragon's secret land..Are you willing to go?" << endl;
    cout << "a.Yes" << endl;
    cout << "b.NO" << endl;
    cout << "0:save & exit the game" << endl;
    cin >> s5;
    r.function = 15;
    status.push_back(r); save(status);
    if (s5 == 'a') {
        if (step6(status) == 1) {
            return 1;
        };
    }
    if (s5 == 'b') {
        if (step7(status) == 1) {
            return 1;
        };
    }
    else { 
        return 1; }
    return 0;
}
int step6(vector <round>& status) {
    round r = status.back(); r.event++;
    int s6;
    r.function = 16;
    cout << "The wise Dragon will ask you a question. You cannot save and quit the game when answering his questions.\n";
    cout<<"If you answer it correctly, you will get his blessing. He sees that you are a traveler from earth, and he asks:" << endl;
    cout<< "print any integer to go on"<<endl;
    cin>>s6;
    if (s6==0){
        return 1;
    }
    if (dragon_test() > 1) {
        cout << "Congratulations,you get his blessings'n";
        r.recognition++;
        if (step7(status) == 1) {
            return 1;
        };
    }
    else {
        cout << "test failed\n";
        
    }
    if (step7(status) == 1) {
            return 1;
        };status.push_back(r);save(status);
 return 0;
}

int step7(vector <round>& status) {
    round r = status.back(); r.event++;
    srand(time(NULL));
    r.function = 17;
    int s7 = rand() % 10;
    int s7_2 = rand() % 10;
    cout<<" this is the last round of the game. \033[1;31mYou cannot quit.\033[0m\n";
    cout<<"Press any key to continue.\n";
    string s;
    cin>>s;
    if (s7 > 4) {
        //scared sword code//
        cout << "The sacred sword trial begins, and only the bravest will be chosen" << endl;
        if (s7_2 > 4) {
            cout << "There is no doubt that you are the bravest warrior. Congratulations on being chosen by the Sword!" << endl;
            //sword_index+1//
            r.holy++; }
        else {
            cout << "sorry but there's nothing you can get\n";
        }
    }
    else {
        //scared medicine code//
        cout << "The sacred potion trial begins, and only the wisest will be chosen" << endl;
        if (s7_2 > 4) {
            cout << "There is no doubt that you are the wisest warrior. Congratulations on being chosen by the Potion!" << endl;
            //sword_index+1//
            r.holy++;
        }
        else {
            cout << "sorry but there's nothing you can get\n";
        }
    }status.push_back(r); save(status);
    cout << "You have arrived at the demon City" << endl;
    //return nothing to see whether you win
    return check_win(r);
}
/**********************************  content_page, checklife, check_win    *******************************************************/
void content_page() {
    cout << "\t\t***********\tWelcome to Ionia\t*************" << endl;
    cout << "\tYou were reincarnated as a warrior in Another world called Ionia,\n" << endl;
    cout << "\tand the people of the village saw you as the savior of the evil Lord.\n" << endl;
    cout << "\tEmbark on the journey!\n\n";
}
int checklife(int life) {
    cout << "life checked\n";
    cout << "You have " << life << " live(s) left.\n";
    if (life < 1) {
        cout << "game over\n"; return 1;
    }

    return 0;
}


int check_win(round r) {
     //**********/ check whether the player has fulfilled the requirements of winning
     //if the player wins, print "you win" in gold colour, else print "you loose 10 times"
    cout << "let's check if you win ..." << endl;
    cout<<"event\tlast choice\tarmour\tholy\tlife\trecognition\tfunction\n";
    cout << r.event << "\t" << r.choice << "\t" << r.companion << "\t";
        cout << r.armour << "\t" << r.holy << "\t";
        cout << r.life << "\t" << r.recognition<<"\t" << r.function << "\n";
    if (r.life < 1) {
        for (int i = 0; i < 10; i++) {
            cout << "You loose\n";
            return 0;
        }
    }
   
    int victory = r.companion + r.armour + r.holy + r.recognition;
    if (victory >= 2) {
        cout << "\t\t\x1B[33m~YOU WINNNNNNNNNNNNN!~\033[0m" << endl;}
    else{
        for (int i = 0; i < 10; i++) {
            cout << "You loose\n";}
        }
    //once the game is finished, make the file last.txt blank
    ofstream fout("last.txt");
    fout<<'\0'<<endl;
    fout.close();
    return 0;
}
/**********************  random events     ******************************************************************/
void random_event_one() {
    cout << "You have encountered a slime on the way to the castle of the demon lord.\n";
    cout << "You will:\n\n" << endl;
    //list the choices

    cout << "\x1B[33m1.\tFlee, go away from the slime\n";//print in gold colour

    cout << "2.\tSummon magic “fire ball”\n";

    cout << "3.\tFeed it with grass\x1B[30m\n";

    cout << "\x1B[31m";//print in red colour
    int selc;cin>>selc; switch (selc) {
    case 1:
        cout << "(1)you cannot go back\n\033[0m"; break;
    case 2:
        cout << "(2)magic “fireball” is completed and the slime is boiled into steam\n\033[0m";break;
    case 3:
        cout << "(3)you have a new friend called slime\n\033[0m"; break;
    default:
        cout << "please input a number 1,2, or 3\n\033[0m"; random_event_one();
    }
}

void random_event_two(vector <round> &status) {
    int selc;round r=status.back();r.event++;
    cout << "You meet a suspicious old man who sells bottles of suspicious potions\n";
    cout << "You will:\n\n" << endl;
    cout << "\x1B[33m1.\tIgnore him and proceed\n";

    cout << "2.\tBuy 1 and immediately drink it\n\033[0m";
    srand(time(NULL));
    int parameter = (rand() % (10) + 1);
    cin >> selc;
    switch (selc) {

    case 1:
        cout << "You:\nWords have it the potions may be poisonous and fatal. Lucky that I have not touched any of the potions.\n";

        break;
    case 2:
    {if (parameter >= 7) {
        cout << "\033[0mitem: holy potion get\n";
        //change the vector such that the entry of holy potion +1
        r.holy++; 
    }
    else {
        cout << "Words have it the potions may be poisonous and fatal. Do not trust suspicious guys!\n";
        r.life--;
        //change the vector such that the entry of life minus 1

        
    }break;}

    default:
    {cout << "invalid input\n"; random_event_two(status); }
    }status.push_back(r);save(status);checklife(status.back().life);
  
}

/*********************************  dragon test ******************************************************/
int dragon_test() {
    int ans = 0;
    int correct = 0;
    int anskey[5] = { 2,3,4,4,1 };
    ifstream finq;
    finq.open("math_test.txt");

    string math_line;
    cout << "Dragon: Let f:R->R be a continuous function.\n";
    cout<<"Select the correct option by typing the corresponding one in [].\n";
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 9; j++) {

            getline(finq, math_line);
            cout << math_line << endl;
        }
        cin >> ans;
        if (ans == anskey[i]) {
            cout << "correct" << endl;
            correct++;
        }
        else {
            cout << "wrong" << endl;
        }
    }return correct;
}
/************************************  new_game()  ***************************************************/
int new_game(int& x) {
    //initialize the game status, each new game the player has 2 lives
    vector<round> status;
    round status_init;
    status_init.event = 0;
    status_init.companion = 0;
    status_init.armour = 0;
    status_init.holy = 0;
    status_init.life = 2;
    status_init.function = 0;status.push_back(status_init);
    cout << "You were born as a warrior in Another world named by Ionia,\n";
    cout << "and the people of the village saw you as the savior of the evil Lord.\n";
cout<<"Before going on the journey, you can warm up for 3 days,";
cout<<" which is represented by 3 random events.\n";
cout<<"You cannot save and quit during the random events.\n";
//3 random events
srand(time(NULL));
for(int i=0;i<3;i++){if(status.back().life<1){x=0;return 0;}

    cout<<"Press any key to continue.\n";
    string s;cin>>s;
    int u=rand()%3;
    if (u==0){random_event_one();}
    if (u==1){random_event_two(status);}
    else{cout<<"Today is a sunny day. I am walking a dog in a garden.\n";}
}
cout << "Embark on the journey!\n\nChoose the path in front of you\n\n";
    cout << "1.  A rugged path covered with jungle\n";
    cout << "2.  A well-paved road \n";
    int choice; cin >> choice;
    if (choice == 1) {
        status_init.event = 1;status_init.function= 0;
        status.push_back(status_init);save(status);
        x=step1_1(status);
        if(x==1){
            x=0;return x;
        }
       
    }
    if (choice == 2) {
        status_init.event = 100;status_init.function=0;
        status.push_back(status_init);save(status);
        x=hello(status);
        if(x==1){
            x=0;return x;
        }
    }
    else{x=0;cout<<" this is the first round of the game. \033[1;31mYou cannot save.\033[0m\n"; return x;}
   return 0;
}

/******************************** resume_last()  *******************************/
int  resume_last(int& x) {//maybe need to modify more parameters?
    //try to open last.txt (stores items and progress)
    ifstream fin("last.txt");
    // if empty, the while loop calls new_game()
    if (fin.fail()) {
        cout << "no past unclear record. Start a new game directly.\n\n" << endl; x = 1; return 1;
    }
    // input the data as a vector to continue the game
    vector <round> status;
    int w;
    int c;
    int details; int count = 0; round r;
    while (fin >> details) {
        switch (count % 8) {
        case 0:
            r.event = details;
            break;
        case 1:
            r.choice = details;
            c=details;
            break;
        case 2:
            r.companion = details;
            break;
        case 3:
            r.armour = details;
            break;
        case 4:
            r.holy = details;
            break;
        case 5:
            r.life = details;
            break;
        case 6:
            r.recognition = details;
        case 7:
        { r.function = details;
        w = details;
        status.push_back(r);
        break; }

        }

        count++;
    }
    save(status);x = 1;

if(w==111){
    if(c==1){
        step2_1(status);
    }
    if(c==2){
        step2_2(status);
    }
}

else if(w==121){
    step3(status);
}
else if(w==122){
    step3(status);
}
else if(w==13){
    step4(status);
}
else if(w==14){
    step5(status);
}
else if(w==15){
    step6(status);
}
else if(w==16){
    step7(status);
}
else if (w == 21) {
    grad(status);
}
else if (w == 22) {
dept_war(status);
}
else if (w == 23) {
shop(status);
}
else if (w == 241) {
grad(status);
}
else if (w == 24) {
math(status);
}
else if (w == 25) {
not_math(status);
}
else if (w == 26) {
school(status);
}
else if ((w == 27)||(w == 28)||(w == 29)) {
lake_god_1_2(status);
}

else if (w == 210) {
Approach_her_1_1(status);
}
else if (w == 211) {
hide(status);
}
else if (w == 100) {
lake_1(status);
}
    return 0;
}



/********************************  instructions()  *****************************/
int instructions(int& x) {
    //read and print the instructions.txt for game instructions in green colour
    string lines;
    ifstream fin;
    fin.open("instructions.txt");
    while (getline(fin, lines))
    {
        cout << "\033[1;32m" << lines << "\033[0m\n\n";
    }
    cout << "Do you want to go back to content_page or start a new adventure?\n";
    cout << "Press:\n[0]\tto end the program\n[1]\tto start new game\n[2]\tto continue with the last saved file\n[3]\tto view content page" << endl; \
        cin >> x;
    if (x == 3)
    {
        content_page();
    }
    return 0;
}

/********************************  main  ***************************************/


//
int main() {
    int x, y=0; // x denotes the game status- whether you want to quit
    content_page();
    //in this moment can choose start new game, continue with older files, or start new game????//// 
    cout << "Press:\n[0]\tto end the program\n[1]\tto start new game\n[2]\tto continue with the last saved file\n[3]\tto view instructions" << endl;
    cin>>x;
    while (x != 0) {
        switch (x) {
        case 1:
            new_game(x);
            break;

        case 2:
            resume_last(x);cout<<"try a new game? ";
cin>>x;
   
            break;

        case 3:
            instructions(x);
            //involve file I/O: input instructions file in .txt format (print the instructions page)
            break;
        default:
            cout << "\x1B[31minvalid output" << "\x1B[0m" << endl;
            cin >> x;
            break;
        } 
   }
     cout << "##Thank you for playing the game\n\n";content_page(); 
    return 0;
}




