package MyGame;

class Validation {
    static boolean isValidIndex(int index, int size) {
        return (index >= 1 && index <= size);
    }
    
    static boolean isValidSign(char sign) {
        return (Character.toLowerCase(sign) == 'x' ||
                Character.toLowerCase(sign) == 'o');
    }
}
