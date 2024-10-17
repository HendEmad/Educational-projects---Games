package MyGame;

class GameBoard {
    private char[] board;
    private int inputs;
    
    GameBoard() {
        board = new char[] {'0',
            '1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'
        };
        inputs = 0;
    }
    
    int getInputs() {
        return inputs;
    }
    
    void draw() {
        System.out.printf("\t\t\t\t   %c  |  %c  |  %c\n", board[1], board[2], board[3]);
        System.out.printf("\t\t\t\t  ____| ____| ___\n");
        System.out.printf("\t\t\t\t   %c  |  %c  |  %c\n", board[4], board[5], board[6]);
        System.out.printf("\t\t\t\t  ____| ____| ___\n");
        System.out.printf("\t\t\t\t   %c  |  %c  |  %c\n", board[7], board[8], board[9]);
    }
    
    void reset() {
        board = new char[] {'0',
            '1', '2', '3',
            '4', '5', '6',
            '7', '8', '9'
        };
        inputs = 0;
    }
    
    boolean isBusy(int index) {
        if(!Validation.isValidIndex(index)) {
            // invalid index
            return true;
        }
        return (Character.toLowerCase(board[index]) == 'x' ||
                Character.toLowerCase(board[index]) == 'o');
    }
    
    boolean insert(char sign, int index) {
        if(!isBusy(index) && Validation.isValidSign(sign)) {
            board[index] = sign;
            inputs++;
            return true;
        }
        return false;
    }
    
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
    
    boolean isFull() {
        return (inputs == 9);
    }
    
    boolean isDraw() {
        return (isFull() && !isWin());
    }
}