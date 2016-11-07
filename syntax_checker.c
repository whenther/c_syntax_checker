#include <stdio.h>
#define MAXLINE 1000 /* max input line size */

void process_lines();
void process_line(char *line);
void check_character(char c);
int is_in_quotes();
void maybe_close_current_quote(char c);
void close_quotes();
void error(char *error);

struct braces {
  int paren;
  int square;
  int curly;
  int doublequote;
  int singlequote;
};

struct braces brace_counts;
struct braces open_braces = {'(', '[', '{', '"', '\''};
struct braces close_braces = {')', ']', '}', '"', '\''};

/* print longest input line */
int main() {
  
}

void process_lines() {
  char line[MAXLINE];

  while (gets(line)) {
    process_line(line);
  }
}

void process_line(char *line) {
  char c;

  // Update braces for the line.
  while (*line) {
    check_character(*line);
    line++;
  }

  // If there are still open quotes,
  // you're gonna have a bad time.
  if (is_in_quotes()) {
    // TODO: include line numbers.
    error("Open quotes at the end of the line.");
    close_quotes();
  }
}

void check_character(char c) {
  if (is_in_quotes()) {
    maybe_close_current_quote(c);
  } else {
    
  }
}

int is_in_quotes() {
  return brace_counts.singlequote || brace_counts.doublequote;
}

void close_quotes() {
  brace_counts.singlequote = 0;
  brace_counts.doublequote = 0;
}

void maybe_close_current_quote(char c) {
  if (brace_counts.doublequote && c == close_braces.doublequote) {
    brace_counts.doublequote--;
  } if (brace_counts.singlequote && c == close_braces.singlequote) {
    brace_counts.singlequote--;
  }
}

void update_braces(char c) {
  
}

void error(char *e) {
  printf("%p", e);
}
