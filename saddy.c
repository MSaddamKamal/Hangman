#include <stdio.h> // used for scanf , printf etc
#include <stdlib.h> // used for exit()
#include <string.h>// used for strlen and strcpy



//Initialize default variables for all the functions
int defaultLives = 11;
char wordOne[30];
FILE* file;
char path[30] = "lists/listAnimals.txt";

//Main Menu
int main(void){
    
    showSelectionMenu();
	return 0;
}

int clearScreen()
{
    // int n;
    // for (n = 0; n < 10; n++)
    //     printf( "\n\n\n\n\n\n\n\n\n\n" );

     system("cls");
}

int showSelectionMenu()
{
    clearScreen();
    int mainInput;
    printf("\n\n\t\t\t*******************Welcome To The Hangman Game*******************\n\n");
    printf("\t\t\t\t\t\t____________   \n");
    printf("\t\t\t\t\t\t|         |    \n");
    printf("\t\t\t\t\t\t|         0    \n");//Escape characters are printed in C by prepending a backslash prefix to them
    printf("\t\t\t\t\t\t|        /|\\  \n");
    printf("\t\t\t\t\t\t|        / \\  \n");
    printf("\t\t\t\t\t\t|              \n");
    printf("\t\t\t\t\t\t|              \n");
    printf("\n");

    printf("\t\t\t\t\t\tDefault Optiion: QUIT \n\n");
    printf("\t\t\t\t\t\tMAIN MENU:\n\n\t\t\t\t\t\t1:  PLAY\n\t\t\t\t\t\t2:  OPTIONS\n\t\t\t\t\t\t3:  ACKNOWLEDGEMENT\n\t\t\t\t\t\t4:  QUIT\n");
    scanf("%d", &mainInput);
    switch(mainInput){
        case 1:
            clearScreen();
            play();
            break;
        case 2:
            clearScreen();
            defaultLives = options();
            printf("\n\t\t\t\t\t\tThe settings have been saved successfully \n\n");
             printf("\n\t\t\t\t\t\tThe lives have been set to %d. \n\n",defaultLives);
             showSelectionMenu();
            break;
        case 3:
            showAcknoledgment();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n\t\t\t\t\t\t *Please select valid option.\n");
            exit(0);
            break;
    }
}

void showWrongGuesses(char wrongChars[])
{           
            int i;
                   //Display array of wrong guesses
             printf("\n\nWRONG GUESSES:\n\n");
            for(i = 0; i < defaultLives ; i++){

                printf(" %c", wrongChars[i]);
            }
}

void showBlanks(char blanks[],int wordSize){

        int i;

       for( i = 0; i < wordSize; i++)
            printf(" %c", blanks[i]);
}

int displayBackMenu()
{
    int input;
        printf("\n\n\t\t\t\t\t\tTYPE '1' TO PLAY AGAIN\n\t\t\t\t\t\tTYPE '2' TO RETURN TO MAIN MENU\n");
            scanf(" %d", &input);
            switch(input){
                case 1:
                    play();
                    return 0;
                default:
                    main();
                    return 0;
            }
}

