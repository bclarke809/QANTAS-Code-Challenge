//
//  main.cpp
//  Code Challenge
//
//  Created by Brett Clarke on 20/6/18.
//  Copyright © 2018 Brett Clarke. All rights reserved.
//

/*
    Since I do not have a calendar library availble to me, I have built my own calendar
    that can calculate any year from 1970 and onwards.
*/

#include <iostream>
using namespace std;
//Variables
int z = 0;
int x = 0;

int Cal[72][7] = {                  //First Possible year is 1970, and everything is based on this year
    //Jan
    {0,0,0,0,0,1,2},
    {3,4,5,6,7,8,9},
    {10,11,12,13,14,15,16},
    {17,18,19,20,21,22,23},
    {24,25,26,27,28,29,30},
    {31,0,0,0,0,0,0},
    //Feb
    {0,1,2,3,4,5,6},
    {7,8,9,10,11,12,13},
    {14,15,16,17,18,19,20},
    {21,22,23,24,25,26,27},
    {28,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    //Mar
    {0,1,2,3,4,5,6},
    {7,8,9,10,11,12,13},
    {14,15,16,17,18,19,20},
    {21,22,23,24,25,26,27},
    {28,29,30,31,0,0,0},
    {0,0,0,0,0,0,0},
    //Apr
    {0,0,0,0,1,2,3},
    {4,5,6,7,8,9,10},
    {11,12,13,14,15,16,17},
    {18,19,20,21,22,23,24},
    {25,26,27,28,29,30,0},
    {0,0,0,0,0,0,0},
    //May
    {0,0,0,0,0,0,1},
    {2,3,4,5,6,7,8},
    {9,10,11,12,13,14,15},
    {16,17,18,19,20,21,22},
    {23,24,25,26,27,28,29},
    {30,31,0,0,0,0,0},
    //Jun
    {0,0,1,2,3,4,5},
    {6,7,8,9,10,11,12},
    {13,14,15,16,17,18,19},
    {20,21,22,23,24,25,26},
    {27,28,29,30,0,0,0},
    {0,0,0,0,0,0,0},
    //Jul
    {0,0,0,0,1,2,3},
    {4,5,6,7,8,9,10},
    {11,12,13,14,15,16,17},
    {18,19,20,21,22,23,24},
    {25,26,27,28,29,30,31},
    {0,0,0,0,0,0,0},
    //Aug
    {1,2,3,4,5,6,7},
    {8,9,10,11,12,13,14},
    {15,16,17,18,19,20,21},
    {22,23,24,25,26,27,28},
    {29,30,31,0,0,0,0},
    {0,0,0,0,0,0,0},
    //Sep
    {0,0,0,1,2,3,4},
    {5,6,7,8,9,10,11},
    {12,13,14,15,16,17,18},
    {19,20,21,22,23,24,25},
    {26,27,28,29,30,0,0},
    {0,0,0,0,0,0,0},
    //Oct
    {0,0,0,0,0,1,2},
    {3,4,5,6,7,8,9},
    {10,11,12,13,14,15,16},
    {17,18,19,20,21,22,23},
    {24,25,26,27,28,29,30},
    {31,0,0,0,0,0,0},
    //Nov
    {0,1,2,3,4,5,6},
    {7,8,9,10,11,12,13},
    {14,15,16,17,18,19,20},
    {21,22,23,24,25,26,27},
    {28,29,30,0,0,0,0},
    {0,0,0,0,0,0,0},
    //Dec
    {0,0,0,1,2,3,4},
    {5,6,7,8,9,10,11},
    {12,13,14,15,16,17,18},
    {19,20,21,22,23,24,25},
    {26,27,28,29,30,31,0},
    {0,0,0,0,0,0,0},
    
};

int YearOne(){                                      //For 1971
    for(int i = 0; i < 72; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[71][6], Cal[i][j]);
        }
    }
    for(int y = 0; y < 70; y += 6){                         //check if start of month is all 0's, and move row of 0's to bottom
        int a = y+5;
        if(Cal[y][6]==0){
            for(int j = 0; j < 7; j++){
                for(int i = a-1; i >= a-5; i--){
                    std::swap(Cal[a][j], Cal[i][j]);
            }
        }
    }
}
    static int Cal = Cal;
    return(Cal);
}

