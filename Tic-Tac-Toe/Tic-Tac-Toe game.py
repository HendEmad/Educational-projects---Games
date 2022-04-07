# importing the random module to call the randint() function.
import random

# Displaying the board
def Board(board):
    print('   |   |')
    print(' ' + board[7] + ' | ' + board[8] + ' | ' + board[9])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[4] + ' | ' + board[5] + ' | ' + board[6])
    print('   |   |')
    print('-----------')
    print('   |   |')
    print(' ' + board[1] + ' | ' + board[2] + ' | ' + board[3])
    print('   |   |')

# Getting the player letter(x || o)
# This function returns a list with the player's letter as the first element, and the computer's letter as the second one
def Player_Letter():
    letter = ''
    while not (letter == 'X' or letter == 'O'):
        print('Choose your desired letter (X or O ?)')
        letter = input().upper()

    # the first element is the player's letter, the second is the computer's letter.
    if letter == 'X':
        return ['X', 'O']
    else:
        return ['O', 'X']

# Deciding who will start the game randomly
def who_is_First():
    if random.randint(0, 1) == 0:
        return 'computer'
    else:
        return 'player'

# Asking the player wheter he want to play again or not
# This function returns True if the player wants to play again, otherwise it returns False
def play_Again():
    print('Do you want to play again? (yes or no)')
    # the input may be 'yes', 'Yes', 'YES', 'Y', 'y', 'Yup', etc...
    return input().lower().startswith('y')

#Making move on the board
# The inputs are: the list of the board ->board, the player's letter(x or o) ->letter, the place(index)where the player want to play ->move
def make_Move(board, letter, move):
    board[move] = letter
    
# Checking if the player won
def Winner(board, letter):
    # Given a board and a player's letter, this function returns True if that player has won.
    return ((board[7] == letter and board[8] == letter and board[9] == letter) or # across the top
    (board[4] == letter and board[5] == letter and board[6] == letter) or # across the middle
    (board[1] == letter and board[2] == letter and board[3] == letter) or # across the bottom
    (board[7] == letter and board[4] == letter and board[1] == letter) or # down the left side
    (board[8] == letter and board[5] == letter and board[2] == letter) or # down the middle
    (board[9] == letter and board[6] == letter and board[3] == letter) or # down the right side
    (board[7] == letter and board[5] == letter and board[3] == letter) or # diagonal
    (board[9] == letter and board[5] == letter and board[1] == letter)) # diagonal

# Duplicating the Board elements
# This function creats a copy of the original function (Board) and returns a reference to this new board(duplicatedBoard), not to the original one(Board)
def getBoardCopy(board):
    duplicatedBoard = []

    for i in board:
        duplicatedBoard.append(i)

    return duplicatedBoard


#Checking if the desired space(index) is free
# Return true if the passed move is free on the passed board.
#note -->  free spaces on the board lists are marked as a single space string. 
def is_Space_Free(board, move):
    return board[move] == ' '

# Getting player's move
# This function makes sure that the player will choose space within the board whose status is free
def Player_Move(board):
    move = ' '
    while move not in '1 2 3 4 5 6 7 8 9'.split() or not is_Space_Free(board, int(move)):
        print('What is your next move? (1-9)')
        move = input()
    return int(move)

def choose_Random_Move(board, movesList):
  possibleMoves = []
  for i in movesList:
    if is_Space_Free(board, i):
      possibleMoves.append(i)
  if len(possibleMoves) != 0:
    return random.choice(possibleMoves)
  else:
    return None

'''
Tic Tac Toe computer working:

· First, see if there’s a move the computer can make that will win the game. If there is, take that move. Otherwise, go to the second step.

· Second, see if there’s a move the player can make that will cause the computer to lose the game.
  If there is, the computer should move there to block the player. Otherwise, go to the third step.

· Third, check if any of the corner spaces (spaces 1, 3, 7, or 9) are free. If no corner space is free, then go to the fourth step.

· Fourth, check if the center is free. If so, move there. If it isn’t, then go to the fifth step.

· Fifth, move on any of the side pieces (spaces 2, 4, 6, or 8). There are no more steps; because if the execution has reached this step then the side spaces are the only spaces left.
'''

