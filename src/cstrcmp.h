#ifndef CSTRCMP_H
#define CSTRCMP_H

/**
 * @brief Compare '\0' terminated c-strings. 
 * 
 * @param c_str1 
 * @param c_str2 
 * @return true 
 * @return false 
 */
bool cstrcmp(const char * c_str1, const char * c_str2);

/**
 * @brief Compare two strings, do not need to be terminated with '\0' 
 * 
 * @param c_str1 
 * @param c_str1_len 
 * @param c_str2 
 * @param c_str2_len 
 * @return true 
 * @return false 
 */
bool cstrcmp(const char * c_str1, unsigned int c_str1_len, const char * c_str2, unsigned int c_str2_len);

#endif
