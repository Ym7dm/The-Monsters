#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

/*void Ya7ya_MO7amed()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}*/

void Monster(int &player_health,int&shields,int&monsters_health,int &player_dmg_value,int &monsters_dmg_value
    ,int &monsters_dmg_reset,int &player_health_plus);
void Random_Value(int &player_health,int&shields,int&monsters_health,int &player_health_value
    ,int &monsters_health_value,int &player_dmg_value,int &monsters_dmg_value,int &monsters_dmg_reset,int &player_health_plus);
void Game();

//main Function
int main() {

    char play,check;
    cout<<"<{ ---The Monsters--- }>"<<endl<<endl;

    do{
        cout<<"[Choose Your Options] "<<endl<<
             "- Play <Press p>"<<endl<<
             "- Exit <Press e>"<<endl;
        cin>>check;
        play=tolower(check);
    }while(play!='p'&&play!='e');

    if(play=='e')
        return 0;

    cout<<"{ -Instructions- }"<<endl;
    cout<<"You should pass from your place in the 2D map to the last point to any point"<<endl<<" in the last column."<<endl;
    cout<<"You are $ symbol and the points is *"<<endl;
    cout<<"You have a health and sheilds and you should jumps point by point to reach "<<endl<<"the last point."<<endl;
    cout<<"You will choose where to move you only can move to the right or up right or "<<endl<<"down right."<<endl;
    cout<<"You will find at every point you jump to it a extra health or extra shields "<<endl<<"or a monster that you will"
          " fight him."<<endl;
    cout<<"Monster's base attack DMG is 10 and yours with the sword is 15 and both increase"<<endl<<" by 5+ each combat."<<endl;
    cout<<"Monster's attack increases by 5+ up to 35 DMG during the fight. Use shield to "<<endl<<"reset the monster's attack to 10."<<endl;
    cout<<"If you understood, enjoy playing!"<<endl;
    cout<<""<<endl;


    if(play=='p') {

        char start;
        do{
            cout<<"Press s to Start the game"<<endl;
            cin>>check;
            cout<<endl;
            start=tolower(check);
        }while(start!='s');

        if(start=='s') {
            Game();
        }

    }

    return 0;
}

