#include <iostream>
#include <cctype>

using namespace std;

void display(char slots[9]){
    cout<<slots[0]<<"|"<<slots[1]<<"|"<<slots[2]<<"\n------\n"
    <<slots[3]<<"|"<<slots[4]<<"|"<<slots[5]<<"\n------\n"
    <<slots[6]<<"|"<<slots[7]<<"|"<<slots[8]<<endl;
}

bool result(char slots[9]){
    if ((slots[0]==slots[4]) && (slots[4]==slots[8]) || (slots[2]==slots[4]) && (slots[4]==slots[6]))
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
    {
        if ((slots[0+i]==slots[3+i]) && (slots[3+i]==slots[6+i])){
            return false;
        } else if ((slots[0+i*3]==slots[1+i*3]) && (slots[1+i*3]==slots[2+i*3]))
        {
            return false;
        }
    }
    
    return true;
}

char changeTurn(char turn){
    if (turn == 'x'){
        return 'o';
    } else {
        return 'x';
    }
}

void start(){
    int numberOfturns = 0;
    int option;
    bool playing = true;
    char slots[9] = {'1','2','3','4','5','6','7','8','9'};
    char turn = 'o';
    bool possibleAnswer = false;
    while (playing == true){
        numberOfturns++; 
        display(slots);
        turn = changeTurn(turn);
        while (possibleAnswer == false)
        {
            cout<<turn<<" choose a slot to place the "<<turn<<endl;
            cin>>option;
            if (slots[option-1] != 'x' && slots[option-1] != 'o' && option >= 1 && option < 10)
            {
                possibleAnswer = true;
            } else{
                cout<<"invalid option!!"<<endl;
            }
        }
        possibleAnswer = false;
        slots[option-1] = turn;
        playing = result(slots);
        if (numberOfturns == 9)
        {
            playing = false;
        }    
    }

    display(slots);

    if (numberOfturns == 9){
        cout<<"it's a draw!"<<endl;
    } else {
        if (turn == 'x')
        {
            cout<<"x won!"<<endl;
        } else{
            cout<<"o won!"<<endl;
        }
    }
}

int main(){
    start();
    bool stopPlaying = false;
    char answer;

    while (stopPlaying == false)
    {
        cout<<"do you want to play again? y/n"<<endl;
        cin>>answer;
        answer = tolower(answer);
        if (answer == 'y'){
        start();
        } else if (answer == 'n')
        {
            stopPlaying = true;
        } else{
            cout<<"invalid option"<<endl;
        }
    }
}