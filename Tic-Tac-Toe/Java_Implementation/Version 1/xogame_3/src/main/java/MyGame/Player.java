package MyGame;

class Player {
    private String name;
    private char sign;
    private int score;

    Player(String name, char sign) {
        this.name = name;
        this.sign = sign;
        score = 0;
    }

    String getName() {
        return name;
    }

    int getScore() {
        return score;
    }

    char getSign() {
        return sign;
    }
    
    void increaseScore() {
        score++;
    }
    
    void showNameAndScore() {
        System.out.printf("%s's score is %d\n", name, score);
    }
}

