#include<bits/stdc++.h>
/*#include<conio.h>
#include<ctime>
#include <windows.h>*/
using namespace std;

char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawboard(){
    cout<<" "<<matrix[0][0]<<" | "<<matrix[0][1]<<" | "<<matrix[0][2]<<endl;
    cout<<"-----------\n";
    cout<<" "<<matrix[1][0]<<" | "<<matrix[1][1]<<" | "<<matrix[1][2]<<endl;
    cout<<"-----------\n";
    cout<<" "<<matrix[2][0]<<" | "<<matrix[2][1]<<" | "<<matrix[2][2]<<endl;
    cout<<"-----------\n";
}

bool check_winner(){
    int i;
    for(i=0;i<3;i++){
        if(matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2])
            return true;

        if(matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i])
            return true;
    }
    if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2])
        return true;
    if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0])
     return true;
    return false;
}

int main(){
    int i, row, col, slot, flag=1;
    drawboard();
    for(i=0;i<9 && flag;i++){

          cout<<"Player "<<(i%2)+1<<" , enter your slot number:";

          cin>>slot;
          cout<<"\n";
          //cout<<slot<<endl;
          if(slot<1 || slot>9){
              cout<<"Slot doesn't exist, enter again\n";
              i--;
              continue;
          }
          row=(slot-1)/3;
          col=(slot%3==0)?2:(slot%3)-1;
          if(matrix[row][col]=='X' || matrix[row][col]=='O'){
            cout<<"Slot is captured, enter again\n";
            i--;
            continue;
          }
          matrix[row][col]=(i%2==0)?'X':'O';
          drawboard();
          cout<<"\n";
          if(check_winner()){
            cout<<"Player "<<(i%2)+1<<" won the game\n";
            flag=0;
            break;
          }
          //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
    if(flag)
        cout<<"Tie\n";
return 0;
}
