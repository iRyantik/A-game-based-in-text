#ifndef HELLO_H
#define HELLO_H
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

struct round
{
    int event;
    int choice=0;
    int companion = 0;
    int armour = 0;
    int holy = 0;
    int life = 2;
    int recognition = 0;
    int function = 0;
};

void save(vector <round> status);
int castle(vector<round> &status);
int grad(vector<round> &status) ;
int apprentice(vector<round>  &status) ;
int dept_war(vector<round> &status) ;
int shop(vector<round> &status);
    
int math(vector<round>& status) ;
int not_math(vector<round>& status);


int school(vector<round>& status) ;
int lake_god_1_2(vector<round>& status) ;
int say_sorry_1_1_1(vector<round>& status) ;
int apologize_1_1_2(vector<round> status) ;
int Approach_her_1_1(vector<round>& status) ;
int hide(vector<round>& status);

int lake_1(vector<round>& status);



int hello(vector<round>& status);

#endif
