# Push Swap (121/100)

Push Swap is an algorithmic project that involves sorting a stack of integers using a limited set of operations. The goal is to sort the stack using the minimum number of moves possible.

## Features
- **Sorting Algorithms**: Implements the Turk algorithm, optimizing for a low number of moves.
- **Limited Operations**: Includes `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- **Bonus**:
  - **Checker**: Validates whether a stack is sorted.
  
## How It Works
- The stack of integers is sorted by pushing and rotating elements using a defined set of operations.
- The checker verifies if the stack is sorted and provides feedback. However, it mistakenly considers an empty stack as sorted, which is the reason the project doesn't achieve the full score of 125.

## Usage
1. Compile the program:
   ```make``` and 
   ```make bonus```
3. To sort a stack:
   ```./push_swap <list_of_numbers>```
4. To check if a stack is sorted:
   ```./checker <list_of_numbers>```
5. To check if the Algorithm have sorted the stack:
   ```ARG="list_of_numbers"; ./push_swap $ARG | ./checker $ARG```