# Creating computer letter
def Computer_Move(board, computerLetter):
  if computerLetter == 'X':
    playerLetter = 'O'
  else:
    playerLetter = 'X'

# The Computer Checks if it Can Win in One Move
    for i in range(1, 10):
        copy = getBoardCopy(board)
        if is_Space_Free(copy, i):
            make_Move(copy, computerLetter, i)
            if Winner(copy, computerLetter):
                return i

'''
More than anything, if the computer can win in the next move, the computer should make that winning move immediately.
The for loop that starts iterates over every possible move from 1 to 9. The code inside the loop will simulate what would happen if the computer made that move.

The first line in the loop makes a copy of the board list. This is so the simulated move inside the loop doesn’t modify the real board stored in the board variable.
The getBoardCopy() returns an identical but separate board list value.

then, the next if condition checks if the space is free and if so, simulates making the move on the copy of the board.
If this move results in the computer winning, the function returns that move’s integer.

If none of the spaces results in winning, the loop will finally end and the program execution continues .
'''

def getComputerMove(board, computerLetter):
    # Given a board and the computer's letter, determine where to move and return that move.
    if computerLetter == 'X':
        playerLetter = 'O'
    else:
        playerLetter = 'X'

    # First, check if we can win in the next move
    for i in range(1, 10):
        copy = getBoardCopy(board)
        if is_Space_Free(copy, i):
            make_Move(copy, computerLetter, i)
            if Winner(copy, computerLetter):
                return i

    # Check if the player could win on his next move, and block them.
    for i in range(1, 10):
        copy = getBoardCopy(board)
        if is_Space_Free(copy, i):
            make_Move(copy, playerLetter, i)
            if Winner(copy, playerLetter):
                return i
            
    # Checking the Corner, Center, and Side Spaces (in that Order)
    # 1-check if the computer can take one of the corners, if they are free.
    move = choose_Random_Move(board, [1, 3, 7, 9])
    if move != None:
      return move

    # 2-check if the computer can take the center, if it is free.
    if is_Space_Free(board, 5):
      return 5

    # 3- Move on one of the sides.
    return choose_Random_Move(board, [2, 4, 6, 8])

# Checking if the board is full
# This function returns True if every space on the board has been taken. Otherwise return False.
def is_Board_Full(board):
    for i in range(1, 10):
        if is_Space_Free(board, i):
            return False
    return True

# The Start of the Game
print('Welcome to Tic Tac Toe!')

while True:
    # Reset the board
    theBoard = [' '] * 10
    playerLetter, computerLetter = Player_Letter()
    turn = who_is_First()
    print('The ' + turn + ' will go first.')
    gameIsPlaying = True

    while gameIsPlaying:
        if turn == 'player':
            # Player's turn.
            Board(theBoard)
            move = Player_Move(theBoard)
            make_Move(theBoard, playerLetter, move)

            if Winner(theBoard, playerLetter):
                Board(theBoard)
                print('Hooray! You have won the game!')
                gameIsPlaying = False
            else:
                if is_Board_Full(theBoard):
                    Board(theBoard)
                    print('The game is a tie!')
                    break
                else:
                    turn = 'computer'

        else:
            # Computer's turn.
            move = getComputerMove(theBoard, computerLetter)
            make_Move(theBoard, computerLetter, move)

            if Winner(theBoard, computerLetter):
                Board(theBoard)
                print('The computer has beaten you! You lose.')
                gameIsPlaying = False
            else:
                if is_Board_Full(theBoard):
                    Board(theBoard)
                    print('The game is a tie!')
                    break
                else:
                    turn = 'player'

    if not play_Again():
        break
