#include <stdio.h>







// FUNCTION PROTOTYPES
void encryptRotation(char *someString, int someInteger);
void decryptRotation(char *someString, int someInteger);
char spellCheck4(char letter1, char letter2, char letter3, char letter4);
char spellCheck5(char letter1, char letter2, char letter3, char letter4, char letter5);
char spellCheck6(char letter1, char letter2, char letter3, char letter4, char letter5, char letter6);
void rotateByOne(char *someString);
void substitute(char *someString, char originalLiteral, char literalSubstitute, char *memoryString);
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
                        /* The previous code is just for a user interface. */
    fgetc(stdin);       /* I put fgetc here because for some reason without it I cannot use the fgets function. I use fgets because it scans whitespace.
                           fgetc() seems to act like some kind of fget initialisation and I really do not understand why.*/
    if(userChoice < 'a' || userChoice > 'h') 
    {
        printf("Incorrect choice. Terminating program.\n");  /* This is here just incase the user inputs the wrong letter. */
        return 0;
    }
    
    printf("\n\n\n");
    
    
    
    switch(userChoice) {
        case'a': 
        {
            int rotation = 0;   // A variable where the user's choice of rotation key is kept.
            char string[1500];  // The string the user's input message is kept in.
            printf("Type a message.\n");
            fgets(string, 1500, stdin);
            printf("%s\n", string);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("Your message has been encrypted: %s\n", string);
            break;
            
                /* This code just takes a user input message and rotates it by an integer that the user inputs. It then outputs the cipher.
                   The encryptRotation() function is what encrypts the message. It is explained at its function definition. */
        }
        
        
        case 'b': 
        {
            int rotation = 0;
            char string[1500];
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
            int repetition = 1; // This is used in a while loop soon. It stops after 26 repetitions.
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
                                   by the spell checking loops, the decryption has failed. A description how the spell checking loops work has been included
                                   at the end of the first spell checking loop. */
            while(repetition < 26 && wordFound != 1)
            {
                
                rotateByOne(string); // This function rotates the letters within a string by 1.
                while(string[i] != '\0') // This is the first spell check function. It is described below.
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
                                      Each time one of the letter variables is updated, the spellCheck4 function looks at the 4 consecutive
                                      elements and decides if there is a word in them. That is what the IF statements are for.
                                      spellCheck4 returns 1 if it can see a word, and returns 0 if it cannot. 
                                      If spellCheck4 detects a word within the 4 most recent consecutive elements, wordFound becomes 1 and the break
                                      statement takes the program out of the spell checking loop. wordFound being at the value of 1 takes the program
                                      out of the Big Loop and the decryption is complete. The string that contained the word is then output to the
                                      screen.
                                      The spellCheck4 function only looks for 2 letter words that are encompassed by a space bar at the start and
                                      at the end of the word.
                                      The spellCheck5 function looks for 3 letter words surrounded by a space bars, and the spellCheck6 function
                                      looks for 4 letter words surrounded by space bars. 
                                      The following spell checking loops are almost identical to the spell checking loop that wasjust described.
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
            if(wordFound == 1)
            {
                printf("I assume your message was: %s\n", string);
            }
            if(wordFound != 1)
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
            // The substitution() function needs to know at what indexes it has replaced letters in a string in the past. The indexMemory string keeps a record 
            // of the indexes where the substitution function has changed a letter.
            printf("Type a message that you wish to be encrypted.\n");
            fgets(string, 1500, stdin);
            printf("You will now be prompted with the letters of the alphabet.\n");
            printf("Each time a letter appears, type the letter you wish the prompt-letter to be replaced with during the encryption.\n");
            printf("Remember: to create a proper substitution alphabet, you must only enter each letter of the alphabet once.\n");
            printf("Please use upper case when entering your substitutions.\n\n");
            while(i < 26)
            {
                printf("Letters you have typed:%s", substitutions);
                printf("\nSubstitution for %c:  ", interfaceLetter);
                scanf(" %c", &substitutions[i]);
                interfaceLetter++;
                i++;
            }
            i = 0;
            while(i < 26)
            {
                substitute(string, letter, substitutions[i], indexMemory);
                letter++;
                i++;
            }
            
            printf("%s\n", string);
            break;
            
        }  
        
        
        case 'e':
        {
            char indexMemory[1500];
            char string[1500];
            int letter = 'A';
            int interfaceLetter = 'A';
            char substitutions[26];
            int i = 0;
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
            while(i < 26)
            {
                substitute(string, substitutions[i], letter, indexMemory);
                letter++;
                i++;
            }
            printf("I assume your message was: %s", string);
            break;
        }
        
        case 'g':
        {
            char string[1000];
            char number = 1;
            char rep = 1;
            while(rep < 60)
            {
                number = 1;
                printf("\n\n");
                fgets(string, 1000, stdin);
                while(number < 27)
                {
                    rotateByOne(string);
                    printf("%s   ", string);
                    number++; 
                }
                rep++;
            }

            break;
        }
        case 'h':
        {
            //int i = 1;
            char string[1000];
            fgets(string, 2000, stdin);
            /* while(string[i] != '\0')
            {
                printf("%d\n", i);
                i++;
            } */
            printf("%s\n", string);
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
    {
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
    /* As the name hopefully suggests, this function rotates the letters in a string of words by a key of 1. A turns into B, B turns into C and so on.
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
    {
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
    {
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
    int i = 0;
    while(someString[i] != '\0')
            {
                if(someString[i] == originalLiteral && memoryString[i] != '-')
                {
                    someString[i] = literalSubstitute;
                    memoryString[i] = '-';
                }
                i++;
            }
    /* */
}





char spellCheck4(char letter1, char letter2, char letter3, char letter4)
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
/* */





char spellCheck5(char letter1, char letter2, char letter3, char letter4, char letter5)
{
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







