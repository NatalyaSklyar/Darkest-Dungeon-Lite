//
// Created by Ivan Novikov on 08.03.2024.
//

#include "graphics.h"

Monitor::Monitor() {
    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
}
Monitor::~Monitor() {
    endwin();
}

void Monitor::draw_rectangle(int x1, int y1, int x2, int y2) {
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void Monitor::draw_hero_position(int x, int y) {
    mvaddch(y, x, '@');
}

void Monitor::make_an_event_loop() {
    int x = 0;
    int y = 0;
    int input_char = 0;

    do{
        clear();
        draw_rectangle(3, 3, 7, 7);
        draw_rectangle(25, 10, 30, 20);
        if(input_char == KEY_UP) y--;
        else if(input_char == KEY_DOWN) y++;
        else if(input_char == KEY_LEFT) x--;
        else if(input_char == KEY_RIGHT)x++;

        draw_hero_position(x, y);
    }while((input_char = getch()) != 27);
    getch();
    endwin();

    /*
    // инициализация (должна быть выполнена
    // перед использованием ncurses)
    initscr();
    // Измеряем размер экрана в рядах и колонках
    int row, col;
    getmaxyx(stdscr, row, col);
    // перемещение курсора в стандартном экране
    move(row / 2, col / 2 - 25);
    printw("Hello world"); // вывод строки
    refresh(); // обновить экран
    getch(); // ждём нажатия символа
    endwin(); // завершение работы с ncurses
    */
}