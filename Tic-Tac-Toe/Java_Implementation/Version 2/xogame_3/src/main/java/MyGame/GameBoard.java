package MyGame;

abstract class GameBoard {
    protected char[] board;
    protected int inputs;
    protected int size;
    
    int getInputs() {
        return inputs;
    }
    
    abstract void draw();
    abstract void reset();
    abstract boolean isWin();
    
    boolean isBusy(int index) {
        if(!Validation.isValidIndex(index, size)) {
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
    
    boolean isFull() {
        return (inputs == size);
    }
    
    boolean isDraw() {
        return (isFull() && !isWin());
    }
}