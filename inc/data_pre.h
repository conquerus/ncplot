#include <vector>
#include <iostream>

const int MAX_LENGTH=25;
  
class DataSet
{
 public:
  int num_colums_;
  std::vector<float> data_storage_array[MAX_LENGTH];

  DataSet(void);
  void LoadData(const char* filename, int num_colums);
  void NormalizeData();


 private:

};
