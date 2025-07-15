#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

// X:user
// O:computer 

#define X 'X'
#define O 'O'
//Function
void front();
void boards(char board[3][3]);
int win(char board[3][3],char player);
int draw(char board[3][3]);
void playgame();
void player_move(char board[3][3]);
void computer_move(char board[3][3]);

// Structure
typedef struct
{
    int player;
    int computer;
    int draw;
    
}Score;
// variables
Score s = {0,0,0};
    
int a;




int main(){
    front();
    srand(time(NULL));
    int choice;
    do{
        
        playgame();
        printf("\nWant to play again the press 1 : ");
        scanf("%d",&choice);
    }while (choice==1);

    printf("\nThank's for playing\n");
    printf("by Shubham Singh");
    
}

void playgame(){
    char board[3][3]=
    {
        { ' ', ' ', ' '},
        { ' ', ' ', ' '},
        { ' ', ' ', ' '}
    };
    
    char current_player = rand() % 2 == 0 ? X : O;
    boards(board);
    while (1){

        if (current_player==X)
        {
            player_move(board);
            boards(board);
            if(win(board,X)){
                s.player++;
                boards(board);
                printf("\nCongratulation you won");
                break;
            }
            current_player = O;
        }else{

            computer_move(board);
            boards(board);
            if (win(board,O))
            {
                s.computer++;
                boards(board);
                printf("\nBetter Luck Next time");
                break;
            }
            current_player=X;
        } 
        if(draw(board)){
            s.draw++;
            boards(board);
            printf("\nMatch Draw try again");
            break;
        }
    }  
}

void player_move(char board[3][3]){
    int count=0,x,y;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]==' ')
            {
                count++;
                x=i;
                y=j;
            }
            
        }
        
    }
    if (count==1)
    {
        board[x][y]=X; 
        return; 
    }
    
    
    int row,col;
    do {
    printf("It is your move \n");
    printf("Enter the your move (1-3) : ");
    scanf("%d",&row);
    scanf("%d",&col);
    row--;
    col--;
    }while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
    board[row][col]=X;


}
void computer_move(char board[3][3]){  
    // 1.Immidiate win
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++){
            if (board[i][j]==' ')
            {
                board[i][j]=O;
            
            if (win(board,O))       
            {
                return;
            }else{
                board[i][j]=' ';
            }
            }
            
        }
    }
    // 2.Immidiate block
    for (int i = 0; i < 3; i++)
    {
        for(int j=0;j<3;j++){
            if (board[i][j]==' '){
            board[i][j]=X;
            
            if (win(board,X))       
            {
                board[i][j]=O;
                return;
            }else{
                board[i][j]=' ';
            }
            }   
        }
    }
    if(a==2){

        //3.Centre Play
        if(board[1][1]==' '){
            board[1][1]=O;
            return;
        }

        // 4.corner play
        if(board[0][0]==' '){
            board[0][0]=O;
            return;
        }
        else if(board[0][2]==' '){
            board[0][2]=O;
            return;
        }
        else if(board[2][0]==' '){
            board[2][0]=O;
            return;
        }
        else if(board[2][2]==' '){
            board[2][2]=O;
            return;
        }

    }

        // 5.any where
        for (int i = 0; i < 3; i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j]=O;
                return;
            }
            
        }
        }
        
        

    
    

}
int draw(char board[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            if(board[i][j]==' '){
            return 0;
            }
        }
        
    }
    return 1;
    
}
int win(char board[3][3],char player){
    for(int i=0;i<3;i++){
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player){
            return 1;
        }
    }
    for(int i=0;i<3;i++){
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player){
            return 1;
        }
    }
    if((board[0][0]==player && board[1][1]==player &&board[2][2]==player) || (board[0][2]==player && board[1][1]==player &&board[2][0]==player)){
        return 1;
    }
    return 0;
}
void front(){
    while (1){
        system("cls");
    
    printf("WELCOME TO TIC-TAC-TOE GAME\n");
    printf("1.Easy Level \n");
    printf("2.Hard Level(Impossible to win)\n");
    printf("Select the Choice (1/2) : ");
    scanf("%d",&a);
    getchar();
    if (a!=1&&a!=2){
        printf("Incorrect choice \n");
    }
    else{
        break;
    }
    }

}
void boards(char board[3][3]){
    system("cls");
    
    printf("Score Board-> Player : %d  Computer : %d  Draw : %d\n",s.player,s.computer,s.draw);
    printf("TIC-TAC-TOE\n");

    for(int i=0;i<3;i++){
        printf("\n");
        for(int j=0;j<3;j++){
            printf("%c",board[i][j]);
            if(j<2){
                printf(" |");
            }
        }
        if(i<2){
        printf("\n--+--+--");
        }
    }  

    printf("\n\n");
}