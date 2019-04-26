#include <stdio.h>







// FUNCTION PROTOTYPES
void encryptRotation(char *someString, int someInteger);
void decryptRotation(char *someString, int someInteger);
void putInSpaces(char *someString);
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
    fgetc(stdin);
    if(userChoice < 'a' || userChoice > 'h') 
    {
        printf("Incorrect choice. Terminating program.\n");
        return 0;
    }
    printf("\n\n\n");
    
    
    
    switch(userChoice) {
        case'a': 
        {
            int rotation = 0;
            char string[1500];
            printf("Type a message.\n");
            fgets(string, 1500, stdin);
            printf("%s\n", string);
            printf("Choose a rotation key.\n");
            scanf("%d", &rotation);
            encryptRotation(string, rotation);
            printf("Your message encrypted: %s\n", string);
            break;
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
        
    
        case 'c':
        {
            char string[1500];
            int repetition = 1;
            int wordFound = 0;
            int i = 0;
            char letter1 = 0;
            char letter2 = 0;
            char letter3 = 0;
            char letter4 = 0;
            char letter5 = 0;
            char letter6 = 0;
            printf("Type a rotation cipher.\n");
            fgets(string, 1500, stdin);
            while(repetition < 26 && wordFound != 1)
            {
                
                rotateByOne(string);
                while(string[i] != '\0')
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
            char string[1500];
            char substitutions[26] = {'0'};
            int interfaceLetter = 'A';
            int i = 0;
            int letter = 'A';
            char indexMemory[1500];
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
    int i = 0;
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

}


void encryptRotation(char *someString, int someInteger) 
{
    int i = 0;
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
   
}




void decryptRotation(char *someString, int someInteger)
{
    int i = 0;
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
}
    

void putInSpaces(char *someString)
{
    int i = 0;
    while(someString[i] != '\0') 
    {
        if(someString[i] == '=') 
        {
            someString[i] = ' ';
        }
    i++;
    }

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







