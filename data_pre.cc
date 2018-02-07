#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "data_pre.h"

DataSet::DataSet(void)
{
  //data_storage_array=NULL;
}
              
void DataSet::NormalizeData()
{
  double max;
  for (int i =0;i<num_colums_;i++) {
    max = *std::max_element(data_storage_array[i].begin(), data_storage_array[i].end());
    for (int j = 0; j<data_storage_array[i].size(); j++){
      data_storage_array[i][j]=data_storage_array[i][j]/max;
    }
  }
}

void DataSet::LoadData(const char* filename, int num_columns)
{
  //add error if file isnt found
  std::scientific;
  std::fstream data_file (filename, std::fstream::in);
     
  double temp;
  while(data_file) {
     for (int i =0;i<num_columns;i++) {
       if (data_file.eof()){break;}
       data_file >> temp;
       data_storage_array[i].push_back(temp);
     }
     
  }

  //hack
  data_storage_array[0].erase(data_storage_array[0].end()-1);

  data_file.close();
}


  
