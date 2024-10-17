package MyGame;

class Validation {
    static boolean isValidIndex(int index) {
        return (index >= 1 && index <= 9);
    }
    
    static boolean isValidSign(char sign) {
        return (Character.toLowerCase(sign) == 'x' ||
                Character.toLowerCase(sign) == 'o');
    }
}