int YearTwo(){
    YearOne();
    Cal[10][2] = 29;
    for(int i = 12; i < 72; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[71][6], Cal[i][j]);
        }
    }
    for(int y = 0; y < 70; y += 6){                         //check if start of month is all 0's, and move row of 0's to bottom
        int a = y+5;
        if(Cal[y][6]==0){
            for(int j = 0; j < 7; j++){
                for(int i = a-1; i >= a+6; i--){
                    std::swap(Cal[a][j], Cal[i][j]);
                }
            }
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearThree(){
    YearTwo();
    Cal[10][3] = 0;
    for(int i = 0; i < 12; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[11][6], Cal[i][j]);
        }
    }
    for(int y = 0; y < 70; y += 6){                         //check if start of month is all 0's, and move row of 0's to bottom
        int a = y+5;
        if(Cal[y][6]==0){
            for(int j = 0; j < 7; j++){
                for(int i = a-1; i >= a+6; i--){
                    std::swap(Cal[a][j], Cal[i][j]);
            }
        }
    }
}
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearFour(){
    YearThree();                                      //Fourth Year is Created from the Third Year, plus the first
    YearOne();                                        //Must Be in that order
    static int Cal = Cal;
    return(Cal);
}

int YearFive(){
    YearFour();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearSix(){
    YearFive();
    Cal[10][0] = 29;
    for(int i = 12; i < 72; i++){                            //Move all Days after leap day to account for additional day
        for(int j = 0; j < 7; j++){
            std::swap(Cal[71][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearSeven(){
    YearSix();
    Cal[10][1] = 0;
    for(int i = 0; i < 12; i++){                            //Move all days BEFORE previous leap day to account for additional day
        for(int j = 0; j < 7; j++){
            std::swap(Cal[11][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearEight(){
    YearSeven();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearNine(){
    YearEight();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearTen(){
    YearNine();
    Cal[9][5] = 29;
    for(int i = 12; i < 72; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[71][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearEleven(){
    YearTen();
    Cal[9][6] = 0;
    for(int i = 0; i < 12; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[11][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int YearTwelve(){
    YearEleven();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearThirteen(){
    YearTwelve();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearFourteen(){
    YearThirteen();
    Cal[9][3] = 29;
    
    for(int i = 12; i < 72; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[71][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearFifteen(){
    YearFourteen();
    Cal[9][4] = 0;
    for(int i = 0; i < 12; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[11][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearSixteen(){
    YearFifteen();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearSeventeen(){
    YearSixteen();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearEighteen(){
    YearSeventeen();
    Cal[10][1] = 29;
    for(int i = 12; i < 72; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[71][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearNineteen(){
    YearEighteen();
    Cal[10][2] = 0;
    for(int i = 0; i < 12; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[11][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwenty(){
    YearNineteen();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwentyOne(){
    YearTwenty();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwentyTwo(){
    YearTwentyOne();
    Cal[8][6] = 29;
    for(int i = 12; i < 72; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[71][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwentyThree(){
    YearTwentyTwo();
    Cal[9][0] = 0;
    for(int i = 0; i < 12; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[11][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwentyFour(){
    YearTwentyThree();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwentyFive(){
    YearTwentyFour();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwentySix(){
    YearTwentyFive();
    Cal[9][3] = 29;
    for(int i = 12; i < 72; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[71][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwentySeven(){
    YearTwentySix();
    Cal[9][4] = 0;
    for(int i = 0; i < 12; i++){                            //move every day one across for the next year
        for(int j = 0; j < 7; j++){
            std::swap(Cal[11][6], Cal[i][j]);
        }
    }
    YearOne();
    static int Cal = Cal;
    return(Cal);
}
int YearTwentyEight(){
    YearTwentySeven();
    YearOne();
    static int Cal = Cal;
    return(Cal);
}

int main() {
    //Variables
    int Day, Year, Period = 0;
    string Month;
    int NewYear = 0;
    int v = 0;
    
    cout << "Please enter date (MMM DD YYYY)" << endl;                  //Input Statement
    cin >> Month >> Day >> Year;

    if(Year < 1971 || Year >= 2100){                                    //Invalid Test Case
        cout << "INVALID YEAR!, Must be between 1971-2099" << endl;
    }
    else{
    NewYear = Year - 1970;                                              //Convert Year into nuber 1-28, as there are 28 possible
    while(NewYear > 29){                                                //Calendar Combinations
        NewYear -= 28;
    }
    
    if(NewYear == 1){                                                   //Each Year can be grouped into one of the following functions
        YearOne();
    }
    else if(NewYear == 2){
        YearTwo();
    }
    else if(NewYear == 3){
        YearThree();
    }
    else if(NewYear == 4){
        YearFour();
    }
    else if(NewYear == 5){
        YearFive();
    }
    else if(NewYear == 6){
        YearSix();
    }
    else if(NewYear == 7){
        YearSeven();
    }
    else if(NewYear == 8){
        YearEight();
    }
    else if(NewYear == 9){
        YearNine();
    }
    else if(NewYear == 10){
        YearTen();
    }
    else if(NewYear == 11){
        YearEleven();
    }
    else if(NewYear == 12){
        YearTwelve();
    }
    else if(NewYear == 13){
        YearThirteen();
    }
    else if(NewYear == 14){
        YearFourteen();
    }
    else if(NewYear == 15){
        YearFifteen();
    }
    else if(NewYear == 16){
        YearSixteen();
    }
    else if(NewYear == 17){
        YearSeventeen();
    }
    else if(NewYear == 18){
        YearEighteen();
    }
    else if(NewYear == 19){
        YearNineteen();
    }
    else if(NewYear == 20){
        YearTwenty();
    }
    else if(NewYear == 21){
        YearTwentyOne();
    }
    else if(NewYear == 22){
        YearTwentyTwo();
    }
    else if(NewYear == 23){
        YearTwentyThree();
    }
    else if(NewYear == 24){
        YearTwentyFour();
    }
    else if(NewYear == 25){
        YearTwentyFive();
    }
    else if(NewYear == 26){
        YearTwentySix();
    }
    else if(NewYear == 27){
        YearTwentySeven();
    }
    else if(NewYear == 28){
        YearTwentyEight();
    }
if(Month == "Jan"){                                             //Once Calendar has been calculated, Find Month and Day
        if(Day > 0 && Day <= 31){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;                                //Find Billing Period
                    z = i;
                    }
                }
            }
        }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Feb"){
        if((Day > 0 && Day <= 28) || (Year % 4 == 0 && Day > 0 && Day <= 29)){
        for(int i = 6; i < 12; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                    }
                }
            }
        }
    }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Mar"){                                //If the Input is March
        if(Day > 0 && Day <= 31){                       // Make sure Day is within boundaries
        for(int i = 12; i < 18; i++){                   // Check between these parts of the array
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){                   // When you reach the day, add 1 to the i value to give period number
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                    if(Cal[x][0] == 0)
                    {
                        Period = Period - 1;
                    }
                }
            }
        }
    }
}
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Apr"){
        if(Day > 0 && Day <= 30){
        for(int i = 18; i < 24; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                }
            }
        }
    }
}
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "May"){
        if(Day > 0 && Day <= 31){
        for(int i = 24; i < 30; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                    }
                }
            }
        }
    }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Jun"){
        if(Day > 0 && Day <= 30){
        for(int i = 30; i < 36; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                }
            }
        }
    }
}
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Jul"){
        if(Day > 0 && Day <= 31){
        for(int i = 36; i < 42; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                    }
                }
            }
        }
    }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Aug"){
        if(Day > 0 && Day <= 31){
        for(int i = 42; i < 48; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                    }
                }
            }
        }
    }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Sep"){
        if(Day > 0 && Day <= 30){
        for(int i = 48; i < 54; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                    }
                }
            }
        }
    }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Oct"){
        if(Day > 0 && Day <= 31){
        for(int i = 54; i < 60; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                    }
                }
            }
        }
    }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Nov"){
        if(Day > 0 && Day <= 30){
        for(int i = 60; i < 66; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                    }
                }
            }
        }
    }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else if(Month == "Dec"){
        if(Day > 0 && Day <= 31){
        for(int i = 66; i < 72; i++){
            for(int j = 0; j < 7; j++){
                if(Cal[i][j] == Day){
                    Period = i + 1;
                    z = i;
                    for(int x = 5; x < i; x+= 6){          //Make sure no 0 rows were included in the period, otherwise take them out
                        if(Cal[x][0] == 0)
                        {
                            Period = Period - 1;
                        }
                    }
                }
            }
        }
    }
        else{
            cout << "INVALID DATE" << endl;
        }
    }
else{
    cout << "INVALID MONTH" << endl;
}
        while(Cal[z][v] == 0){                              //Ensure Period Actually starts on 1, instead of 0
            v++;
        }
    cout << "Billing Period = " << Year << "-" << Period << ": " << Month << " " << Cal[z][v] << " - " << Month << " " << Cal[z][6] << endl;
}
    return 0;
}


