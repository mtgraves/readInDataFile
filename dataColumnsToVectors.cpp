#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef vector<double> dVec;

vector<dVec> readRows(ifstream& f) {
    string line;
    vector<dVec> rows;
    while (getline(f, line)) {
        if (line[0]!='#'){ // skip commented lines
            istringstream iss(line);
            rows.push_back(dVec());
            while(iss){
                string sub;
                double subD;
                iss >> sub;
                if (sub != ""){
                    /* convert to double and add to vector */
                    subD = strtod(sub.c_str(),NULL);
                    rows.back().push_back(subD);
                } //endif
            } //endwhile
        } //endif
    } //endwhile
    return rows;
}

int main() {
    
    /* File to open. */
    string testFile="testDatafile.dat";   
    
    /* Read in file and store data columns in vector of vectors. */
    ifstream inFile;
    inFile.open(testFile.c_str());
    vector<dVec> rows = readRows(inFile);
    
    /* Bookkeeping */
    int numRows = rows.size();
    int numCols = rows[0].size(); // for future reference
    
    /* Keep only the columns you want (here we want the first two). */
    vector<double> data1, data2;
    for (int i=0; i<numRows; i++){
        data1.push_back(rows[i][0]);
        data2.push_back(rows[i][1]);
    }

    /* Delete all other data from memory. */
    vector<dVec>().swap(rows);

    /* print first element of each array */    
    cout<<data1[0]<<" "<<data2[0]<<endl;
    
    return 0;
}