void showHangman(float percent)
{
        printf("\t\t\t\t\t\t\t\t\tPrepare for Hanging Bro!   \n");
        if(percent >= 0 && percent <= 15)
        {
            printf("\t\t\t\t\t\t\t\t\t               \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        else if(percent > 15 && percent <= 25)
        {
            printf("\t\t\t\t\t\t\t\t\t____________   \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        else if(percent > 25 && percent <= 35)
        {
            printf("\t\t\t\t\t\t\t\t\t____________   \n");
            printf("\t\t\t\t\t\t\t\t\t|         |    \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        else if(percent > 35 && percent <= 45)
        {

            printf("\t\t\t\t\t\t\t\t\t____________   \n");
            printf("\t\t\t\t\t\t\t\t\t|         |    \n");
            printf("\t\t\t\t\t\t\t\t\t|         0    \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        else if(percent > 45 && percent <= 55)
        {

            printf("\t\t\t\t\t\t\t\t\t____________   \n");
            printf("\t\t\t\t\t\t\t\t\t|         |    \n");
            printf("\t\t\t\t\t\t\t\t\t|         0    \n");
            printf("\t\t\t\t\t\t\t\t\t|         |    \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        else if(percent > 55 && percent <= 65)
        {

            printf("\t\t\t\t\t\t\t\t\t____________   \n");
            printf("\t\t\t\t\t\t\t\t\t|         |    \n");
            printf("\t\t\t\t\t\t\t\t\t|         0    \n");
            printf("\t\t\t\t\t\t\t\t\t|        /|    \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        else if(percent > 65 && percent <= 75)
        {

            printf("\t\t\t\t\t\t\t\t\t____________   \n");
            printf("\t\t\t\t\t\t\t\t\t|         |    \n");
            printf("\t\t\t\t\t\t\t\t\t|         0    \n");
            printf("\t\t\t\t\t\t\t\t\t|        /|\\  \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        else if(percent > 75 && percent <= 99)
        {

            printf("\t\t\t\t\t\t\t\t\t____________   \n");
            printf("\t\t\t\t\t\t\t\t\t|         |    \n");
            printf("\t\t\t\t\t\t\t\t\t|         0    \n");
            printf("\t\t\t\t\t\t\t\t\t|        /|\\  \n");
            printf("\t\t\t\t\t\t\t\t\t|        /     \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        else if(percent == 100)
        {

            printf("\t\t\t\t\t\t\t\t\t____________   \n");
            printf("\t\t\t\t\t\t\t\t\t|         |    \n");
            printf("\t\t\t\t\t\t\t\t\t|         0    \n");
            printf("\t\t\t\t\t\t\t\t\t|        /|\\  \n");
            printf("\t\t\t\t\t\t\t\t\t|        / \\  \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\t\t\t\t\t\t\t\t\t|              \n");
            printf("\n");
        }
        



   
}

int showAcknoledgment()
{
    clearScreen();
    printf("\n\n\n\n\t\t\t\t    *****************Acknowledgement***************** \n\n\n");
    printf("\t\t\tIn the Name of Allah, the most Beneficent and the most Merciful\n");
    printf("\t\t\tWe are profoundly indebted to our course faculty, Mr Touseef Qadeer,\n");
    printf("\t\t\twhose support, mentoring and guiding principles has enabled us to\n");
    printf("\t\t\taccomplish this task. Without his constant check and immense determination, \n");
    printf("\t\t\twe would not have been able to complete our term report. Thank you sir for \n");
    printf("\t\t\tyour sheer mentoring and enlightening our morals and intellect for good. \n");
    printf("\t\t\tWe are also indebted to Mohammad Ali Jinnah University for providing us\n");
    printf("\t\t\twith an opportunity to augment our skills and rationale through such projects.\n");
    printf("\t\t\tLastly, we extend our appreciation for our group members for their cooperation;\n");
    printf("\t\t\tcollaboration without which we could not have consummated the task.\n\n\n\n\n\n");
    printf("\t\t\tRegards DevTeam\n\n");
    printf("\t\t\tMuhammad Saddam Kamal\n");
    printf("\t\t\tJawad Ali\n\n");
   
    printf("\t\t\tThe Code is also avaliable at https://github.com/MSaddamKamal/Hangman\n");

int input;
        printf("\n\n\t\t\t\t\t\tTYPE '1' TO PLAY GAME\n\t\t\t\t\t\tTYPE '2' TO RETURN TO MAIN MENU\n");
            scanf(" %d", &input);
            switch(input){
                case 1:
                    play();
                    return 0;
                default:
                    main();
                    return 0;
            }

}

void showCategoryList()
{
     //Category Selection
    int catInput;
    printf("\n\n\n\n\n\t\t\t\t\t  **********CHOOSE A CATEGORY**********\n\n");
    printf("\t\t\t\t\t\tDefault Category: ANIMALS \n\n");
    printf("\t\t\t\t\t\t1.  ANIMALS\n");
    printf("\t\t\t\t\t\t2.  BOOKS\n");
    printf("\t\t\t\t\t\t3.  BRANDS\n");
    printf("\t\t\t\t\t\t4.  COUNTRIES\n");
    printf("\t\t\t\t\t\t5.  MOVIES\n");
    printf("\t\t\t\t\t\t6.  PEOPLE\n");
    printf("\t\t\t\t\t\t7.  WINTER\n");
    scanf("%d", &catInput);

 
    //set list path

    switch(catInput){
        case 1:
            strcpy(path, "lists/listAnimals.txt");
            break;
       case 2:
            strcpy(path, "lists/listBooks.txt");
            break;
        case 3:
            strcpy(path, "lists/listBrands.txt");
            break;
        case 4:
            strcpy(path, "lists/listCountries.txt");
            break;
        case 5:
            strcpy(path, "lists/listMovies.txt");
            break;
        case 6:
            strcpy(path, "lists/listPeople.txt");
            break;
        case 7:
            strcpy(path, "lists/listWinter.txt");
            break;
        default:
            strcpy(path, "lists/listAnimals.txt");
          


    }

}


//play game
int play(void){

    clearScreen();

	char line[256];
    int i = 0, j = 0, input, counter = 0, spaces = 0; // j is used for index for wrong guesses
    char blanks[30], guess, wrongChars[11] = "";
    int count = 0;
    int counterLives = defaultLives;    
    

    showCategoryList();

   


	char wordOne[256] = "";
    //Pick a 'random' line

    //counting number of lines in a file to create a random int which is in max range of it.

     FILE *fp = fopen(path,"r");
    int ch;
    int lineCount=0;
    do
    {
        ch = fgetc(fp);
        if(ch == '\n') lineCount++;   
    } while( ch != EOF );// EOF means end of file    

    fclose(file);

    

    // create random int with in the range  from 0 to linecount
    int randInt = (rand()%lineCount++);

    FILE *file = fopen(path, "r");

    if(file == NULL)
    {
        printf("\nfile not found\n");
    }

    while (fgets(line, 20, file)) {
         
        if(i == randInt){
            strcpy(wordOne, line);
            break;
        }
        i++;
    }

    fclose(file);

    //Store length of the found string
	int wordSize = strlen(wordOne) - 1;

    //Initialize array blanks with underscores or slashes if it finds a space
    for(i = 0; i < wordSize; i++){
        if(wordOne[i] == ' '){
        	blanks[i] = '/';
			spaces++;
    	}else{
			blanks[i] = '_';
    	}
    }



    //While loop will continuously display updated loops until a person runs out of lives
    while(counterLives > 0){
		int flag = 0;
        clearScreen();

        //Dislay number of lives
        printf(" LIVES: %d\n\n", counterLives);
        
        // hangmen print

        showHangman(((float)j/defaultLives)*100);
         


        showBlanks(blanks,wordSize);
        

        showWrongGuesses(wrongChars);

    
        //Scans for user input and check to see if input matches character in generated word
        printf("\n\nGUESS A LETTER\n");
        scanf(" %c", &guess);
        guess = toupper(guess);
        for(i=0; i<wordSize; i++){
            if(wordOne[i] == guess && blanks[i] == '_'){
                printf("\a");// for sound alert that your input matched
                blanks[i] = guess;
                flag = 1;
				counter++;
            }
		}
       

	   	//if not found, lose a life
		if (flag == 0) {
			counterLives--;
			wrongChars[j] = guess;
			j++;
           
		}


       
		//Lose Screen
		if (counterLives == 0) {
			clearScreen();

			//Display final Lives
			printf(" LIVES: 0", counterLives);
			printf("\n");
            
            showHangman(100);

            showBlanks(blanks,wordSize);


                showWrongGuesses(wrongChars);


                printf("\n\n\nYOU LOSE, THE CORRECT ANSWER IS %s\n\n", wordOne);
              
                return displayBackMenu();
             
		}
        
        //Win Screen
        //counter to match with the total size of word excliding spaces.every time the word is matched the couter will increase
        else if(counter == (wordSize-spaces)){
            clearScreen();
            
            //Display Lives
            printf(" LIVES: %d\n", counterLives);
            printf("\n");
            showHangman(((float)j/defaultLives)*100);
        
       
            showBlanks(blanks,wordSize);
    
      
            showWrongGuesses(wrongChars);
            
            //Display menu to play again or return to main menu
            printf("\n\nYOU WIN!");

             return displayBackMenu();

    	}
    }
}

//Options menu
int options(){
    clearScreen();
    int option, lives;
    printf("\n\n \t\t\t********************Select Your Difficulty Level********************\n\n\n");
    printf("\t\t\t\t\t\tPRESS '1' FOR EASY \n");
    printf("\t\t\t\t\t\tPRESS '2' FOR MEDIUM \n");
    printf("\t\t\t\t\t\tPRESS '3' FOR HARD \n");
    printf("\n");
    scanf("%d", &option);
    
    //decide lives based on option selection
    switch(option){
        case 1:
            lives = 11;
            break;
        case 2:
            lives = 8;
            break;
	    case 3:
            lives = 5;
            break;
        default:
            lives = defaultLives;
	    break;
    }
    return lives;
}


/*The code has been developed By Muhamamad Saddam Kamal Senior FullStack Developer*/