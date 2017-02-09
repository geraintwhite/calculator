void
split(char *str, char *delim, char ***res, int *num)
{
  char *token = strtok(str, delim);
  int i = 0;

  while (token != NULL)
  {
    *res = realloc(*res, sizeof(char*) * ++i);
    (*res)[i - 1] = token;

    token = strtok(NULL, delim);
  }

  *res = realloc(*res, sizeof(char*) * (i + 1));
  (*res)[i] = 0;

  *num = i;
}
