#include <fstream>
#include <iostream>
#include <string>
#include <new>

using namespace std;

void identifySymbols(const string &line, int *ptr)
{
  int idx = 0;
  for(int i = 0, size = line.size(); i < size; i++){
    if(line[i] == '+'){
      ptr[idx]++;
      continue;
    }
    else if(line[i] == '>'){
      idx++;
      continue;
    }
  }
  std::cout << line << std::endl;
}

int main(int argc, char *argv[]){
  std::ifstream file;
  std::string filename = "./../sample/examples/hello.bf";
  file.open(filename, std::ios::in);
  int count = 0, arr_size = 0;
  int *ptr;
  int idx = 0;
  std::string line;
  while(std::getline(file, line)){
    for(int i = 0, size = line.size(); i < size; i++){
      if(line[i] == '>') arr_size++;
    }
    std::cout << line << std::endl;
  }

  ptr = new int[arr_size];
  file.close();
  line.clear();
  file.open(filename);
  while(std::getline(file, line)){
    identifySymbols(line, ptr);
  }

  std::cout << "a" << ptr[0] << std::endl;
  std::cout << "a" << ptr[1] << std::endl;

  return 0;
}
