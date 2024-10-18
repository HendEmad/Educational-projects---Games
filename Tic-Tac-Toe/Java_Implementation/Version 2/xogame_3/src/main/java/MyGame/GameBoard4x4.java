package MyGame;

class GameBoard4x4 extends GameBoard {

    GameBoard4x4(){
        board = new char[]{' ',
                ' ', ' ', ' ',' ',
                ' ', ' ', ' ',' ',
                ' ', ' ', ' ',' ',
                ' ', ' ', ' ',' '
        };

        inputs = 0;
        size = 16;
    }

    @Override
    void reset(){
        board = new char[]{' ',
                ' ', ' ', ' ',' ',
                ' ', ' ', ' ',' ',
                ' ', ' ', ' ',' ',
                ' ', ' ', ' ',' '
        };

        inputs = 0;
    }
    
    @Override
    void draw(){
        System.out.printf("\t\t\t\t %c  |   %c   |  %c   |  %c\n", board[1], board[2], board[3], board[4]);
        System.out.println("\t\t\t\t____|_______|______|_____");
        System.out.printf("\t\t\t\t %c  |   %c   |  %c   |  %c\n", board[5], board[6], board[7], board[8]);
        System.out.println("\t\t\t\t____|_______|______|_____");
        System.out.printf("\t\t\t\t %c  |   %c   |  %c   |  %c\n", board[9], board[10], board[11], board[12]);
        System.out.println("\t\t\t\t____|_______|______|_____");
        System.out.printf("\t\t\t\t %c  |   %c   |  %c   |  %c\n", board[13], board[14], board[15], board[16]);
    }
    
    @Override
    boolean isWin(){
        for(int i = 1; i <= 13; i+= 4) {  // Horizontaly
            if(isBusy(i) && board[i] == board[i+1] && board[i] == board[i+2] && 
               board[i] == board[i+3] && board[i] == board[i+4])
                return true;
        }
        
        for(int i = 1; i <= 4; i++) { // vertically
            if(isBusy(i) && board[i] == board[i + 4] && board[i] == board[i + 8] 
               && board[i] == board[i + 12])
                return true;
        }
        
        return (isBusy(1) && isBusy(6) && isBusy(11) && isBusy(16) &&board[1] == board[6] && board[1] == board[11] && board[1] == board[16] ||
                isBusy(4) && isBusy(7) && isBusy(10) && isBusy(13) && board[4] == board[7] && board[4] == board[10] && board[4] == board[13]);
        
    }
}