//Monster Function
void Monster(int &player_health,int&shields,int&monsters_health,int &player_dmg_value,int &monsters_dmg_value
    ,int &monsters_dmg_reset,int &player_health_plus) {

    int player_dmg=player_dmg_value,monster_dmg=monsters_dmg_value;
    char c,continu,fight,check;

    cout<<"Your Health <<"<<player_health<<">>"<<endl;
    cout<<"Your Sheilds <<"<<shields<<">>"<<endl;
    cout<<"Monster's Health <<"<<monsters_health<<">>"<<endl;
    do{
        cout<<"Press f to fight"<<endl;
        cin>>check;
        cout<<endl;
        fight=tolower(check);
    }
    while(fight!='f');

    if(fight=='f') {

        do{
            cout<<"It's your turn\n"
                   <<"Choose how to fight (sword or shield)\n";

            do{
                cout<<"Press 'w' for sword or 'h' for shield \n";
                cin>>check;
                c=tolower(check);// in case he entered capital letter
            }while(c!='w'&&c!='h');

            if(shields==0&&c=='h') {
                do{
                    cout<<"You have no more shields Press 'w' for sword \n";
                    cin>>check;
                    c=tolower(check);// in case he entered capital letter
                }while(c!='w');
            }

            //Sword or Sheild
            if(c=='w'){

                monsters_health-=player_dmg;
                cout<<"Hit!"<<endl;
                cout<<"You did "<<player_dmg<<" DMG"<<endl<<endl;
                player_dmg+=player_health_plus;
                do
                {
                    cout<<"Press c to continue"<<endl;
                    cin>>check;
                    cout<<endl;
                    continu=tolower(check);
                }
                while(continu!='c');

                if(monsters_health<=0) {
                    cout<<"Great you have won the fight "<<endl;
                    cout<<"Your Health <<"<<player_health<<">>"<<endl;
                    cout<<"Your Sheilds <<"<<shields<<">>"<<endl;
                    cout<<"Monster's Health <<"<<0<<">>"<<endl<<endl;
                    break;
                }

                cout<<"It's monstar's turn"<<endl;
                player_health-=monster_dmg;
                cout<<"Monster Did "<<monster_dmg<<" DMG "<<endl<<endl;
                monster_dmg+=5;
                if(monster_dmg==45)monster_dmg=monsters_dmg_reset;

            }
            else if(c=='h'){
                if(shields>0) {
                    cout<<"You are protected! And the Monster's Attack decreases"<<endl<<endl;
                    shields--;
                    monster_dmg=monsters_dmg_reset;

                    do
                    {
                        cout<<"Press c to continue"<<endl;
                        cin>>check;
                        cout<<endl;
                        continu=tolower(check);
                    }
                    while(continu!='c');

                    if(monsters_health<=0) {
                        cout<<"Great you have won the fight "<<endl;
                        cout<<"Your Health <<"<<player_health<<">>"<<endl;
                        cout<<"Your Sheilds <<"<<shields<<">>"<<endl;
                        cout<<"Monster's Health <<"<<0<<">>"<<endl<<endl;
                        break;
                    }

                    cout<<"It's monstar's turn"<<endl;
                    player_health-=monster_dmg;
                    cout<<"Monster Did "<<monster_dmg<<" DMG "<<endl<<endl;
                    monster_dmg+=5;
                    if(monster_dmg==45)monster_dmg=monsters_dmg_reset;

                }
                else {
                    cout<<"Their no more shields!"<<endl;
                }
            }
            if(player_health<=0) {
                player_health=0;
                cout<<"You Lose the fight"<<endl;
                cout<<"Your Health <<"<<0<<">>"<<endl;
                cout<<"Your Sheilds <<"<<shields<<">>"<<endl;
                cout<<"Monster's Health <<"<<monsters_health<<">>"<<endl<<endl;
                break;
            }
            cout<<"<<<<<< After the combat >>>>>> "<<endl;
            cout<<"Your Health <<"<<player_health<<">>"<<endl;
            cout<<"Your Sheilds <<"<<shields<<">>"<<endl;
            cout<<"Monster's Health <<"<<monsters_health<<">>"<<endl<<endl;

            do
            {
                cout<<"Press c to continue"<<endl;
                cin>>check;
                cout<<endl;
                continu=tolower(check);
            }
            while(continu!='c');

        }while(player_health>0 && monsters_health>0);
    }

}

//Random_value Function
void Random_Value(int &player_health,int&shields,int&monsters_health,int &player_health_value
    ,int &monsters_health_value,int &player_dmg_value,int &monsters_dmg_value,int &monsters_dmg_reset,int &player_health_plus) {
    int x,y;
    bool flag=1;
    x=time(0)*100;
    srand(x);
    y=(rand()%100)+1;

    char continu,check;

    if (y>=1&&y<=25){
        //Monster
        cout<<"Uh-Oh, you find a monster. You should fight him!"<<endl;
        monsters_health=monsters_health_value;
        Monster(player_health,shields,monsters_health,player_dmg_value,monsters_dmg_value,monsters_dmg_reset,player_health_plus);
    }
    else if (y>=26&&y<=65){
        //Player Health Increasment
        cout<<"WOW, you find  20 extra heath in this point"<<endl;
        player_health+=20;
        cout<<"Your Health <<"<<player_health<<">>"<<endl<<endl;
    }
    else if (y>=66&&y<=90){
        //Player Sheilds Increasment
        cout<<"WOW, you find 1 sheild in this point"<<endl;
        shields++;
        cout<<"Your Sheilds <<"<<shields<<">>"<<endl<<endl;
    }
    else if (y>=91&&y<=100){
        //Nothing Will Happen
        cout<<"Their Nothing Here!"<<endl<<endl;
    }

    do
    {
        cout<<"Press c to continue"<<endl;
        cin>>check;
        cout<<endl;
        continu=tolower(check);
    }
    while(continu!='c');

}


