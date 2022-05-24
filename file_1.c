#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(){
    srand(time(NULL));
    char guessWords[][16]={
        "green",
        "yellow",
        "purple",
        "windows",
        "linux",
        "apple"
    };
    int randomIndex=rand()%6;
   
   int numlives=5;
   int numCorrect=0;
   int oldCorrect=0;
  

   int lengthofWord=strlen(guessWords[randomIndex]);

   //           0 1 2 3 4 5
   //           p u r p l e
   int letterGuessed[8]={0,0,0,0,0,0,0,0};

   int quit=0;

   int loopIndex=0;

   char guess[16];
   char letterEntered;

   printf("guessWords=%s randomIndex:%d lengthofWord:%d\n",guessWords[randomIndex],randomIndex,lengthofWord);

   while(numCorrect<lengthofWord)
   {
        printf("\nNew Turn...\nHangman Word :");

        for (loopIndex=0;loopIndex<lengthofWord;loopIndex++)
       {
           if(letterGuessed[loopIndex]==1)
           {
              printf("%c",guessWords[randomIndex][loopIndex]);
           }
           else
           {
               printf("-");
           }
          
       }
       printf("\n");

       printf("Number Correct so far : %d\n",numCorrect);
       printf("Enter a guess letter : ");
       fgets(guess,16,stdin);

       if(strncmp(guess,"quit",4)==0){
           quit=1;
           break;
       }
       letterEntered=guess[0];
       printf("LetterEntered : %c\n",letterEntered);
       oldCorrect=numCorrect;

       for (loopIndex=0;loopIndex<lengthofWord;loopIndex++)
       {
           if(letterGuessed[loopIndex]==1)
           {
               continue;
           }
           if(letterEntered==guessWords[randomIndex][loopIndex])
           {
               letterGuessed[loopIndex]=1;
               numCorrect++;
           }
       }

       if(oldCorrect==numCorrect)
       {
           numlives--;
           printf("Sorry,wrong guess\n");
           if(numlives==0)
           {
               break;
           }
       }
       else{
           printf("Correct guess :)\n");
       }
       
   }
   if(quit==1)
   {
       printf("\nThe user quit early\n");
   }
   else if(numlives==0)
   {
       printf("Sorry you lose , the word was :%s\n",guessWords[randomIndex]);
   }
   else
   {
       printf("You WIN!!!! :) \n");
   }
}