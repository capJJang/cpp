#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#define NEGATIVE_VALUE -1
#define NUMBER_TOO_LARGE -2
#define BAD_INPUT -3

class BitcoinExchange {
 private:
  std::map<std::string, float> exchangeRate;
  std::multimap<std::string, float> input;

  BitcoinExchange(/* args */);
  BitcoinExchange(const BitcoinExchange &rhs);
  BitcoinExchange &operator=(const BitcoinExchange &rhs);

  void initExchanger(const std::string &userInput);
  // void extract(const std::string &src, std::string &dest, const char *c);
  bool isValidDate(const std::string &date);
  float isValidValue(const float value);
  float toFloat(std::string &userInput);
  void exchangeRateReader();
  void inputParser(const std::string &userInput);
  void printRate();

 public:
  BitcoinExchange(const std::string &userInput);
  ~BitcoinExchange();
};

#endif