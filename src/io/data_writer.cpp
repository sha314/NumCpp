//
// Created by shahnoor on 10/27/18.
// Modified by shahnoor on 3/21/21.
//

#include "data_writer.h"
#include <iomanip>
#include <fstream>


using namespace std;

void
savetxt(
        const string &out_filename,
        const vector<vector<double>> &data,
        const string info="",
        char delimeter=' ',
        int precision=7
) {
    ofstream fout(out_filename);

    fout << '#' << info << endl; // info cannot contain a new line character
    fout << "#convolved data" << endl;
    cout << data.size() << ", " << data[0].size() << endl;

    for(size_t i{}; i < data.size(); ++i){

        for(size_t j{}; j < data[0].size(); ++j){
            fout << setprecision(precision) << data[i][j] << delimeter;
//            cout << setprecision(precision) << b_data_out[i][j] << delimeter;
        }
        fout << endl;
    }
    fout.close();
}