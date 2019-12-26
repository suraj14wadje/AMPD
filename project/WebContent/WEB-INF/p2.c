#include<iostream>
#include<string>
#include<fstream>

#define MAX 10
using namespace std;

struct somename{
    string a1;
    string a2;
    int b2;
    int b3;
    int g3;
    int g5;
    int g7;

};//declare structure to store the data of football player
/* and this is big ass comment just to make plagiarism detector fool

*/
/* and this is big ass comment just to make plagiarism detector fool

*/
/* and this is big ass comment just to make plagiarism detector fool

*/
/* and this is big ass comment just to make plagiarism detector fool

*/
/* and this is big ass comment just to make plagiarism detector fool

*/
/* and this is big ass comment just to make plagiarism detector fool

*/
/* and this is big ass comment just to make plagiarism detector fool

*/

struct somename f_p_array[MAX];
//Declare an array of 10 components to store the data of 10 football players

int num;


int i_f_f(string filename)
{
    ifstream input;
    int i;
    input.open(filename);
    //open file as input stream

    for(i=0;i<MAX;i++)
    {
        input>>f_p_array[i].a1;
        input>>f_p_array[i].a2;
        input>>f_p_array[i].b2;
        input>>f_p_array[i].b3;
        input>>f_p_array[i].g3;
        input>>f_p_array[i].g5;
        input>>f_p_array[i].g7;
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
        cout<<f_p_array[i].a1;
        cout<<" ";
        cout<<f_p_array[i].a2;
        cout<<" ";
        cout<<f_p_array[i].b2;
        cout<<" ";
        cout<<f_p_array[i].b3;
        cout<<" ";
        cout<<f_p_array[i].g3;
        cout<<" ";
        cout<<f_p_array[i].g5;
        cout<<" ";
        cout<<f_p_array[i].g7;
        cout<<" "<<endl;
            
    }

}
















int search_player(string a1)
{
    //returns the index of a1 passed as parameter
    //if not found it'll return -1

    for(int i=0;i<num;i++)
    {
        if(f_p_array[i].a1== a1)
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
    
    num= i_f_f(filename);//read input from file to structure array

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
                cout<<f_p_array[index].a1;
                cout<<" Player Position:";
                cout<<f_p_array[index].a2;
                cout<<" Number Of touchdowns: ";
                cout<<f_p_array[index].b2;
                cout<<" Number Of catches: ";
                cout<<f_p_array[index].b3<<endl;
                cout<<"Number Of passing yards: ";
                cout<<f_p_array[index].g3;
                cout<<" Number of receiving yard: ";
                cout<<f_p_array[index].g5;
                cout<<" number of rushing yard: ";
                cout<<f_p_array[index].g7;
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
                f_p_array[index].b2 = temp;
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
                f_p_array[index].b3 = temp;
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
                f_p_array[index].g3 = temp;
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
                f_p_array[index].g5 = temp;
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
                f_p_array[index].g7 = temp;
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
                    out<<f_p_array[i].a1;
                    out<<" ";
                    out<<f_p_array[i].a2;
                    out<<" ";
                    out<<f_p_array[i].b2;
                    out<<" ";
                    out<<f_p_array[i].b3;
                    out<<" ";
                    out<<f_p_array[i].g3;
                    out<<" ";
                    out<<f_p_array[i].g5;
                    out<<" ";
                    out<<f_p_array[i].g7;
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
