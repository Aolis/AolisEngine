#ifndef AOLIS_LOG_H
#define AOLIS_LOG_H

#include <string>


extern void log(const std::string msg);

extern void log(const unsigned int level, const std::string msg);


#endif /* AOLIS_LOG_H */