//Game Function
void Game() {
    int player_health_value=250,monsters_health_value=50,shields_value=2,x_value=3,size_value=7
    ,player_dmg_value=10,monsters_dmg_value=20,monsters_dmg_reset=15,player_health_plus=5;
    char play,check,continu;

    int i=1;

    while(i<=3) {
        if(i==2) {
            player_health_value=450,monsters_health_value=70,shields_value=4,x_value=5,size_value=11,
            player_dmg_value=15,monsters_dmg_value=25,monsters_dmg_reset=20,player_health_plus=10;
        }
        else if(i==3) {
            player_health_value=600,monsters_health_value=100,shields_value=6,x_value=6,size_value=13,
            player_dmg_value=20,monsters_dmg_value=30,monsters_dmg_reset=25,player_health_plus=15;
        }

        int player_health=player_health_value,monsters_health=monsters_health_value,shields=shields_value;
        string size[size_value][size_value];

        for (int i = 0; i < size_value; ++i)
        {
            for (int j = 0; j < size_value; ++j)
                size[i][j] = "*";
        }
        size[x_value][0] = "$";

        cout<<"LEVEL "<<i<<endl;
        cout<<"Your Health <<"<<player_health<<">>"<<endl;
        cout<<"Your Sheilds <<"<<shields<<">>"<<endl<<endl;

        int x = x_value, y = 0;

        do
        {
            cout<<"Press c to continue"<<endl;
            cin>>check;
            cout<<endl;
            continu=tolower(check);
        }
        while(continu!='c');

        while(player_health>0&&y!=size_value-1) {

            //cout The Grid
            for (int i = 0; i < size_value; ++i)
            {
                for (int j = 0; j < size_value; ++j)
                    cout << size[i][j] << " ";
                cout << "\n";
            }

            //player movement
            string move;
            do
            {
                cout<<endl<<"If you want to move right press r or up  right press ur or down "
                      "right press dr"<<endl;

                cin>>move;
                cout<<endl;
            }
            while(move!="r"&&move!="ur"&&move!="dr");

            if (move == "r") // هيتحرك يميناً
            {
                swap(size[x][y], size[x][y + 1]);
                y++;
            }
            else if (move == "ur") // هيتحرك شمال شرقي
            {
                swap(size[x][y], size[x - 1][y + 1]);
                x--;
                y++;
            }
            else if (move == "dr") // هيتحرك جنوب شرقي
            {
                swap(size[x][y], size[x + 1][y + 1]);
                y++;
                x++;
            }

            //cout The Grid
            for (int i = 0; i < size_value; ++i)
            {
                for (int j = 0; j < size_value; ++j)
                    cout << size[i][j] << " ";
                cout << endl;
            }cout<<endl;

            if((y+1)%3==0) {
                cout<<"Uh-Oh, you find a monster. You should fight him!"<<endl;
                monsters_health=monsters_health_value;
                Monster(player_health,shields,monsters_health,player_dmg_value,monsters_dmg_value,monsters_dmg_reset,player_health_plus);
            }
            else if(y==size_value-1) {
                continue;
            }
            else
                Random_Value(player_health,shields,monsters_health,player_health_value,
                    monsters_health_value,player_dmg_value,monsters_dmg_value,monsters_dmg_reset,player_health_plus);
        }
        if(i==3) {
            cout<<"Congratulations, You win the game"<<endl<<endl;

            do{
                cout<<"[Choose Your Options] "<<endl<<
                     "- Restart from Level 1 <Press r>"<<endl<<
                     "- Exit <Press e>"<<endl;
                cin>>check;
                play=tolower(check);
            }while(play!='r'&&play!='e');

            if(play=='r')
                i=1;
            else
                i=4;
        }
        if(player_health==0) {
            cout<<"You Lose the game"<<endl<<endl;

            do{
                cout<<"[Choose Your Options] "<<endl<<
                     "- Restart from Level 1 <Press r>"<<endl<<
                     "- Exit <Press e>"<<endl;
                cin>>check;
                play=tolower(check);
            }while(play!='r'&&play!='e');

            if(play=='r')
                i=1;
            else
                i=4;
        }
        if(y==size_value-1) {
            cout<<"You Win Level "<<i<<endl<<endl;

            do{
                cout<<"[Choose Your Options] "<<endl<<
                     "- Next Level <Press n>"<<endl<<
                     "- Exit <Press e>"<<endl;
                cin>>check;
                play=tolower(check);
            }while(play!='n'&&play!='e');

            if(play=='n')
                i++;
            else
                i=4;
        }
    }

}

