#include <stdio.h>







// FUNCTION PROTOTYPES
void encryptRotation(char *someString, int someInteger);  /* This function rotates someString by someInteger. */ 
void decryptRotation(char *someString, int someInteger);  /* This function rotates someString backwards by someInteger. */

char spellCheck4(char letter1, char letter2, char letter3, char letter4);
char spellCheck5(char letter1, char letter2, char letter3, char letter4, char letter5);
char spellCheck6(char letter1, char letter2, char letter3, char letter4, char letter5, char letter6);
/* The spellCheck functions return 1 if they can see a word held inside of the letters it they take as arguments. If they do not, they return 0. */

char spellCheck4Backup(char letter1, char letter2, char letter3, char letter4);
char spellCheck5Backup(char letter1, char letter2, char letter3, char letter4, char letter5);
char spellCheck6Backup(char letter1, char letter2, char letter3, char letter4, char letter5, char letter6);
/* The spellCheckBackup functions do the same as the spellCheck functions, they just look for more unreliable words. They are used only if
   the spellCheck functions cannot find a word.  */
  
void rotateByOne(char *someString);      
              /* This function rotates someString by one. */
void substitute(char *someString, char originalLiteral, char literalSubstitute, char *memoryString); 
              /* This function substitutes all of the literals in a string that have the value held by originalLiteral and substitutes them with
                 the value of the literal held by literalSubstitute. memoryString is explained in detail later. */
                
                
                /* All functions are described in more detail at their definitions.*/
// FUNCTION PROTOTYPES







