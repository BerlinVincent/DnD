#include <ncurses.h>
#include <string>
#include <vector>

int main () {
    initscr();
    noecho();
    curs_set(TRUE);
    keypad(stdscr, TRUE);

    std::vector<std::string> options = {
        "1 - Foo",
        "2 - Bar",
        "3 - Exit"
    };

    size_t highlight = 0;
    int input;

    while (true) {
        clear();
        mvprintw(0, 0, "Welcome to the Test Menu!");
        mvprintw(1, 0, "Use ↑ ↓ to navigate, Enter to select");

        for (size_t i = 0; i < options.size(); i++) {
            if (i == highlight) attron(A_REVERSE);
            mvprintw(i + 2, 2, "%s", options[i].c_str());
            if (i == highlight) attroff(A_REVERSE);
        }

        input = getch();

        switch (input) {
            case KEY_UP:
                highlight = (highlight - 1 + options.size()) % options.size();
                break;
            case KEY_DOWN:
                highlight = (highlight + 1) % options.size();
                break;
            case 10:
                if (options[highlight] == "3 - Exit") {
                    endwin();
                    return 0;
                } else {
                    clear();
                    mvprintw(5, 5, "%s", ("You selected: " + options[highlight]).c_str());
                    mvprintw(7, 5, "Press any key to return to menu...");
                    getch();
                }
                break;
        }
    }
    endwin();
    return 0;
}