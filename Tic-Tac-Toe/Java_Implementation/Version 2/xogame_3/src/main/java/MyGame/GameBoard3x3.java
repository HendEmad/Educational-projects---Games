package MyGame;

class GameBoard3x3 extends GameBoard{
    GameBoard3x3() {
        board = new char[] {'0',
            '1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'
        };
        inputs = 0;
        size = 9;
    }
    
    @Override
    void draw() {
        System.out.printf("\t\t\t\t   %c  |  %c  |  %c\n", board[1], board[2], board[3]);
        System.out.printf("\t\t\t\t  ____| ____| ___\n");
        System.out.printf("\t\t\t\t   %c  |  %c  |  %c\n", board[4], board[5], board[6]);
        System.out.printf("\t\t\t\t  ____| ____| ___\n");
        System.out.printf("\t\t\t\t   %c  |  %c  |  %c\n", board[7], board[8], board[9]);
    }
    
    @Override
    void reset() {
        board = new char[] {'0',
            '1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'
        };
        inputs = 0;
    }

    @Override
    boolean isWin() {
        for(int i = 1; i <= 7; i+= 3){  // horizontal
            if(board[i] == board[i + 1] && board[i] == board[i + 2])
                return true;
        }
        
        for(int i = 1; i <= 3; i++) {  // vertical
            if(board[i] == board[i + 3] && board[i] == board[i + 6])
                return true;
        }
        
        return (board[1] == board[5] && board[1] == board[9] ||
                board[3] == board[5] && board[3] == board[7]);  // diagonal
    }
}