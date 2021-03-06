/* Copyright (c) 2016 David Benoit
   ansi_colors.h
   
  Provide ansi escape sequences for colored terminal output
*/

#ifndef ANSI_COLORS_H
#define ANSI_COLORS_H

#define ANSI_BLACK "\033[0;30m"
#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_BROWN "\033[0;33m"
#define ANSI_BLUE "\033[0;34m"
#define ANSI_PURPLE "\033[0;35m"
#define ANSI_CYAN "\033[0;36m"
#define ANSI_LIGHT_GREY "\033[0;37m"

#define ANSI_DARK_GREY "\033[1;30m"
#define ANSI_LIGHT_RED "\033[1;31m"
#define ANSI_LIGHT_GREEN "\033[1;32m"
#define ANSI_YELLOW "\033[1;33m"
#define ANSI_LIGHT_BLUE "\033[1;34m"
#define ANSI_LIGHT_PURPLE "\033[1;35m"
#define ANSI_LIGHT_CYAN "\033[1;36m"
#define ANSI_WHITE "\033[1;37m"

#define DEBUG_CONSOLE_DEFAULT_COLOR ANSI_WHITE
#define DEBUG_CONSOLE_DEFAULT_COLOR_LIGHT ANSI_WHITE

#define DEBUG_CONSOLE_SUCCESS_COLOR ANSI_LIGHT_GREEN
#define DEBUG_CONSOLE_FAILURE_COLOR ANSI_LIGHT_RED
#define DEBUG_CONSOLE_WARNING_COLOR ANSI_YELLOW

#endif // ANSI_COLORS_H
