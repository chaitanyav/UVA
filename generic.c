#include <stdio.h>
#include <string.h>
#include <stdlib.h>


static int compare_int(const void *ptr1, const void *ptr2);
static int compare_char(const void *ptr1, const void *ptr2);
static int compare_strings(const void *ptr1, const void *ptr2);
void replace(void *arr, int element_size, int num_elements, int (*cmp)(const void *, const void *), void *find, void *replace);

void replace(void *arr, int element_size, int num_elements, int (*cmp)(const void *, const void *), void *find, void *replace) {
  int i;
  for(i = 0; i < num_elements; ++i) {
    void *element_addr = (char *)arr + (element_size * i);
    if(cmp(element_addr, find) == 0) {
      memcpy(element_addr, replace, element_size);
    }
  }
}

static int compare_int(const void *ptr1, const void *ptr2) {
  return *(int *)ptr1 - *(int *)ptr2;
}

static int compare_char(const void *ptr1, const void *ptr2) {
  return *(char *)ptr1 - *(char *)ptr2;
}

static int compare_strings(const void *ptr1, const void *ptr2) {
  return strcmp(*(char **)ptr1, *(char **)ptr2);
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int num_elems = sizeof(nums)/sizeof(nums[0]);
  int x = 4;
  int y = 0;
  int i;

  printf("\nBefore replacing %d with %d\n", x, y);
  for(i = 0; i < num_elems; ++i) {
    printf("%d ", nums[i]);
  }

  replace(nums, sizeof(nums[0]), num_elems, compare_int, &x, &y);
  printf("\nAfter replacing\n");
  for(i = 0; i < num_elems; ++i) {
    printf("%d ", nums[i]);
  }

  printf("\n");

  char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  char ch1 = 'b';
  char ch2 = 'g';
  num_elems = sizeof(chars)/sizeof(chars[0]);

  printf("\nBefore replacing %c with %c\n", ch1, ch2);
  for(i = 0; i < num_elems; ++i) {
    printf("%c ", chars[i]);
  }

  replace(chars, sizeof(chars[0]), num_elems, compare_char, &ch1, &ch2);
  printf("\nAfter replacing\n");
  for(i = 0; i < num_elems; ++i) {
    printf("%c ", chars[i]);
  }

  printf("\n");

  char *strings[] = {"abc", "def", "ghi", "jkl", "mno", "pqr"};
  char *str1 = "def";
  char *str2 = "stu";
  num_elems = (sizeof(strings)/ sizeof(strings[0]));

  printf("\nBefore replacing %s with %s\n", str1, str2);
  for(i = 0; i < num_elems; ++i) {
    printf("%s ", strings[i]);
  }

  replace(strings, sizeof(char *), num_elems, compare_strings, &str1, &str2);
  printf("\nAfter replacing\n");
  for(i = 0; i < num_elems; ++i) {
    printf("%s ", strings[i]);
  }

  printf("\n");

  exit(EXIT_SUCCESS);
}
