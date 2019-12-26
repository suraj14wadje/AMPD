#include<iostream>
#include<string>
#include<fstream>

#define MAX_PLAYER 10
using namespace std;

struct football_player{
    string player_name;
    string player_position;
    int number_touchdown;
    int number_catches;
    int number_passing_yards;
    int number_receiving_yard;
    int number_rushing_yard;

};//declare structure to store the data of football player

struct football_player f_p_array[MAX_PLAYER];
//Declare an array of 10 components to store the data of 10 football players

int num;


int i_f_f(string filename)
{
    ifstream input;
    int i;
    input.open(filename);
    //open file as input stream

    for(i=0;i<MAX_PLAYER;i++)
    {
        //copy data from file stream to array elements of football player
        input>>f_p_array[i].player_name;
        input>>f_p_array[i].player_position;
        input>>f_p_array[i].number_touchdown;
        input>>f_p_array[i].number_catches;
        input>>f_p_array[i].number_passing_yards;
        input>>f_p_array[i].number_receiving_yard;
        input>>f_p_array[i].number_rushing_yard;
        if(!input)
            break;

    }
    input.close();//close the opened file
    return i;
    //returns number of players read from file

}

void print_entire_data()
{

    for(int i=0;i<num;i++)
    {
        cout<<f_p_array[i].player_name;
        cout<<" ";
        cout<<f_p_array[i].player_position;
        cout<<" ";
        cout<<f_p_array[i].number_touchdown;
        cout<<" ";
        cout<<f_p_array[i].number_catches;
        cout<<" ";
        cout<<f_p_array[i].number_passing_yards;
        cout<<" ";
        cout<<f_p_array[i].number_receiving_yard;
        cout<<" ";
        cout<<f_p_array[i].number_rushing_yard;
        cout<<" "<<endl;
            
    }

}

int search_player(string player_name)
{
    //returns the index of player_name passed as parameter
    //if not found it'll return -1

    for(int i=0;i<num;i++)
    {
        if(f_p_array[i].player_name== player_name)
        {
            return i;
        }
    }

    return -1;
}


int main()
{
    int ch = 0,index,temp;
    string name;
    char yes_no;
    string filename = "Data.txt";//set file name
    
    num= input_from_i_f_f//read input from file to structure array

    while(ch != 99)
    {
        cout<<"1: To print a player's data"<<endl;
        cout<<"2: To print the entire data"<<endl;
        cout<<"3: To update a player's touch downs"<<endl;
        cout<<"4: To update a player's number of catches"<<endl;
        cout<<"5: To update a player's passing yards"<<endl;
        cout<<"6: To update a player's receiving yards"<<endl;
        cout<<"7: To update a player's rushing yards"<<endl;
        cout<<"99: To quit the program"<<endl;
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter player's name: ";
            cin>>name;
            index = search_player(name);
            if(index == -1)
            {
                cout<<"player not found"<<endl;
            }

            else
            {
                cout<<"Player Name:";
                cout<<f_p_array[index].player_name;
                cout<<" Player Position:";
                cout<<f_p_array[index].player_position;
                cout<<" Number Of touchdowns: ";
                cout<<f_p_array[index].number_touchdown;
                cout<<" Number Of catches: ";
                cout<<f_p_array[index].number_catches<<endl;
                cout<<"Number Of passing yards: ";
                cout<<f_p_array[index].number_passing_yards;
                cout<<" Number of receiving yard: ";
                cout<<f_p_array[index].number_receiving_yard;
                cout<<" number of rushing yard: ";
                cout<<f_p_array[index].number_rushing_yard;
                cout<<" "<<endl;
                
            }
            

            break;
        case 2:
            print_entire_data();
            break;
        case 3:
            cout<<"Enter player's name: ";
            cin>>name;
            index = search_player(name);
            if(index == -1)
            {
                cout<<"player not found"<<endl;
            }

            else
            {
                cout<<"New Number Of touch Downs : ";
                cin>>temp;
                f_p_array[index].number_touchdown = temp;
            }

            break;

        case 4:

            cout<<"Enter player's name: ";
            cin>>name;
            index = search_player(name);
            if(index == -1)
            {
                cout<<"player not found"<<endl;
            }

            else
            {
                cout<<"New Number Of Catches : ";
                cin>>temp;
                f_p_array[index].number_catches = temp;
            }

            break;

        case 5:
            cout<<"Enter player's name: ";
            cin>>name;
            index = search_player(name);
            if(index == -1)
            {
                cout<<"player not found"<<endl;
            }

            else
            {
                cout<<"New Number Of passing yards : ";
                cin>>temp;
                f_p_array[index].number_passing_yards = temp;
            }

            break;
        case 6:
            cout<<"Enter player's name: ";
            cin>>name;
            index = search_player(name);
            if(index == -1)
            {
                cout<<"player not found"<<endl;
            }

            else
            {
                cout<<"New Number Of receiving yards : ";
                cin>>temp;
                f_p_array[index].number_receiving_yard = temp;
            }

            break;

        case 7:
            cout<<"Enter player's name: ";
            cin>>name;
            index = search_player(name);
            if(index == -1)
            {
                cout<<"player not found"<<endl;
            }

            else
            {
                cout<<"New Number Of rushing yards : ";
                cin>>temp;
                f_p_array[index].number_rushing_yard = temp;
            }

            break;

        case 99:
            cout<<"Would you like to save data: (y,Y/n,N) ";
            cin>>yes_no;
            yes_no = tolower(yes_no);
            if(yes_no =='y')
            {
                ofstream out;
                out.open(filename);//open file as output stream
                for(int i=0;i<num;i++)
                {
                    //Store the data to file
                    out<<f_p_array[i].player_name;
                    out<<" ";
                    out<<f_p_array[i].player_position;
                    out<<" ";
                    out<<f_p_array[i].number_touchdown;
                    out<<" ";
                    out<<f_p_array[i].number_catches;
                    out<<" ";
                    out<<f_p_array[i].number_passing_yards;
                    out<<" ";
                    out<<f_p_array[i].number_receiving_yard;
                    out<<" ";
                    out<<f_p_array[i].number_rushing_yard;
                    out<<" "<<endl;
                }
                out.close();
                //close file

                cout<<filename <<" updated succesfully!!"<<endl;
            }
            cout<<"Exiting programm"<<endl;
            break;
            



        default:
            break;
        }
    }
    return 0;
}
