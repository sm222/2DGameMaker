/**
 * @file ReadfFile.hpp
 * @author your name
 * @brief 
 * @version 0.1
 * @date 2024-07-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef READFILE_HPP_
# define READFILE_HPP_

# include <string>
# include <iostream>
# include <fstream>
# include <exception>
# include <vector>
# include <cstring>

# include "lib.hpp"
# include "../../inc/CPPDefine.hpp"

class ReadFile {
  public:
    ReadFile(const char* FileName);
    ~ReadFile();
  private:
    bool  FindHeader(vector<string> file);
    void  ShowError(const string data, const size_t line, const size_t i,  bool start = true);
    int   ParseLine(const string s);
    //    |
    int               _Type;
    const string      _FileName;
    vector<string>    _FileData;
    size_t            _FileStart;
    unsigned short    _Depth;
    size_t            _line_err, _err_i;
};

#endif // READFILE_HPP_
