#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(/* args */) {}

BitcoinExchange::BitcoinExchange(const std::string &userInput) {
  initExchanger(userInput);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) { (void)rhs; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
  (void)rhs;
  return *this;
}

void BitcoinExchange::initExchanger(const std::string &userInput) {
  exchangeRateReader();
  inputParser(userInput);
}

void BitcoinExchange::exchangeRateReader() {
  std::string key;
  std::string value;

  std::ifstream is("data.csv");

  if (is.is_open() == false) exit(1);

  std::string inputBuffer;
  while (std::getline(is, inputBuffer)) {
    key = inputBuffer.substr(0, 10);
    value = inputBuffer.substr(10, inputBuffer.size() - 1);
    exchangeRate.insert(std::make_pair(key, value));
  }
  for (std::map<std::string, float>::const_iterator it = exchangeRate.begin();
       it != exchangeRate.end(); ++it)
  //      std::cout << it->first << " = " << it->second << "; ";
}

void BitcoinExchange::inputParser(const std::string &userInput) {
  (void)userInput;
}
// csv 읽어 들이고 -> 입력한 파일 유효성 검사(포맷, 파일 명) ->