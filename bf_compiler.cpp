#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void getSymbols(const string &line, map<int, char> &symbols, int &idx, int &comma)
{
  int count = 0;
  for(int i = 0, size = line.size(); i < size; i++){
    if(line[i] != '+'){
      symbols[i+idx] = line[i];
    }
    if(line[i] == '.') comma++;
    count++;
  }
  idx += count;
  // std::cout << line << std::endl;
}

void calcSymbols(const map<int, char> &symbols, vector<int> &output)
{
  int roop_count = 0, count_idx = 0, roop_idx = 0, past_symbol_idx = 0, output_count = 0;
  vector<int> counts(output.size());
  auto roop_it = symbols.begin();
  for(auto it = symbols.begin(); it != symbols.end(); it++){
    // cout << "first: " << it->first << endl; 
    counts[count_idx] += it->first - past_symbol_idx - 1;
    past_symbol_idx = it->first;
    if(it->second == '>'){
      count_idx++;
      continue;
    }
    else if(it->second == '<'){
      count_idx--;
      continue;
    }
    else if(it->second == '-'){
      counts[count_idx]--;
      // cout << "roop: " << counts[count_idx] << endl;
      continue;
    }
    else if(it->second == '['){  // 2重ループ未対応
      roop_idx = count_idx;
      roop_it  = it;
      continue;
    }
    else if(it->second == ']'){
      if(counts[roop_idx] != 0){
        it = roop_it;
        past_symbol_idx = it->first;
      }
      continue;
    }
    else if(it->second == '.'){
      output[output_count] = counts[count_idx];
      output_count++;
    }
  }
}

int main(int argc, char *argv[]){
  std::ifstream file;
  std::string filename = "./../sample/examples/hello.bf";
  file.open(filename, std::ios::in);
  int *ptr;
  int idx = 1, comma = 0;
  map<int, char> symbols;
  vector<int> output;
  std::string line;
  while(std::getline(file, line)){
    getSymbols(line, symbols, idx, comma);
  }
  output.resize(comma);
  calcSymbols(symbols, output);
  for(int i = 0, size = output.size(); i < size; i++){
    // cout << "output: " << output[i] << endl;
    printf("%c", output[i]);
  }

  return 0;
}
