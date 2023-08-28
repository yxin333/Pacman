#include<iostream>
using namespace std;

#define PLACE_A_LIMIT 10
#define PLACE_B_LIMIT 20
#define PLACE_C_LIMIT 40
#define PLACE_D_LIMIT 60
#define PLACE_E_LIMIT 80
#define PLACE_F_LIMIT 100

int main()
{
    int time[100];

    for(int i =1; i<100; i++)
    {
        cout<< "Your time taken to reach victory in this game is "<<duration<<endl;
        cout<<"You rank No. "<<place<<"in this game!!"<<endl;
    }
    
    char place;
    for (int i =1; i<100; i++)
    {
        if (time[i]<= PLACE_A_LIMIT)
            place= '1';
        else (time[i]<= PLACE_B_LIMIT)
            place= '2';
        else (time[i]<= PLACE_C_LIMIT)
            place= '3';
        else (time[i]<= PLACE_D_LIMIT)
            place= '4';
        else (time[i]<= PLACE_E_LIMIT)
            place= '5';
        else
            place= '6';

        cout<<time[i]<<"\t"<<place<<endl;
    }
    return 0;
}