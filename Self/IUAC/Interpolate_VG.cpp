#include <bits/stdc++.h>
using namespace std;

int main()
{  
    unsigned int input ;
    int Index ;
    int break1 ;
    int togglecounter=1;
    break1 = 0;
    Index = -1;
     
    while (break1 != 1) {
        //__wfi();
        cin >> Index  ;
        if (Index > -1) {

            input = Index + 1;
            printf("\n input pressed is %u\n",input);
            switch (input){
                
                case 10:
                    while(1){
                        if(input == 10){
                            togglecounter++;
                            //printf("CH%1d press  ENTER",togglecounter); 
                            //sprintf(display,"CH1 press  ENTER");   
                            //writestringspi_line2(display);  
                            cout << "channel " << togglecounter << endl ; 
                            if (togglecounter==8) togglecounter=1;
                        }
                        else break ;
                        
                        //_wfi(); waiting for interrupt or
                        cin >> Index ;
                    }
                    
                case 12:
                    
                    printf("channel stored on ENTER pressed\n");
                    printf("calling sensor select fn ..\n");
                    //channelselected=ch;
                    
                    //selectSensor();
                     //selectSensor();
                     break1 =1;
                    break;  
                default:
                    printf("you pressed  to ABORT ESCAPE.No CH selected. no ENTER\n");
                    //printf("channel %d and sensor %d type stored on ENTER pressed\n",channelselected,sensorselected);
                    break1 =1;
                    break;
                    
                }
            
            Index = -1;
        }
    }
    return 0;


}