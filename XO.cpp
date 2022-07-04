#include <iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
bool tie=false;
char t='x';
void draw(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<" "<<board[i][j]<<" "<<"|";
        }
        cout<<endl;
    }
    cout<<"------------\n";
}
void game(){
    int num;
    if(t=='x'){
        cout<<"Please enter ";
        cin>>num;
    }
    if(t=='o'){
        cout<<"Please enter ";
        cin>>num;
    }
    if(num==1){
        column=0;
        row=0;
    }
     if(num==2){
        column=1;
        row=0;
    }
     if(num==3){
        column=2;
        row=0;
    }
     if(num==4){
        column=0;
        row=1;
    }
     if(num==5){
        column=1;
        row=1;
    }
     if(num==6){
        column=2;
        row=1;
    }
     if(num==7){
        column=0;
        row=2;
    }
     if(num==8){
        column=1;
        row=2;
    }
     if(num==9){
        column=2;
        row=2;
    }
    else if(num<1||num>9){
        cout<<"invalid!!!\n";
    }
    if(t=='x'&&board[row][column]!='x'&&board[row][column]!='o'){
       board[row][column]='x'; 
       t='o';
    }
    else if(t=='o'&&board[row][column]!='o'&&board[row][column]!='x'){
       board[row][column]='o'; 
       t='x';
    }
    else {
        cout<<"No empty space!\n";
        game();
    }
  
}
bool fun(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]||board[0][i]==board[1][i]&&board[0][i]==board[2][i]){
            return true;
        }
        if(board[0][0]==board[0][1]&&board[1][1]==board[2][2]||board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
            return true;
        }
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='x'&&board[i][j]!='o')
            return false;
        }
     }
    tie=true;
    return false;
    
}

int main()
{ int cx=0;
 int co=0;
    while(!fun()){
        draw();
        game();
        fun();
        if(t=='x'&&tie==false){
            cx++;
        }
        else if(t=='o'&&tie==false){
           co++;
        }
        else
        cout<<"no \n";
       
    }
    draw();
     if(cx>co){
            cout<<"O wins!!\n";
        }
        else if(cx<co){
            cout<<"X wins!!\n";
        }
        
    return 0;
}

