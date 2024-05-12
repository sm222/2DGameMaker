#include "tools.h"

static int  size_of_unb(unsigned long long nb, int base) {
  int  size;

  size = 0;
  while (nb) {
    size++;
    nb /= base;
  }
  return size;
}

char  *ft_ulltoa(unsigned long long nb, int base, char *out) {
  int  i;

  i = size_of_unb(nb, base);
  if (nb == 0)
    i++;
  out[i] = 0;
  while (i--) {
    out[i] = HEX_TABLE[nb % base];
    nb /= base;
  }
  return out;
}

static int  num_s(int n) {
  int  i;

  i = 1;
  if (n == -2147483648)
    return 11;
  else if (n < 0) {
    n = n * -1;
    i++;
  }
  while (n > 9) {
    n = n / 10;
    i++;
  }
  return i;
}

static void set_str(char *s, int i, int long n) {
  if (i > 0) {
    s[i] = n % 10 + '0';
    set_str(s, i - 1, n / 10);
  }
  else
    s[i] = n % 10 + '0';
}

static char	*ft_itoa(int n, char* buff) {
  long int  temp;

  temp = n;
  if (temp < 0)
    temp = temp * -1;
  set_str(buff, num_s(n) - 1, temp);
  if (n < 0)
    buff[0] = '-';
  return buff;
}


static void set_time_buff(char buff[TMP_BUFF_SIZE]) {
  time_t     rawtime;
  struct tm* timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  memcpy(buff, asctime(timeinfo) + 11, TMP_BUFF_SIZE - (22));
}

static int	print_select(va_list *list, char c, char *buff, char** ref, char* color)
{
  int     nb;
  char*   s;
  char*   testColor;

  *ref = NULL;
  bzero(buff,  TMP_BUFF_SIZE);
  bzero(color, TMP_BUFF_SIZE);
  testColor = strchr(colorName, c);
  if (c == 's')
  {
    s = va_arg(*list, char *);
    if (!s) {
      memcpy(buff, "(null)", 7);
      return 6;
    }
    *ref = s;
    return (strlen(s));
  }
  else if (c == 'i' || c == 'd') {
    nb = va_arg(*list, int);
    ft_itoa(nb, buff);
		return (strlen(buff));
  }
  else if (c == 'c') {
    nb = (va_arg(*list, int));
    buff[0] = nb;
    buff[1] = 0;
    return 1;
  }
  else if (c == 'p') {
    ft_ulltoa(va_arg(*list, unsigned long), 16, buff + 2);
    memcpy(buff, "0x", 2);
    return (strlen(buff));
  }
  else if (c == '%') {
    memcpy(buff, "%", 2);
    return 1;
  }
  else if (c == 'x') {
    ft_ulltoa(va_arg(*list, unsigned long), 16, buff);
    return (strlen(buff));
  }
  else if (c == 'u') {
    ft_ulltoa(va_arg(*list, unsigned long), 10, buff);
    return (strlen(buff));
  }
  else if (testColor) {
    size_t tmp = (colorName - testColor) *-1;
    memcpy(color, colorList[tmp], strlen(colorList[tmp]) + 1);
  }
  else if (c == 'F') {
    s = va_arg(*list, char *);
    if (!s) {
      return 0;
    }
    *ref = s;
  }
  else if (c == 'T') {
    set_time_buff(buff);
    return (strlen(buff));
  }
  return 0;
}


static short add_buff(char* arg, t_buff* buff) {
  if (!buff->str) {
    buff->str = calloc(SIZE_BUFF + 1, sizeof(char));
    if (!buff->str)
      return 1;
    buff->len = SIZE_BUFF;
  }
  ssize_t sLen = strlen(arg);
  while (buff->dest > buff->len / 2 || sLen + buff->dest > buff->len / 2) {
    buff->str = realloc(buff->str, buff->len * BUFF_MUL);
    if (!buff->str)
      return 1;
    buff->len *= BUFF_MUL;
  }
  memmove(buff->str + buff->dest, arg, sLen);
  buff->dest += sLen;
  return 0;
}


static ssize_t calculate_size(const char* s, va_list* list, t_buff out[2]) {
  ssize_t   i = 0, j = 0;
  char      buff[TMP_BUFF_SIZE], color[TMP_BUFF_SIZE];
  t_buff    file;
  char*     str = NULL;
  short     err = 0;

  if (!s)
    return -1;
  bzero(&file, sizeof(file));
  while (s[i]) {
    if (s[i] != '%') {
      buff[0] = s[i];
      buff[1] = 0;
      err += add_buff(buff, &out[0]);
      err += add_buff(buff, &out[1]);
      j++;
    }
    else {
      j += print_select(list, s[++i], buff, &str, color);
      if (str && s[i] != 'F') {
        err += add_buff(str, &out[0]);
        err += add_buff(str, &out[1]);
        str = NULL;
      }
      else if (color[0])
        err += add_buff(color, &out[0]);
      else if (str) {
        out[1].outfile = str;
      }
      else {
        err += add_buff(buff, &out[0]);
        err += add_buff(buff, &out[1]);
      }
    }
    i++;
    if (err)
      return -1;
  }
  return j;
}


/// @brief 
/// @param s 
/// @param  
/// @return raw size of text with no color or flag init
ssize_t debug_info(const char* s, ...) {
  va_list   args;
  ssize_t   i = 0;
  t_buff    buff[2];

  if (!s)
    return -1;
  bzero(buff, sizeof(buff));
  va_start(args, s);
  if (DEBUG_FLAG > 0) {
    i = calculate_size(s, &args, buff);
    if (i != -1 && DEBUG_FLAG & DflagOut)
      write(STDERR_FILENO, buff[0].str, strlen(buff[0].str));
    if (i != -1 && DEBUG_FLAG & DflagLog) {
      if (buff[1].outfile) {
        int fd = open(buff[1].outfile, O_CREAT | O_APPEND | O_RDWR, 0644);
        if (fd > -1) {
          write(fd, buff[1].str, strlen(buff[1].str));
          close(fd);
        }
        else
          perror(buff[1].outfile);
      }
      else
        write(STDERR_FILENO, "no file give to output\n", 23);
    }
    if (i == -1)
      perror("calculate_size");
    free(buff[0].str);
    free(buff[1].str);
  }
  va_end(args);
  return i;
}


int main(void) {
	char* test = "a b c";

	int n1  =     printf("test %s, %d%% %p %x %% %o", test, 421, &main, 54635, 0);
	int n2  =  debug_info("[%C%T%r]test %s, %Y%d%%%r %p %B%x%r %% %o%F\n", test, 421, &main, 54635, "OUT");
	printf("\n%d | %d\n", n1, n2);
}

