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

bool cstrcmp(const char * c_str1, unsigned int c_str1_len, const char * c_str2, unsigned int c_str2_len){
  if(c_str1_len != c_str2_len)
    return false; 
  for(unsigned int i = 0; i < c_str1_len; ++i){
    if(c_str1[i] != c_str2[i])
      return false; 
  }
  return true; 
}

#endif
