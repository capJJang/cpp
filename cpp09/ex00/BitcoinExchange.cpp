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

float BitcoinExchange::toFloat(std::string &userInput) {
  std::stringstream ss(userInput);
  float ret;

  std::cout << userInput << std::endl;
  ss >> ret;
  return ret;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
  int i = 0;

  if (date.length() != 10) return false;
  while (i < 4)
    if (std::isdigit(date[i++]) != false) return false;
  if (date[i++] != '-') return false;
  while (i < 7)
    if (std::isdigit(date[i++]) != false) return false;
  if (date[i++] != '-') return false;
  while (i < 10)
    if (std::isdigit(date[i++]) != false) return false;
}

bool BitcoinExchange::isValidValue(const std::string &value) {}

void BitcoinExchange::exchangeRateReader() {
  std::string key;
  std::string value;
  std::string inputBuffer;

  std::ifstream is("data.csv");

  if (is.is_open() == false) exit(1);

  while (std::getline(is, inputBuffer)) {
    key = inputBuffer.substr(0, 10);
    value = inputBuffer.substr(11, inputBuffer.size() - 1);
    if ((isValidDate(key) && isValidValue(value)) == false) exit(0);
    exchangeRate.insert(std::make_pair(key, toFloat(value)));
  }
  for (std::map<std::string, float>::const_iterator it = exchangeRate.begin();
       it != exchangeRate.end(); ++it)
    std::cout << it->first << " | " << it->second << std::endl;
}

void BitcoinExchange::inputParser(const std::string &userInput) {
  (void)userInput;
}
// csv 읽어 들이고 -> 입력한 파일 유효성 검사(포맷, 파일 명) ->