import curses
from time import sleep

stdscr = curses.initscr()
curses.noecho()
curses.cbreak()
stdscr.keypad(True)

sleep(5)

curses.nocbreak()
stdscr.keypad(False)
curses.echo()
curses.endwin()
