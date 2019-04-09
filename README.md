# Word

## How to execute?
> g++ main.cpp -o main

> ./main

## Example of use

Type your text and interrupt it by some given option below.

> Um dois tres quatro $$ st cinco seis ## o sete oito @@ 10 

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
 
  
