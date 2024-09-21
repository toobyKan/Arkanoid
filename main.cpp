#include "includes/Game.hpp"
#include "includes/Menu.hpp"

int main(){
    initscr();
    refresh();
    noecho();
    curs_set(0);

    const int BOARD_DIM = 40;
    const int BOARD_ROWS = BOARD_DIM;
    const int BOARD_COLS = BOARD_DIM * 2.5;
    const int BOARD_SPEED = 60;

    Game game(BOARD_ROWS, BOARD_COLS, BOARD_SPEED);
    Menu menu;

    while (!game.isOver()){
        if (game.getMenuMode()){
            menu.display();
            int choice = menu.getUserChoice();
            switch (choice){
            case KEY_UP:
            case KEY_DOWN:
                menu.handleArrowKey(choice);
                break;
            case 10: // Enter key
                if (menu.getSelectedIndex() == 0)
                {
                    game.menuToggle();
                    menu.clearMenu();
                    game.redraw_broder();
                }
                else if (menu.getSelectedIndex() == 1) {
                    game.endGame();
                }
            }
        }
        else{
            game.processInput();

            game.updateState();

            game.redraw();
        }
    }
    getch();
    endwin();

    return 0;
}