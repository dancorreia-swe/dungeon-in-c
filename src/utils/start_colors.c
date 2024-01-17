#include <start_colors.h>

void start_colors()
{
  system("COLOR 0A");
  printf("\033[1;30m a"); // BLACK
  printf("\033[1;31m a"); // RED
  printf("\033[1;32m a"); // GREEN
  printf("\033[1;33m a"); // YELLOW
  printf("\033[1;34m a"); // BLUE
  printf("\033[1;35m a"); // PURPLE
  printf("\033[1;36m a"); // CYAN
  printf("\033[0;37m a"); // WHITE
  system("cls");
}