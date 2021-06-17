#ifndef cstrcmpCPP
#define cstrcmpCPP

bool cstrcmp(const char  * c_str1,const char  * c_str2) {
  while (*c_str1 && * c_str2) {
    if (*c_str1 != *c_str2)
      return false;
    ++c_str1;
    ++c_str2;
  }
  if ( (!*c_str1 && *c_str2) || (*c_str1 && !*c_str2))
    return false;
  return true;
}

#endif
