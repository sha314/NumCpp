//
// Created by shahnoor on 3/21/21.
//

#ifndef NUMCPP_DATA_WRITER_2_H
#define NUMCPP_DATA_WRITER_2_H

#include <iostream>
#include <string>
#include <vector>

void
savetxt_multi(
        const std::string &in_filename,
        const std::string &out_filename,
        const std::string &info,
        bool write_header_and_comment,
        char delimeter,
        bool write_input_data,
        const std::vector<std::vector<double>> &a_data,
        const std::vector<std::vector<double>> &b_data_in,
        const std::vector<std::vector<double>> &b_data_out,
        int precision
);


void
savetxt(
        const string &out_filename,
        const vector<vector<double>> &data,
        const string info="",
        char delimeter=' ',
        int precision=7
);

#endif //NUMCPP_DATA_WRITER_2_H
