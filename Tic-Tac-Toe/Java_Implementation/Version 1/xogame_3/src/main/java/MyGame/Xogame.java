package MyGame;

import java.util.Scanner;

public class Xogame {
    Player player1, player2;
    GameBoard board = new GameBoard();
    Scanner cin = new Scanner(System.in);
    
    void setData() {
        String name;
        System.out.print("Please enter player's 1 name: ");
        name = cin.nextLine();
        
        System.out.print("Please choose (x or o): ");
        char sign = cin.next().charAt(0);
        cin.nextLine();
        
        while(!Validation.isValidSign(sign)) {
            System.out.println("Invalid sign!");
            
            System.out.print("Please choose (x or o): ");
            sign = cin.next().charAt(0);
            cin.nextLine();
        }
        
        player1 = new Player(name, Character.toUpperCase(sign));
        
        System.out.print("Please enter player's 2 name: ");
        name = cin.nextLine();
        
        sign = (player1.getSign() == 'X' ? 'O' : 'X');
        
        player2 = new Player(name, sign);
    }
    
    void turn(Player player) {
        System.out.printf("\n%s 's position is: ", player.getName());
        int position = cin.nextInt();
        
        while(!board.insert(player.getSign(), position)) {
            System.out.println("Please enter a valid posiiton!");
            System.out.printf("\n%s 's position is: ", player.getName());
            position = cin.nextInt();
        }
    }
    
    void basicGame() {
        while(true) {
            turn(player1);
            board.draw();
            
            if(board.isWin()) {
                System.out.printf("\n%s 's won!", player1.getName());
                player1.increaseScore();
                break;
            }
            
            if(board.isDraw()) {
                System.out.printf("Board is a draw, noone won!");
                break;
            }
            //------------------------------------------------------------------
            turn(player2);
            board.draw();
            
            if(board.isWin()) {
                System.out.printf("\n%s 's won!", player1.getName());
                player2.increaseScore();
                break;
            }
            
            if(board.isDraw()) {
                System.out.printf("Board is a draw, noone won!");
                break;
            }
        }
    }
    
    public void play() {
        board.reset();
//        setData();
        char samePlayers = 'n';
        char playAgain;
        
        do {
            
            if(Character.toLowerCase(samePlayers) != 'y') 
                setData();
            
            player1.showNameAndScore();
            player2.showNameAndScore();
            System.out.printf("-------------------------------------------------\n");
           
            board.reset();
            board.draw();
            basicGame();
            
            System.out.printf("Do you want to play again? (y, n)");
            playAgain = cin.next().charAt(0);
            cin.nextLine();
            
            if(Character.toLowerCase(playAgain) == 'y') {
                System.out.print("Same players (y/ n)?");
                samePlayers = cin.next().charAt(0);
                cin.nextLine();
            }
            
            if(Character.toLowerCase(playAgain) == 'y') {
                Player temp;
                temp = player1;
                player1 = player2;
                player2 = temp; 
            }
            
        }while(Character.toLowerCase(playAgain) == 'y');
        
        if(Character.toLowerCase(playAgain) == 'n') 
            System.out.println("Thank you for playing our game....");
        
        
    }
}
