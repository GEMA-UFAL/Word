# Word

## How to execute?
> g++ main.cpp -o main

> ./main

## Example of use

Type your text and interrupt it by some given option below.
Running example:

    Um Um UM UM     
    $$ Um

    $$ U
    A possible suffix: "M" (UM).
    A possible suffix: "m" (Um).

    Dois dois dois dois
    @@ 10
    Um Um UM
    UM Dois
    dois dois
    dois

    ## is
    Present at word number 5.
    Present at word number 6.
    Present at word number 7.
    Present at word number 8.
    
    @@ 100000
    Um Um UM UM Dois dois dois dois
   
    Tres tres tres
    @@ 100000
    Um Um UM UM Dois dois dois dois Tres tres tres
    
    END  

### 1. Auto-complete ( $$ + query )
    Input: 
            stop stopping stopped
  
    Query:             
            $$ st
  
    Output: 
            A possible suffix: op (stop).
            A possible suffix: opping (stopping).
            A possible suffix: opped (stopped).
 
### 2. Find anything ( ## + query )
  
    Input:       
          rodrigo paes likes to code
  
    Query:         
          ## o
  
    Output:   
           Present at word number 1.         
           Present at word number 4.      
           Present at word number 5.
           
    Query: 
          ## likes
  
    Output: 
          Present at word number 3.
  
  
### 3. Justify ( @@ + width )
    Input: 
          Tushar Roy Likes To Code
    
    Query:
          @@ 10
    
    Output: 
          Tushar
          Roy Likes
          To Code
 
  
