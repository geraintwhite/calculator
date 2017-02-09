char **
split(char *str, char *delim, int *num)
{
  char *token = strtok(str, delim);
  char **res = NULL;
  int i = 0;

  while (token != NULL)
  {
    res = realloc(res, sizeof(char*) * ++i);

    if (res == NULL)
    {
      exit(-1);
    }

    res[i - 1] = token;

    token = strtok(NULL, delim);
  }

  res = realloc(res, sizeof(char*) * (i + 1));
  res[i] = 0;

  *num = i;

  return res;
}
