//Leila Lin
//9-19-2018
//This lab uses vectors and arrays to calculate the total score of bowling.
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    vector<string> player_name;
    string pn;
    vector<int> total_score;
    vector<int> total_frame;
    int frame_total;
    int roll[21];
    int roll_num = 1;
    int frame = 1;
    int score;
    int sum = 0;

    int j = 0;
    int minscore; //http://www.cplusplus.com/forum/beginner/84756/ check c++ built-in INT_MIN, INT_MAX
    int maxscore; //http://www.cplusplus.com/forum/beginner/84756/ check c++ built-in INT_MIN, INT_MAX
    int min = 0;  //better to name it as index_min or min_index
    int max = 0;  //better to name it as index_max or max_index
    unsigned int i = 0;

//begin
    while(true){
        cout << "Enter player's name (done for no more players): ";
        cin >> pn;
        if(pn == "done"){

            // you need to check whether vector players is empty, before print the line below
            cout << "No players were entered. \n";
            // Please check this link https://stackoverflow.com/questions/18422651/return-vs-break-when-closing-a-function
            //return 0;// return means terminate the program;
            break; // the following code after while loop will still run
        }

        player_name.push_back(pn);

    }

    //player_name.push_back(pn);// this should be inside the while loop


    //so does the for loop, it should be inside while loop
    // if you set up the size of array as 21, means you are using the first space of the array, then here is the change
    for(int i = 1; i < 21; i++){
        cout << "Enter score for frame " << frame << ", roll " << roll_num << ": ";
        cin >> score;

        roll[i] = score;

        if(score == 10){
            if(frame < 10){
                if(i % 2 == 1){
                    i++;
                }

                frame++;

                roll_num = 1;

            }
            else{
                roll_num = 2;
            }
        }
        else{
            if(i % 2 == 1){
                roll_num = 2;
            }
            else{
                frame++;
                roll_num = 1;
            }
        }
    }

    if((roll[19] + roll[20]) >= 10){
        frame = 10;
        roll_num = 3;
        cout << "Enter score for frame " << frame << ", roll " << roll_num << ": ";
        cin >> score;
        roll[21] = score;
    }

    //This is for calculation of scores
    for(int i = 1; i < 19; i +=2){
        int frame_total = 0; // this has been declared earlier

        if(roll[i] == 10){
            frame_total += 10;

            if(roll[i + 2] == 10){
                frame_total += 10;

                if(i < 17){
                    frame_total += roll[i + 2 + 2];
                }
                else{
                    frame_total += roll[20];
                }
            }
            else{
                frame_total += roll[i + 2] + roll[i + 3];
            }
        }
        else if(roll[i] + roll[i + 1] == 10){
            frame_total += 10;
            frame_total += roll[i + 2];
        }
        else{
            frame_total = roll[i] + roll[i + 1];
        }

        total_frame.push_back(frame_total);
    }

    if(roll[19] == 10){
        total_frame.push_back(10 + roll[20] + roll[21]);
    }
    else if((roll[19] + roll[20]) == 10){
        total_frame.push_back(10 + roll[21]);
    }
    else{
        total_frame.push_back(roll[19] + roll[20]);
    }

    for(int i: total_frame){

        sum += i;
    }

    total_score.push_back(sum);

    //There is no need to handle the case here, since we will handle it in the while loop
    if(player_name.empty() || total_score.empty()){
        return 0;
    }
    //--------

    for(string pn: player_name){
        cout << pn << " scored " << total_score.at(j) << ". \n";
        j++;
    }

    for(int score: total_score){
        if(score < minscore){
            minscore = score;
            min = i;
        }

        if(score > maxscore){
            maxscore = score;
            max = i;
        }

        i++;
    }

    cout << player_name.at(min) << " did the worst by scoring " << min << ". \n";
    cout << player_name.at(max) << " won the game by scoring " << max << ". \n";

//end

    return 0;
}