int main() {
    
    char userChoice = 0;
    printf("\n\n\nChoose an option:\n\n");
    printf("a). Have a message encrypted with a rotation key of your choosing.\n\n");
    printf("b). Have a rotation cipher decrypted after inputting both the cipher and the rotation key.\n\n");
    printf("c). Have a rotation cipher decrpyted after inputting the cipher.\n\n");
    printf("d). Have a message encrypted with a substitution key of your choosing.\n\n");
    printf("e). Have a substitution cypher decrypted after inputting both the cipher and the substitution key.\n\n");
    scanf("%c", &userChoice);
                        /* The previous code is for a user interface. */
    fgetc(stdin);       /* I put fgetc here because for some reason without it I could not use the fgets function.
                           I used fgets because it scans whitespace.
                           fgetc() seems to act like some kind of fget initialisation and I really do not understand why.*/
    if(userChoice < 'a' || userChoice > 'e') 
    {
        printf("Incorrect choice. Terminating program.\n");  /* This is here incase the user inputs the wrong letter. */
        return 0;
    }
    
    printf("\n\n\n");
    
    
    
    switch(userChoice) {
        case'a': 
        {
            int rotation = 0;   // A variable where the user's choice of rotation key is kept.
            char string[1500];  // The string where the user's input message is kept.
            printf("Type a message.\n");
            fgets(string, 1500, stdin); // Scans a user input message and stores it in 'string'.
            printf("%s\n", string);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("Your message has been encrypted: %s\n", string);
            break;
            
                /* This code takes a user input message and rotates it by an integer that the user inputs. It then outputs the cipher.
                   The encryptRotation() function is what encrypts the message. It is explained at its function definition. */
        }
        
        
        case 'b': 
        {
            int rotation = 0;   // A variable where the user's cipher rotation key is kept,
            char string[1500];  // A string where the user's cipher is kept. I often re-used string and variable names between cases because apparently
                                // they have their own scope.
            printf("Type a rotation cipher.\n");
            fgets(string, 1500, stdin);
            printf("Enter the rotation number that was used to make the cipher.");
            scanf("%d", &rotation);
            decryptRotation(string, rotation);
            printf("I assume your message was: %s\n", string);
            break;
        }
                /* This code takes a user input rotation cipher and then decrypts it after the user has input the key that was used to make the cipher.
                   It then outputs the decrypted message. The decryptRotation() function is what decrypts the message and is explained at its function
                   definition. */
    
        case 'c':
        {
            char string[1500];  // The string where the user's input rotation cipher is kept. 
            int repetition = 1; // This is used in a while loop soon. The loop stops after 26 repetitions.
            int wordFound = 0;  // If the code finds a word during its decryption, wordFound becomes 1, and the decryption stops. 
            int i = 0;          // i for index.
            char letter1 = 0;
            char letter2 = 0;
            char letter3 = 0;       
            char letter4 = 0;
            char letter5 = 0;
            char letter6 = 0;   /* These letter varaibles are used as storage spaces to remember the past few elements of the string during decryption. */
            printf("Type a rotation cipher.\n");
            fgets(string, 1500, stdin);
                                /* The following code is the decrpytion of the cipher. It is a while loop (referred to as Big Loop from now on)
                                   that contains 3 other while loops. None of the three other loops are nested within one another,
                                   they are each nested only in the Big Loop. The Big Loop rotates the user's cipher by 1, and the 3 other loops spell check the
                                   resultant string. This is repeated until The Big Loop has rotated the user's cipher into a string that contains
                                   words that can be picked up by one of the spell checking loops. If none of the rotations have words that can be detected
                                   by the spell checking loops, the decryption has failed. A description of how the spell checking loops work has been included
                                   at the end of the first spell checking loop. */
            while(repetition < 26 && wordFound != 1)
            {
                
                rotateByOne(string); // This function rotates the letters within a string by 1.
                while(string[i] != '\0') // This is the first spell checking loop. It is described below.
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter3 = string[i];
                    i++; 
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter4 = string[i];
                    i++;
                    if(spellCheck4(letter1, letter2, letter3, letter4) == 1)
                    {
                        wordFound = 1;
                        break; 
                    }
                }
                
                letter1 = 0;
                letter2 = 0;
                letter3 = 0;
                letter4 = 0;
                i = 0;
                                   /* The loop above reads through the string while remembering the most recent 4 consecutive elements that it has read. 
                                      The 4 consecutive elements are stored in the letter1-letter4 variables.
                                      Each time one of the letter variables is updated, the spellCheck4 function looks at the 4 most recent consecutive
                                      elements and decides if there is a word in them. That is what the IF statements are for.
                                      spellCheck4 returns 1 if it can see a word, and returns 0 if it cannot. 
                                      If spellCheck4 detects a word within the 4 most recent consecutive elements, wordFound becomes 1 and the break
                                      statement takes the program out of the spell checking loop. wordFound being at the value of 1 takes the program
                                      out of the Big Loop and the decryption is complete. The string that contained the word is then output to the
                                      screen.
                                      The spellCheck4 function only looks for 2 letter words that are encompassed by a space bar at the start and
                                      at the end of the word.
                                      The spellCheck5 function looks for 3 letter words surrounded by space bars, and the spellCheck6 function
                                      looks for 4 letter words surrounded by space bars. 
                                      The following spell checking loops are almost identical to the spell checking loop that was just described.
                                      The only difference is that one uses spellCheck5 and the other uses spellCheck6. 
                                      After each spell checking loop has completed, the variables used in the loop are reset to 0 because they
                                      will be used again by the following loop. If the letters were not reset, it would interfere in spell checking,
                                      and if i was not reset, the following loop would not read through the string. */
                while(string[i] != '\0')
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter3 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter4 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                    letter5 = string[i];
                    i++;
                    if(spellCheck5(letter1, letter2, letter3, letter4, letter5) == 1)
                    {
                        wordFound = 1;
                        break;
                    }
                
                }
                
                letter1 = 0;
                letter2 = 0;
                letter3 = 0;
                letter4 = 0;
                letter5 = 0;
                i = 0;
                
                while(string[i] != '\0')
                {
                    letter1 = string[i];
                    i++;
                    if(spellCheck6(letter1, letter2, letter3, letter4, letter5, letter6 == 1))
                    {
                        wordFound = 1;
                        break;
                    }
                    letter2 = string[i];
                    i++;
                    if(spellCheck6(letter1, letter2, letter3, letter4, letter5, letter6 == 1))
                    {
                        wordFound = 1;
                        break;
                    }
                    letter3 = string[i];
                    i++;
                    if(spellCheck6(letter1, letter2, letter3, letter4, letter5, letter6 == 1))
                    {
                        wordFound = 1;
                        break;
                    }
                    letter4 = string[i];
                    i++;
                    if(spellCheck6(letter1, letter2, letter3, letter4, letter5, letter6 == 1))
                    {
                        wordFound = 1;
                        break;
                    }
                    letter5 = string[i];
                    i++;
                    if(spellCheck6(letter1, letter2, letter3, letter4, letter5, letter6 == 1))
                    {
                        wordFound = 1;
                        break;
                    }
                    letter6 = string[i];
                    i++;
                    if(spellCheck6(letter1, letter2, letter3, letter4, letter5, letter6 == 1))
                    {
                        wordFound = 1;
                        break;
                    }
                    
                }
                
                letter1 = 0;
                letter2 = 0;
                letter3 = 0;
                letter4 = 0;
                letter5 = 0;
                letter6 = 0;
                i = 0;
                
                
                repetition++;
                
            }
            
            /*
               The code below is a backup Big Loop. The only difference between the previous Loop and this second Big Loop is that it uses spellCheckBackup
               functions in its spell checking loops. This second Big Loop will only run if the first Big Loop fails to detect any words.
               The spellCheckBackup functions try to detect words that were deemed too unreliable to place in the main spell checking code (the code
               in the first Big Loop). Hence, the spellCheckBackup functions and the Big Loop below are used as a last resort. 
               An example of a word that is unreliable to detect during decryption is the word " WHAT ". This is because when a particular rotation key is
               applied to "WHAT", the name "ALEX" occurs. This means that if a user's hidden message contained the name ALEX, the Big Loop could rotate
               the user's cipher, and by chance, rotate an encrpyted 'ALEX' into the word 'WHAT'. It would then detect the word 'WHAT' and assume that it
               had decrypted the cipher, when in reality, it hadn't. 
               All variables used in the previous Big Loop are reset here as they are re-used in the following loop. */ 
            i = 0;
            letter1 = 0;
            letter2 = 0;
            letter3 = 0;
            letter4 = 0;
            letter5 = 0;
            letter6 = 0;
            repetition = 1;
            
            
            if(wordFound == 0)
            {
                rotateByOne(string); /* This is here to rotate the string back to the user's cipher. In the case that the previous Big Loop had
                                        failed to detect a word, and consequently triggered the IF statement just above, the user's cipher would have been
                                        rotated a total of 25 times. That leaves it one rotation behind what the user originally input.
                                        So, this rotates it by one to take it back to the original cipher. 
                                        This is done intentionally so that none of the code will spell check the cipher that the user entered. 
                                        (Notice how at the start of the Big Loop below, the rotateByOne() function is used before any of the
                                        spell checking loops start. The same was done in the first Big Loop.)
                                        The reason for not spell checking the user's cipher is for the scenario in which the user's cipher, by chance
                                        contains actual words that happen to be included in the spellCheck() functions.
                                        For example, an encrypted message could still contain the word WHAT (as previously explained in the comment
                                        chunk above of this one). */
                while(repetition < 26 && wordFound != 1)
                {
                    rotateByOne(string);
                    while(string[i] != '\0')
                    {
                        
                        letter1 = string[i];
                        i++;                        
                        if(spellCheck4Backup(letter1, letter2, letter3, letter4) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter2 = string[i];
                        i++;
                        if(spellCheck4Backup(letter1, letter2, letter3, letter4) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter3 = string[i];
                        i++;
                        if(spellCheck4Backup(letter1, letter2, letter3, letter4) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter4 = string[i];
                        i++;
                        if(spellCheck4Backup(letter1, letter2, letter3, letter4) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                    }
                    
                    i = 0;
                    letter1 = 0;
                    letter2 = 0;
                    letter3 = 0;
                    letter4 = 0;
                    
                    while(string[i] != '\0')
                    {
                        
                        letter1 = string[i];
                        i++;
                        if(spellCheck5Backup(letter1, letter2, letter3, letter4, letter5) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter2 = string[i];
                        i++;
                        if(spellCheck5Backup(letter1, letter2, letter3, letter4, letter5) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter3 = string[i];
                        i++;
                        if(spellCheck5Backup(letter1, letter2, letter3, letter4, letter5) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter4 = string[i];
                        i++;     
                        if(spellCheck5Backup(letter1, letter2, letter3, letter4, letter5) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter5 = string[i];
                        i++;
                        if(spellCheck5Backup(letter1, letter2, letter3, letter4, letter5) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                    }
                    
                    i = 0;
                    letter1 = 0;
                    letter2 = 0;
                    letter3 = 0;
                    letter4 = 0;
                    letter5 = 0;
                    
                    while(string[i] != '\0')
                    {
                        
                        letter1 = string[i];
                        i++;
                        if(spellCheck6Backup(letter1, letter2, letter3, letter4, letter5, letter6) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter2 = string[i];
                        i++;
                        if(spellCheck6Backup(letter1, letter2, letter3, letter4, letter5, letter6) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter3 = string[i];
                        i++;
                        if(spellCheck6Backup(letter1, letter2, letter3, letter4, letter5, letter6) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter4 = string[i];
                        i++;
                        if(spellCheck6Backup(letter1, letter2, letter3, letter4, letter5, letter6) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter5 = string[i];
                        i++;
                        if(spellCheck6Backup(letter1, letter2, letter3, letter4, letter5, letter6) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                        letter6 = string[i];
                        i++;
                        if(spellCheck6Backup(letter1, letter2, letter3, letter4, letter5, letter6) == 1)
                        {
                            wordFound = 1;
                            break;
                        }
                    }
                    
                    i = 0;
                    letter1 = 0;
                    letter2 = 0;
                    letter3 = 0;
                    letter4 = 0;
                    letter5 = 0;
                    letter6 = 0;
                    repetition++;
                }
            }

                        
            
            if(wordFound == 1)
            {
                printf("I assume your message was: %s\n", string);
            }
            if(wordFound == 0)
            {
                printf("Decryption failed.\n");
            }
            break;
        }
        
        
        case 'd':
        {
            char string[1500];              // The string the user's input is kept in.
            char substitutions[26] = {'0'}; // This is a string that will hold the user's substitution alphabet.
            int interfaceLetter = 'A';      // This is used as an output when the user is entering their substitution alphabet.
            int i = 0;                      // i for index.
            int letter = 'A';               // This is used in the substitution function. 
            char indexMemory[1500];         
            /* The substitute() function needs to know at what indexes it has replaced letters in 'string' during the past. The indexMemory string keeps a
               record of the indexes where the substitution function has changed a letter. */
            printf("Type a message that you wish to be encrypted.\n");
            fgets(string, 1500, stdin);
            printf("You will now be prompted with the letters of the alphabet.\n");
            printf("Each time a letter appears, type the letter you wish the prompt-letter to be replaced with during the encryption.\n");
            printf("Remember: to create a proper substitution alphabet, you must only enter each letter of the alphabet once.\n");
            printf("Please use upper case when entering your substitutions.\n\n");
            while(i < 26)
            {
                printf("Letters you have typed:%s", substitutions); // This is here in case the user is making their alphabet off the cuff and does not know
                                                                    // what letters they have previously entered.
                printf("\nSubstitution for %c:  ", interfaceLetter);
                scanf(" %c", &substitutions[i]);
                interfaceLetter++;
                i++;
            }
            i = 0;
                /* The while loop above prints a letter of the alphabet starting at A and then takes a letter input from the user. This is repeated 26 times.
                   The input is stored in the 'substitutions' array. The letter the user input for example when the program output 'A' will be the letter
                   that replaces all A's in the string during the process of encryption. i is reset to 0 as it is used in the next loop.*/
            while(i < 26)
            {
                substitute(string, letter, substitutions[i], indexMemory);
                letter++;
                i++;
            }
               /* The while loop above encrypts the user's message with their substitution alphabet. The substitute() function only substitutes
                  one unique letter for another each time it is called, so it must be repeatedly used to completely encrypt a message. The second argument is
                  the letter in the string that will be substituted by the letter held in the third argument.
                  On substitute()'s first call in this loop, 'letter' has the value of 'A'. substitute[i] has the value held in substitute[0]
                  (i = 0 at this point). The value held in substitute[0] is the letter the user input when prompted with the letter 'A'.
                  On the second use, 'letter' has been incremented by 1, and so has i, and so it moves onto replacing
                  all the Bs in the string with whatever the user input when prompted with 'B'. This continues until the substitution encryption is complete. 
                  The function is further explained at its function definition. */
            printf("Your encrypted message: %s\n", string);
            break;
            
        }  
        
        
        case 'e':
        {
            char indexMemory[1500]; // The substitute() function is used again here so again it requires a memory string. 
            char string[1500];      // The string where the user's input is kept. 
            int letter = 'A';       // This is used in the substitute function.
            int interfaceLetter = 'A';  // This is used as an output when the user inputs their substitution alphabet. 
            char substitutions[26];   // This is where the user's substitution alphabet is kept. 
            int i = 0;                // i for index.
            printf("Type a substitution cipher.\n");
            fgets(string, 1500, stdin);
            printf("You will now be prompted with the letters of the alphabet.\n");
            printf("At each prompt, please enter the letter you used in your cipher alphabet to substitute the prompt-letter.\n");
            printf("Please use upper case when entering your substitutions.\n\n");
            while(i < 26)
            {
                printf("Substitution for %c:  ", interfaceLetter);
                scanf(" %c", &substitutions[i]);
                interfaceLetter++;
                i++;
            }
            i = 0;
              /* The loop above is identical to the user input loop in case 'd'. It scans and stores the user's substitution alphabet in substitutions[].
                 i is reset to 0 because it is used in the following loop.*/
            while(i < 26)
            {
                substitute(string, substitutions[i], letter, indexMemory);
                letter++;
                i++;
            }
    /* The loop above is almost identical to the loop in case 'd'. The only difference is that 'substitutions[i]' is now the second argument, 'and letter'
       is the third argument. So, on the functions first use in the loop, the user's letter substitution for 'A' for their cipher
       will now be replaced with 'A'.
       This is repeated for each letter of the alphabet. */ 
            printf("I assume your message was: %s", string);
            break;
        }
        
        
        default:
        {
            break;
        }
    }
    
    
    
    
    
    return 0;
}



// FUNCTION DEFINITIONS
void rotateByOne(char *someString)
{
    int i = 0; //i for index
    while(someString[i] != '\0')
    {                                                                                                    /* ASCII 39 is the ' symbol */
        if(someString[i] == '.' || someString[i] == ' ' || someString[i] == '!' || someString[i] == '?' || someString[i] == 39 || someString[i] == '"')
        {
            i++;
        }
        else if(someString[i] == '(' || someString[i] == ')' || someString[i] == ';' || someString[i] == ':' || someString[i] == '-' || someString[i] == ',')
        {
            i++;
        }
        else if(someString[i] >= 65 && someString[i] <= 90 && someString[i] + 1 > 90)
        {
            someString[i] = someString[i] + 1 - 26;
            i++;
        }
        else
        {
            someString[i] = someString[i] + 1;
            i++;
        }
    }
    /* This function rotates the letters in a string of words by a key of 1. A turns into B, B turns into C and so on.
    The while condition ensures that the string is read in its entirety. The loop contains an IF, 2 ELSE IFS, and an ELSE that check each of the 3 possible
    scenariors that can occur each time the string at index i is read. The IF and the first IF ELSE check for the scenario at which the string element at i
    is a grammatical feature. If this is the case, the element at i will be left and unchanged, and i will be incremented; effectively skipping over that element.
    This is because only letters are to be changed, and not grammatical features such as space bars and whatnot. The second ELSE IF checks for
    the scenario at which the element at i is a letter that will be greater than ASCII 90 (Z) if it is incremented by 1. If this is the case, the element is 
    incremented by 1, then reduced by 26 to take it back into the ASCII alphabet. i is then incremented.For this function, this scenario only occurs 
    when the string element at i is Z.
    The ELSE at the end is for the only possible scenario left after the previous IFs are checked. That is if the element at i is just a letter that can
    be incremented by one without leaving the boundaries of ASCII 65-ASCII 90. If this is the case, the element at i is incremented by 1, and so is i. */

}


void encryptRotation(char *someString, int someInteger) 
{
    int i = 0; // i for index
    while(someString[i] != '\0') 
    {                                                                                                     /* ASCII 39 is the ' symbol */
        if(someString[i] == '.' || someString[i] == ' ' || someString[i] == '!' || someString[i] == '?' || someString[i] == 39 || someString[i] == '"')
        {
            i++;
        }
        else if(someString[i] == '(' || someString[i] == ')' || someString[i] == ';' || someString[i] == ':' || someString[i] == '-' || someString[i] == ',')
        {
            i++;
        }
        else if(someString[i] <= 90 && someString[i] >= 65 && someString[i] + someInteger > 90)
        {
            someString[i] = someString[i] + someInteger - 26;
            i++;
        }
        else
        {
            someString[i] = someString[i] + someInteger;
            i++;
        }
    }
    /* This function works almost identically to rotateByOne(). The only difference is that when a letter is changed, it is increased by 'someInteger' 
    rather than 1. Its purpose is to take a string of regular words and then turn it into a rotation cipher using the key held by the value of someInteger. 
    The while condition ensures that the string is read in its entirety. The loop contains an IF, 2 ELSE IFS, and an ELSE that check each of the 3 possible
    scenariors that can occur each time the string at index i is read. The IF and the first IF ELSE check for the scenario at which the string element at i
    is a grammatical feature. If this is the case, the element at i will be left and unchanged, and i will be incremented; effectively skipping over that element.
    This is because only letters are to be changed, and not grammatical features such as space bars and whatnot.
    The second ELSE IF checks for the scenario at which the element at i is a letter that will be greater than ASCII 90 (Z) if it is incremented by someInteger.
    If this is the case, the element is incremented by the value of someInteger, then reduced by 26 to take it back into the ASCII alphabet.
    i is then incremented. The ELSE at the end is for the only possible scenario left after the previous IFs are checked. That is if the element at i is
    just a letter that can be incremented by someInteger without leaving the boundaries of ASCII 65-ASCII 90. If this is the case, the element at i is
    incremented by someInteger, and i is incremented by 1. */
   
}




void decryptRotation(char *someString, int someInteger)
{
    int i = 0; // i for index
    while(someString[i] != '\0') 
    {                                                                                                    /* ASCII 39 is the ' symbol */
        if(someString[i] == '.' || someString[i] == ' ' || someString[i] == '!' || someString[i] == '?' || someString[i] == 39 || someString[i] == '"')
        {
            i++;
        }
        else if(someString[i] == '(' || someString[i] == ')' || someString[i] == ';' || someString[i] == ':' || someString[i] == '-' || someString[i] == ',')
        {
            i++;
        }
        else if(someString[i] <= 90 && someString[i] >= 65 && someString[i] - someInteger < 65)
        {
            someString[i] = someString[i] - someInteger + 26;
            i++;
        }
        else
        {
          someString[i] = someString[i] - someInteger;
          i++;
        }
    }
    /* This function works almost identically to encryptRotation(). The only difference is that when a letter is changed, it is decreased by 'someInteger' 
    rather increased by someInteger. Its purpose is to take a rotation cipher and take it back to its original text using the key used to rotate it.
    The while condition ensures that the string is read in its entirety. The loop contains an IF, 2 ELSE IFS, and an ELSE that check each of the 3 possible
    scenariors that can occur each time the string at index i is read. The IF and the first IF ELSE check for the scenario at which the string element at i
    is a grammatical feature. If this is the case, the element at i will be left and unchanged, and i will be incremented; effectively skipping over that element.
    This is because only letters are to be changed, and not grammatical features such as space bars and whatnot.
    The second ELSE IF checks for the scenario at which the element at i is a letter that will be less than ASCII 65 (A) if it is decreased by someInteger.
    If this is the case, the element is decreased by the value of someInteger, then increased by 26 to take it back into the ASCII alphabet.
    i is then incremented. The ELSE at the end is for the only possible scenario left after the previous IFs are checked. That is if the element at 
    i is just a letter that can be decreased by someInteger without leaving the boundaries of ASCII 65-ASCII 90. If this is the case,
    the element at i is decreased by someInteger, and i is incremented by 1. */
}
    



void substitute(char *someString, char originalLiteral, char literalSubstitute, char *memoryString)
{
    int i = 0; // i for index.
    while(someString[i] != '\0')
            {
                if(someString[i] == originalLiteral && memoryString[i] != '-')
                {
                    someString[i] = literalSubstitute;
                    memoryString[i] = '-';
                }
                i++;
            }
    /* The while loop above reads through each character held by 'someString'. If it runs into a character that is equal to 'originalLiteral', it will change the 
       value of that character into the value of the character held by 'literalSubstitute'. So, if 'A' is the second argument, and 'B' is the third, the loop
       will run through the string and turn A's into B's. 
       When the IF statement changes the value of a character, it also remembers the index at which it changed it. It does so by placing a 'marker' (the '-' symbol)
       inside the memoryString at that index. One of the conditions for the IF statement to trigger is that the memoryString at that index does not already have
       a marker on it.
       This is necessary because the substitute function only changes one unique letter each time it is called. The following is a possbile scenario that would
       occur if each index was not remembered when a letter at that index was changed:
       
       (someString holds the string: "ABBA". The user's substitution alphabet switches A for B, and B for A. On substitute()'s first call, it switches A's for B's
       and the string now looks like: "BBBB". On substitute()'s second call, it switches B's for A's. The string now looks like: "AAAA".)
       
       "AAAA" was not the intended result. "BAAB" was the intended result. So, for the function to work as intended, it needs to know at which indexes
       it had already performed a substitution. That way it can know not to perform another substitution at that index again.
       That is the purpose the memoryString serves. */
}





char spellCheck4(char letter1, char letter2, char letter3, char letter4)
{
    
            /* There are multiple chunks of IF statements here. Each chunk looks for 1 word each. The chunk below looks for the word 'IN'. 
               Each chunk is exactly the same as the last one, it just looks for a different word. */
            
            
    if(letter1 == ' ' && letter2 == 'I' && letter3 == 'S' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'I' && letter4 == 'S' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'I' && letter1 == 'S' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'I' && letter2 == 'S' && letter3 == ' ')
    {
        return 1;
    }
    
        /* This function works by looking at the 4 most recent consecutive characters read in a string. The above 'IF chunk' looks for the word 'IN' within those
           4 consecutive characters. You will see each IF in the chunk has the order of their letter variables offset by one when compared to the one above it.
           This is because there are 4 permutations (or is it combinations?) that the 4 most recent consecutive characters can contain the word 'IN' surrounded
           by a space bar on each end. For example, if the start of string looked like this: "I AM IN ....", only the first IF statement would detect the word.
           If the start of the string looked like this: "AM IN ...." only the third IF statement would detect the word. If a word is detected by any of the IFs
           in this function, the function will return 1. If no word is found, it returns 0. 
           To help understand what was just described, when the loop that uses this function reads a string and remembers the 4 most recent characters in the string,
           it looks like this:   
                                           "AM IN A DOG HOUSE" - someString                 
                                            12341234123412341  - the letter variables counting and remembering.             
                                             [3412]            -  Notice how the 4 variables that hold " IN " are the variables: letter3, letter4
                                                                  letter1, letter2 in that order. */
    
    
      
    if(letter1 == ' ' && letter2 == 'O' && letter3 == 'F' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'O' && letter4 == 'F' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'O' && letter1 == 'F' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'O' && letter2 == 'F' && letter3 == ' ')
    {
        return 1;
    } 
    
    
    
    if(letter1 == ' ' && letter2 == 'O' && letter3 == 'N' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'O' && letter4 == 'N' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'O' && letter1 == 'N' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'O' && letter2 == 'N' && letter3 == ' ')
    {
        return 1;
    } 
    
    
    
    
    
    
    
    return 0;
}






char spellCheck5(char letter1, char letter2, char letter3, char letter4, char letter5)
{
    /* This function works exactly the same way the spellCheck4 function works. However, instead, it looks for 3 letter words surrounded by a space bar on each end.
       Hence, it must remember 1 more consecutive character than spellCheck4, and hence each 'IF chunk' contains another IF because there is one more permutation 
       (combination?) for which a 3 letter word can be found in the past 5 consecutive characters. */ 
    if(letter1 == ' ' && letter2 == 'A' && letter3 == 'N' && letter4 == 'D' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'A' && letter2 == 'N' && letter3 == 'D' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'A' && letter1 == 'N' && letter2 == 'D' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'A' && letter5 == 'N' && letter1 == 'D' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'A' && letter4 == 'N' && letter5 == 'D' && letter1 == ' ')
    {
        return 1;  
    }
         
    
    
    if(letter1 == ' ' && letter2 == 'C' && letter3 == 'A' && letter4 == 'N' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'C' && letter2 == 'A' && letter3 == 'N' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'C' && letter1 == 'A' && letter2 == 'N' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'C' && letter5 == 'A' && letter1 == 'N' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'C' && letter4 == 'A' && letter5 == 'N' && letter1 == ' ')
    {
        return 1;  
    }
    
    

    if(letter1 == ' ' && letter2 == 'F' && letter3 == 'O' && letter4 == 'R' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'F' && letter2 == 'O' && letter3 == 'R' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'F' && letter1 == 'O' && letter2 == 'R' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'F' && letter5 == 'O' && letter1 == 'R' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'F' && letter4 == 'O' && letter5 == 'R' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'Y' && letter3 == 'O' && letter4 == 'U' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'Y' && letter2 == 'O' && letter3 == 'U' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'Y' && letter1 == 'O' && letter2 == 'U' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'Y' && letter5 == 'O' && letter1 == 'U' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'Y' && letter4 == 'O' && letter5 == 'U' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'N' && letter3 == 'O' && letter4 == 'T' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'N' && letter2 == 'O' && letter3 == 'T' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'N' && letter1 == 'O' && letter2 == 'T' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'N' && letter5 == 'O' && letter1 == 'T' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'N' && letter4 == 'O' && letter5 == 'T' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'O' && letter3 == 'U' && letter4 == 'R' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'O' && letter2 == 'U' && letter3 == 'R' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'O' && letter1 == 'U' && letter2 == 'R' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'O' && letter5 == 'U' && letter1 == 'R' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'O' && letter4 == 'U' && letter5 == 'R' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'W' && letter3 == 'A' && letter4 == 'S' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'W' && letter2 == 'A' && letter3 == 'S' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'W' && letter1 == 'A' && letter2 == 'S' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'W' && letter5 == 'A' && letter1 == 'S' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'W' && letter4 == 'A' && letter5 == 'S' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'O' && letter3 == 'U' && letter4 == 'T' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'O' && letter2 == 'U' && letter3 == 'T' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'O' && letter1 == 'U' && letter2 == 'T' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'O' && letter5 == 'U' && letter1 == 'T' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'O' && letter4 == 'U' && letter5 == 'T' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'S' && letter3 == 'A' && letter4 == 'Y' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'S' && letter2 == 'A' && letter3 == 'Y' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'S' && letter1 == 'A' && letter2 == 'Y' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'S' && letter5 == 'A' && letter1 == 'Y' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'S' && letter4 == 'A' && letter5 == 'Y' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'T' && letter3 == 'O' && letter4 == 'O' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'T' && letter2 == 'O' && letter3 == 'O' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'T' && letter1 == 'O' && letter2 == 'O' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'T' && letter5 == 'O' && letter1 == 'O' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'T' && letter4 == 'O' && letter5 == 'O' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'D' && letter3 == 'A' && letter4 == 'Y' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'D' && letter2 == 'A' && letter3 == 'Y' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'D' && letter1 == 'A' && letter2 == 'Y' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'D' && letter5 == 'A' && letter1 == 'Y' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'D' && letter4 == 'A' && letter5 == 'Y' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'H' && letter3 == 'I' && letter4 == 'M' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'H' && letter2 == 'I' && letter3 == 'M' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'H' && letter1 == 'I' && letter2 == 'M' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'H' && letter5 == 'I' && letter1 == 'M' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'H' && letter4 == 'I' && letter5 == 'M' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'H' && letter3 == 'O' && letter4 == 'W' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'H' && letter2 == 'O' && letter3 == 'W' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'H' && letter1 == 'O' && letter2 == 'W' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'H' && letter5 == 'O' && letter1 == 'W' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'H' && letter4 == 'O' && letter5 == 'W' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'N' && letter3 == 'O' && letter4 == 'W' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'N' && letter2 == 'O' && letter3 == 'W' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'N' && letter1 == 'O' && letter2 == 'W' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'N' && letter5 == 'O' && letter1 == 'W' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'H' && letter4 == 'O' && letter5 == 'W' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'O' && letter3 == 'L' && letter4 == 'D' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'O' && letter2 == 'L' && letter3 == 'D' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'O' && letter1 == 'L' && letter2 == 'D' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'O' && letter5 == 'L' && letter1 == 'D' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'O' && letter4 == 'L' && letter5 == 'D' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'L' && letter3 == 'E' && letter4 == 'T' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'L' && letter2 == 'E' && letter3 == 'T' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'L' && letter1 == 'E' && letter2 == 'T' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'L' && letter5 == 'E' && letter1 == 'T' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'L' && letter4 == 'E' && letter5 == 'T' && letter1 == ' ')
    {
        return 1;  
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'W' && letter3 == 'A' && letter4 == 'Y' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'W' && letter2 == 'A' && letter3 == 'Y' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'W' && letter1 == 'A' && letter2 == 'Y' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'W' && letter5 == 'A' && letter1 == 'Y' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'W' && letter4 == 'A' && letter5 == 'Y' && letter1 == ' ')
    {
        return 1;  
    }
        
        
        
    return 0;
}
    
    



char spellCheck6(char letter1, char letter2, char letter3, char letter4, char letter5, char letter6)
{
    /* This function works just like spellCheck5 and spellCheck4. It looks for 4 letter words surrounded by a space bar on each end, and contains one more IF per
       'IF chunk'. */
    if(letter1 == ' ' && letter2 == 'T' && letter3 == 'H' && letter4 == 'A' && letter5 == 'T' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'T' && letter2 == 'H' && letter3 == 'A' && letter4 == 'T' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'T' && letter1 == 'H' && letter2 == 'A' && letter3 == 'T' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'T' && letter6 == 'H' && letter1 == 'A' && letter2 == 'T' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'T' && letter5 == 'H' && letter6 == 'A' && letter1 == 'T' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'T' && letter4 == 'H' && letter5 == 'A' && letter6 == 'T' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'T' && letter3 == 'H' && letter4 == 'E' && letter5 == 'Y' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'T' && letter2 == 'H' && letter3 == 'E' && letter4 == 'Y' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'T' && letter1 == 'H' && letter2 == 'E' && letter3 == 'Y' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'T' && letter6 == 'H' && letter1 == 'E' && letter2 == 'Y' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'T' && letter5 == 'H' && letter6 == 'E' && letter1 == 'Y' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'T' && letter4 == 'H' && letter5 == 'E' && letter6 == 'Y' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'W' && letter3 == 'I' && letter4 == 'T' && letter5 == 'H' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'W' && letter2 == 'I' && letter3 == 'T' && letter4 == 'H' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'W' && letter1 == 'I' && letter2 == 'T' && letter3 == 'H' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'W' && letter6 == 'I' && letter1 == 'T' && letter2 == 'H' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'W' && letter5 == 'I' && letter6 == 'T' && letter1 == 'H' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'W' && letter4 == 'I' && letter5 == 'T' && letter6 == 'H' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'W' && letter3 == 'I' && letter4 == 'L' && letter5 == 'L' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'W' && letter2 == 'I' && letter3 == 'L' && letter4 == 'L' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'W' && letter1 == 'I' && letter2 == 'L' && letter3 == 'L' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'W' && letter6 == 'I' && letter1 == 'L' && letter2 == 'L' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'W' && letter5 == 'I' && letter6 == 'L' && letter1 == 'L' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'W' && letter4 == 'I' && letter5 == 'L' && letter6 == 'L' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'W' && letter3 == 'A' && letter4 == 'N' && letter5 == 'T' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'W' && letter2 == 'A' && letter3 == 'N' && letter4 == 'T' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'W' && letter1 == 'A' && letter2 == 'N' && letter3 == 'T' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'W' && letter6 == 'A' && letter1 == 'N' && letter2 == 'T' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'W' && letter5 == 'A' && letter6 == 'N' && letter1 == 'T' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'W' && letter4 == 'A' && letter5 == 'N' && letter6 == 'T' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'S' && letter3 == 'O' && letter4 == 'M' && letter5 == 'E' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'S' && letter2 == 'O' && letter3 == 'M' && letter4 == 'E' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'S' && letter1 == 'O' && letter2 == 'M' && letter3 == 'E' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'S' && letter6 == 'O' && letter1 == 'M' && letter2 == 'E' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'S' && letter5 == 'O' && letter6 == 'M' && letter1 == 'E' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'S' && letter4 == 'O' && letter5 == 'M' && letter6 == 'E' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'Y' && letter3 == 'O' && letter4 == 'U' && letter5 == 'R' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'Y' && letter2 == 'O' && letter3 == 'U' && letter4 == 'R' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'Y' && letter1 == 'O' && letter2 == 'U' && letter3 == 'R' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'Y' && letter6 == 'O' && letter1 == 'U' && letter2 == 'R' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'Y' && letter5 == 'O' && letter6 == 'U' && letter1 == 'R' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'Y' && letter4 == 'O' && letter5 == 'U' && letter6 == 'R' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'F' && letter3 == 'R' && letter4 == 'O' && letter5 == 'M' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'F' && letter2 == 'R' && letter3 == 'O' && letter4 == 'M' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'F' && letter1 == 'R' && letter2 == 'O' && letter3 == 'M' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'F' && letter6 == 'R' && letter1 == 'O' && letter2 == 'M' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'F' && letter5 == 'R' && letter6 == 'O' && letter1 == 'M' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'F' && letter4 == 'R' && letter5 == 'O' && letter6 == 'M' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'K' && letter3 == 'N' && letter4 == 'O' && letter5 == 'W' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'K' && letter2 == 'N' && letter3 == 'O' && letter4 == 'W' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'K' && letter1 == 'N' && letter2 == 'O' && letter3 == 'W' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'K' && letter6 == 'N' && letter1 == 'O' && letter2 == 'W' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'K' && letter5 == 'N' && letter6 == 'O' && letter1 == 'W' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'K' && letter4 == 'N' && letter5 == 'O' && letter6 == 'W' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'T' && letter3 == 'I' && letter4 == 'M' && letter5 == 'E' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'T' && letter2 == 'I' && letter3 == 'M' && letter4 == 'E' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'T' && letter1 == 'I' && letter2 == 'M' && letter3 == 'E' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'T' && letter6 == 'I' && letter1 == 'M' && letter2 == 'E' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'T' && letter5 == 'I' && letter6 == 'M' && letter1 == 'E' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'T' && letter4 == 'I' && letter5 == 'M' && letter6 == 'E' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'H' && letter3 == 'A' && letter4 == 'V' && letter5 == 'E' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'H' && letter2 == 'A' && letter3 == 'V' && letter4 == 'E' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'H' && letter1 == 'A' && letter2 == 'V' && letter3 == 'E' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'H' && letter6 == 'A' && letter1 == 'V' && letter2 == 'E' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'H' && letter5 == 'A' && letter6 == 'V' && letter1 == 'E' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'H' && letter4 == 'A' && letter5 == 'V' && letter6 == 'E' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'M' && letter3 == 'U' && letter4 == 'C' && letter5 == 'H' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'M' && letter2 == 'U' && letter3 == 'C' && letter4 == 'H' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'M' && letter1 == 'U' && letter2 == 'C' && letter3 == 'H' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'M' && letter6 == 'U' && letter1 == 'C' && letter2 == 'H' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'M' && letter5 == 'U' && letter6 == 'C' && letter1 == 'H' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'M' && letter4 == 'U' && letter5 == 'C' && letter6 == 'H' && letter1 == ' ')
    {
        return 1;
    }
    
    
    
    if(letter1 == ' ' && letter2 == 'B' && letter3 == 'E' && letter4 == 'E' && letter5 == 'N' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'B' && letter2 == 'E' && letter3 == 'E' && letter4 == 'N' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'B' && letter1 == 'E' && letter2 == 'E' && letter3 == 'N' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'B' && letter6 == 'E' && letter1 == 'E' && letter2 == 'N' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'B' && letter5 == 'E' && letter6 == 'E' && letter1 == 'N' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'B' && letter4 == 'E' && letter5 == 'E' && letter6 == 'N' && letter1 == ' ')
    {
        return 1;
    }
    
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
char spellCheck4Backup(char letter1, char letter2, char letter3, char letter4)
{
    if(letter1 == ' ' && letter2 == 'I' && letter3 == 'N' && letter4 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'I' && letter4 == 'N' && letter1 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'I' && letter1 == 'N' && letter2 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter1 == 'I' && letter2 == 'N' && letter3 == ' ')
    {
        return 1;
    }
    
    return 0;
}



char spellCheck5Backup(char letter1, char letter2, char letter3, char letter4, char letter5)
{
    if(letter1 == ' ' && letter2 == 'T' && letter3 == 'H' && letter4 == 'E' && letter5 == ' ')
    {
        return 1;  
    }
    if(letter5 == ' ' && letter1 == 'T' && letter2 == 'H' && letter3 == 'E' && letter4 == ' ')
    {
        return 1;  
    }
    if(letter4 == ' ' && letter5 == 'T' && letter1 == 'H' && letter2 == 'E' && letter3 == ' ')
    {
        return 1;  
    }
    if(letter3 == ' ' && letter4 == 'T' && letter5 == 'H' && letter1 == 'E' && letter2 == ' ')
    {
        return 1;  
    }
    if(letter2 == ' ' && letter3 == 'T' && letter4 == 'H' && letter5 == 'E' && letter1 == ' ')
    {
        return 1;  
    }
    
    return 0;
}



char spellCheck6Backup(char letter1, char letter2, char letter3, char letter4, char letter5, char letter6)
{
    if(letter1 == ' ' && letter2 == 'W' && letter3 == 'H' && letter4 == 'A' && letter5 == 'T' && letter6 == ' ')
    {
        return 1;
    }
    if(letter6 == ' ' && letter1 == 'W' && letter2 == 'H' && letter3 == 'A' && letter4 == 'T' && letter5 == ' ')
    {
        return 1;
    }
    if(letter5 == ' ' && letter6 == 'W' && letter1 == 'H' && letter2 == 'A' && letter3 == 'T' && letter4 == ' ')
    {
        return 1;
    }
    if(letter4 == ' ' && letter5 == 'W' && letter6 == 'H' && letter1 == 'A' && letter2 == 'T' && letter3 == ' ')
    {
        return 1;
    }
    if(letter3 == ' ' && letter4 == 'W' && letter5 == 'H' && letter6 == 'A' && letter1 == 'T' && letter2 == ' ')
    {
        return 1;
    }
    if(letter2 == ' ' && letter3 == 'W' && letter4 == 'H' && letter5 == 'A' && letter6 == 'T' && letter1 == ' ')
    {
        return 1;
    }
    
    return 0; 
}
    
    
// FUNCTION DEFINITIONS









/*
 File Stuff.
            FILE *input;
            input = fopen("file.test", "w");
            fprintf(input, "foo");
            fclose(input);
            input = fopen("file.test", "r");
            char str[100];
            fscanf(input, "%s", str);
            printf("%s", str);
 */







