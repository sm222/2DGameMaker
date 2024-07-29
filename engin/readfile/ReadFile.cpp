/**
 * @file ReadFile.cpp
 * @author your name 
 * @brief 
 * @version 0.1
 * @date 2024-07-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "ReadFile.hpp"



ReadFile::ReadFile(const char* FileName) :
_Type(0), _FileName(FileName ? FileName : "") {
  if (!_FileName.length())
    throw std::runtime_error("no file name give");
  //
  std::ifstream File;
  File.open(_FileName.c_str());
  if (!File.is_open()) {
    throw std::runtime_error("can't open file: " + _FileName);
  }
  string str;
  while (getline(File, str)) {
    if (!str.empty()) {
      std::cout << str << std::endl;
      _FileData.push_back(str);
    }
  }
  File.close();
  if (!FindHeader(_FileData)) {
    ShowError(_FileData, 2, 2);
    throw std::invalid_argument("invalid header");
  }
}

static bool strIsSpace(string& s) {
  for (size_t i = 0; i < s.length(); i++) {
    if (!isspace(s[i]))
      return false;
  }
  return true;
}

static size_t findLenWord(const char* s, size_t len) {
  size_t i = 0;
  while (i < len) {
    if (!isspace(s[i]))
      i++;
    else
      break ;
  }
  return i;
}

bool  ReadFile::FindHeader(vector<string> file) {
  size_t  line = 0;
  size_t i = 0;
  while (line < file.size() && (file[line].empty() || strIsSpace(file[line]))) {line++;}
  while (isspace(file[line][i])) {i++;}
  const size_t len = findLenWord(file[line].c_str() + i, file[line].length() - i);
  const size_t len2 = strlen(FILE_HEAD);
  if (len == len2 && strncmp(file[line].c_str() + i, FILE_HEAD, len2) == 0) {
    _Type = 1;
    _FileStart = line  + 1;
    return true;
  }
  return false;
}

void  ReadFile::ShowError(vector<string> data, const size_t line, const size_t i) {
  string err(G_RED G_BOLD);
  for (size_t j = 0; j < i; j++) {
    err += ' ';
  }
  size_t len = findLenWord(data[line].c_str() + i, data[line].length());
  err += '^';
  for (size_t j = 0; j < len - 1; j++) {
    err += '~';
  }
  
  err += G_RESET;
  std::cout << err << std::endl;
  (void)data;
  (void)line;
  (void)i;
}

ReadFile::~ReadFile() {
  for (size_t i = 0; i < _FileData.size(); i++) {
    _FileData[i].clear();
  }
  _FileData.clear();
}