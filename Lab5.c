/*
 * File name:           Lab5.c
 * Author:              Prarthona Paul 
 * Date:                Feb 22, 2021
 * Description:         This program takes the dimension input from the user between 0 and 13 and
 *                      creates a pascals triangle based on that. 
 */
 
 #include <stdio.h>
 void triangle (int);
 int choose (int, int);
 int factorial(int);

int main(int argc, char **argv)
{
    int input;  //Stores the input value of the rows. 
    
    printf("Enter the number of rows: ");
    scanf("%d", &input);
    
    while(input >= 0 && input <=13)         //While loop to keep prompting the user as long as input in valid
    {
        triangle(input);                    //Calls void function that created the triangle
        printf("Enter the number of rows: ");   //asks for new values
        scanf("%d", &input);
    }
    
	return 0;
}

//This function takes the value sent to the function and calculates the factorial of that number
int factorial(int n)
{
    int fact = 1;
    
    for(int i = 1; i <= n; i++)     //For loop to calculate the factorial of sent value. 
        fact *= i;      
    return fact;                    //Returns the factorual 
}

//This function chooses the number of value that goes in the triangle
int choose(int n, int r)
{
    int nCr;        //holds the entries of the triangle. Calculated based on n and r sent to the function. 
    
    nCr = (factorial(n) / (factorial(r) * factorial(n-r)));     //Calculates the value that goes to the traingle bases on formula
    return nCr;
}

//This function creates the pascal's triangle 
void triangle(int n)    //n is value entered by user
{
    for(int row = 0; row < n; row++)                //Outer for loop to control the rows
    {
        int r = row+1;      //r represents the r value in the pascal's triangle equation
        
        for(int col = 0; col < 2*(n); col++)     //Inner for loop to control the columns 
        {
            if(col >= (n - row) && col <= (n + row))   //Determines the edges of the triangle
            {
                if((row+col)%2 == n % 2)                //Determines which positions of the triangle has number
                {
                    r--;                                
                    printf("%d", choose(row, r));       //row and r sent to nCr formula, choose function calculates value
                    
                    if (r > 0)
                    {   //These statements determine spacing between values
                        if(choose(row, r) < 10)
                            printf("     ");
                        else if(choose(row, r) > 9 && choose(row, r) < 100)
                            printf("    ");
                        else
                            printf("   ");
                    }
                    else if(r == 0) //determines spacing to the right of triangle
                        printf("     ");
                }
            }
            else if(col > 0 && r > 0)  //determines spacing to the left of triangle                      
                printf("   ");
    
        }                           //End inner for loop
        printf("\n");               //Newline added to start a new row
    }   //End of outer loop      
}
