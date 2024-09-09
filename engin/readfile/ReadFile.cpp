/**
 * @file ReadFile.cpp
 * @author Sm222
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
      _FileData.push_back(str);
    }
  }
  File.close();
  if (!FindHeader(_FileData)) {
    ShowError(_FileData[_line_err], _line_err, _err_i);
    throw std::invalid_argument("invalid header");
  }
}

static bool strIsSpace(const string& s) {
  for (size_t i = 0; i < s.length(); i++) {
    if (!isspace(s[i]))
      return false;
  }
  return true;
}

static size_t findLenWord(const char* s, size_t len) {
  size_t i = 0;
  while (i < len) {
    if (!isspace(s[i]) && s[i] != NEWLINE)
      i++;
    else {
      break ;
    }
  }
  return i;
}

bool  ReadFile::FindHeader(const vector<string> file) {
  size_t line = 0;
  size_t i = 0;
  while (line < file.size() && (file[line].empty() || strIsSpace(file[line]))) {line++;} // skip empty
  while (isspace(file[line][i])) {i++;}
  const size_t Linelen = file[line].length();
  const size_t len = findLenWord(file[line].c_str() + i, Linelen - i);
  const size_t HeaderLen = strlen(FILE_HEAD);
  if (len == HeaderLen && strncmp(file[line].c_str() + i, FILE_HEAD, HeaderLen) == 0) {
    _Type = 1;
    _FileStart = line + 1;
    i += HeaderLen;
    _Depth++;
    while (i < Linelen && isspace(file[line][i])) { i++; }
    if (i != Linelen && file[line][i] == IN__)
      return true;
  }
  _line_err = line;
  _err_i = i;
  return false;
}

void  ReadFile::ShowError(const string data, const size_t line, const size_t i, bool start) {
  string err(G_RED G_BOLD);
  for (size_t j = 0; j < i; j++) { err += ' '; }
  size_t len = findLenWord(data.c_str() + i, data.length() - i);
  if (start)
    err += '^';
  for (size_t j = 0; j < len - 1; j++) { err += '~'; } // ~ add line
  if (!start)
    err += '^';
  err += G_RESET;
  std::cout << _FileName << ":" << line + 1 << \
  ":" << _err_i + 1 << std::endl << data << \
  std::endl << err << std::endl;
}

int ReadFile::ParseLine(const string s) {
  size_t  i = 0;
  if (strIsSpace(s))
    return 0;
  const size_t len = s.length();
  while (i < len && isspace(s[i])) { i++; }
  if (i == len)
    return -1;
  return 0;
}

ReadFile::~ReadFile() {
  for (size_t i = 0; i < _FileData.size(); i++) {
    _FileData[i].clear();
  }
  _FileData.clear();
}