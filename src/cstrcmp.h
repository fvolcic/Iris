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
 * @brief Compare two char arrays
 * 
 * @note Do not need to be '\0' terminated, but their length must be known prior to
 *       using this function.
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
