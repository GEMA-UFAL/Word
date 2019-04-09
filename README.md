# Word

## How to execute?
> g++ main.cpp -o main

> ./main

## Example of use

### 1. Auto-complete
    Input: 
            stop, stopping, stopped
  
    Query:             
            $$st
  
    Output: 
            An possible suffix: op
            An possible suffix: opping
            An possible suffix: opped
 
### 2. Find anything
  
    Input:       
          rodrigo paes likes to code
  
    Query:         
          ##o
  
    Outuput:   
           Present at word number: 1
           
           Present at word number: 4
           
           Present at word number: 5
           
    Query: 
          ##likes
  
    Outuput: 
          Present at word number: 3
  
  
### 3. Justify:
    Input: 
          Tushar Roy Likes To Code
    
    Query:
          @@10
    
    Outupt: 
          Tushar
          Roy Likes
          To Code
 
  
