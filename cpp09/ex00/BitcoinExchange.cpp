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

  ss >> ret;
  return ret;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
  if (date.length() != 10) return false;

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) return false;

  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    return false;
  if (month == 2) {
    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) return false;
  }

  return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) {
  std::stringstream ss(value);
  float floatValue;

  ss >> floatValue;
  return !ss.fail();
}

void BitcoinExchange::exchangeRateReader() {
  std::string key;
  std::string value;
  std::string inputBuffer;

  std::ifstream is("data.csv");

  if (is.is_open() == false) {
    std::cerr << "Data file open failed" << std::endl;
    exit(1);
  }

  std::getline(is, inputBuffer);
  if (inputBuffer != "date,exchange_rate") {
    std::cerr << "File corrupted." << std::endl;
    exit(1);
  }
  while (std::getline(is, inputBuffer)) {
    key = inputBuffer.substr(0, 10);
    value = inputBuffer.substr(11, inputBuffer.size() - 1);
    if ((isValidDate(key) && isValidValue(value)) == false) {
      std::cerr << "File corrupted." << std::endl;
      exit(1);
    }
    exchangeRate.insert(std::make_pair(key, toFloat(value)));
  }
  // for (std::map<std::string, float>::const_iterator it =
  // exchangeRate.begin();
  //      it != exchangeRate.end(); ++it)
  //   std::cout << it->first << " | " << it->second << std::endl;
}

void BitcoinExchange::inputParser(const std::string &userInput) {
  std::string key;
  std::string value;
  std::string delimeter;
  std::string inputBuffer;

  std::ifstream is(userInput);
  if (is.is_open() == false) {
    std::cerr << userInput << " open failed" << std::endl;
    exit(1);
  }
  std::getline(is, inputBuffer);
  if (inputBuffer != "date | value") {
    std::cerr << "File corrupted." << std::endl;
    exit(1);
  }
  while (std::getline(is, inputBuffer)) {
    key = inputBuffer.substr(0, 10);
    value = inputBuffer.substr(13, inputBuffer.size() - 1);
    delimeter = inputBuffer.substr(10, 3);
    std::cout << delimeter << std::endl;
    if ((isValidDate(key) && isValidValue(value)) == false) {
      std::cerr << "File corrupted." << std::endl;
      exit(1);
    }
    exchangeRate.insert(std::make_pair(key, toFloat(value)));
  }
}
// csv 읽어 들이고 -> 입력한 파일 유효성 검사(포맷, 파일 명) ->